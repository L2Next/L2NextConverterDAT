#include "Utils/Logging.h"

void Utils::Logging::PrintLogo()
{
	std::printf(
		" _    ___ _  _         _    ___                     _           ___   _ _____ \n"
		"| |  |_  ) \\| |_____ _| |_ / __|___ _ ___ _____ _ _| |_ ___ _ _|   \\ /_\\_   _|\n"
		"| |__ / /| .` / -_) \\ /  _| (__/ _ \\ ' \\ V / -_) '_|  _/ -_) '_| |) / _ \\| |  \n"
		"|____/___|_|\\_\\___/_\\_\\ __|\\___\\___/_||_\\_/\\___|_|  \\__\\___|_| |___/_/ \\_\\_|  \n"
	);
}

void Utils::Logging::PrintLog(std::string msg)
{
	std::printf("Log: %s \n", msg.c_str());
}

void Utils::Logging::PrintError(std::string msg, std::string reason)
{
	std::printf("Error: %s \n", msg.c_str());

	if (!reason.empty()) {
		std::printf("Reason: %s \n", reason.c_str());
	}
}

void Utils::Logging::PrintIntro()
{
	Utils::Logging::PrintLogo();

	std::printf("\n");

	std::printf(
		"# By default config.yaml located in config/config.yaml is used for convert tasks.\n"
		"# If you want to specify a custom yaml config, type a `filename.yaml`, that is located relative to app directory.\n"
		"# Enter custom yaml config path, to skip just press ENTER:\n"
	);
}

void Utils::Logging::PrintConfigLoadStart()
{
	Utils::Logging::PrintLog("Loading yaml config file.");
}

void Utils::Logging::PrintConversionStart(std::string path)
{
	Utils::Logging::PrintLog("File " + FileHelper::GetFilenameFromPath(path) + " conversion started.");
}

void Utils::Logging::PrintConversionSuccess()
{
	Utils::Logging::PrintLog("File successfully converted.");
}

void Utils::Logging::PrintFileError()
{
	Utils::Logging::PrintError("File not found or can't be read.");
}

void Utils::Logging::PrintSeparator()
{
	std::printf("-------------------------------------------------------------\n");
}

void Utils::Logging::PrintProgress(std::string heading, unsigned int current, unsigned int total)
{
	double percentage = (double)current / total;
	int val = (int)(percentage * 100);
	int lpad = (int)(percentage * PBWIDTH);
	int rpad = PBWIDTH - lpad;

	std::printf(
		"\rLog: %s - %3d%% [%.*s%*s].",
		heading.c_str(), val, lpad, PBSTR, rpad, ""
	);
	fflush(stdout);

	if (val == 100) {
		std::printf("\n");
	}
}