#include "ConfigReader/ConfigReader.h"

using namespace YAML;
using namespace Utils;

unique_ptr<ConfigBase> ConfigReader::TryLoadConfig(const string& path)
{
	try
	{
		Node rootNode = LoadFile(path);

		unique_ptr<ConfigBase> config = make_unique<ConfigBase>();

		if (!rootNode["deserializeToYaml"] || !rootNode["deserializeToJson"] || !rootNode["serialize"])
		{
			Logging::PrintError("Deserialize or serialize fields are missing in yaml config file.");
			return nullptr;
		}

		try 
		{
			config->DeserializeToYaml = rootNode["deserializeToYaml"].as<vector<ConfigPaths>>();
		}
		catch (exception e)
		{
			// ...
		}

		try
		{
			config->DeserializeToJson = rootNode["deserializeToJson"].as<vector<ConfigPaths>>();
		}
		catch (exception e)
		{
			// ...
		}

		try
		{
			config->Serialize = rootNode["serialize"].as<vector<ConfigPaths>>();
		}
		catch (exception e)
		{
			// ...
		}

		Logging::PrintLog("Configuration file successfully loaded.");

		return config;
	}
	catch (const BadFile e)
	{
		Logging::PrintError("Cannot load yaml config file.", e.msg);

		return nullptr;
	}
	catch (const ParserException e)
	{
		Logging::PrintError("Cannot load yaml config file due to parsing error.", e.msg);
		
		return nullptr;
	}
}
