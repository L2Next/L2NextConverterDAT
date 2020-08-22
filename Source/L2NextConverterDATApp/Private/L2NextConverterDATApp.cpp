#include "L2NextConverterDATApp.h"

using namespace L2NextConverterDATStreams;
using namespace Utils;

unique_ptr<L2NextConverterDATApp> L2NextConverterDATApp::getRef()
{
	return make_unique<L2NextConverterDATApp>();
}

void L2NextConverterDATApp::ReadCustomConfigPath()
{
	getline(cin, customYamlConfig);
}

std::string L2NextConverterDATApp::GetConfigPath()
{
	return customYamlConfig.empty()
		? FileHelper::GetCurrentWorkingDirectory() + "\\" + defaultYamlConfig
		: FileHelper::GetCurrentWorkingDirectory() + "\\" + customYamlConfig;
}

void L2NextConverterDATApp::awaitClosing()
{
	cout << "Press any key to exit program.";
	std::string await = "";
	getline(cin, await);
}

int main()
{
	auto app = L2NextConverterDATApp::getRef();

	Logging::PrintIntro();
	app->ReadCustomConfigPath();

	Logging::PrintConfigLoadStart();
	auto config = ConfigReader::TryLoadConfig(app->GetConfigPath());

	if (config && !config->DeserializeToYaml.empty())
	{
		for (ConfigPaths cp : config->DeserializeToYaml)
		{
			Logging::PrintSeparator();

			std::ifstream input(cp.src, std::ios::binary);
			std::ofstream output(cp.out, std::ios::binary);

			auto converter = std::make_unique<L2NextConverterDAT>();

			std::stringstream serialized;
			serialized << input.rdbuf();

			output << converter->Deserialize(serialized);

			input.close();
			output.close();
		}
	}

	app->awaitClosing();
	config.reset();
	app.reset();

	return 1;
}