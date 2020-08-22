#ifndef H_L2NEXT_CONVERTER_DAT_APP
#define H_L2NEXT_CONVERTER_DAT_APP

#include "pch.h"
#include <string>
#include <sstream>
#include <functional>
#include <memory>
#include <typeinfo>

#include "L2NextConverterDAT.h"
#include "Utils/FileHelper.h"
#include "Utils/Logging.h"
#include "ConfigReader/ConfigReader.h"

class L2NextConverterDATApp
{
public:
	static unique_ptr<L2NextConverterDATApp> getRef();

	void awaitClosing();

	void ReadCustomConfigPath();
	std::string GetConfigPath();

	const std::string defaultYamlConfig = "config\\config.yaml";
	std::string customYamlConfig = "";
	std::string ConfigPath = "";
};

#endif //H_L2NEXT_CONVERTER_DAT_APP
