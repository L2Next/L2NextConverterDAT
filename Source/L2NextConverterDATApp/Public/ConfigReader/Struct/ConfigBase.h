#ifndef H_CONFIG_BASE
#define H_CONFIG_BASE

#include <string>
#include <vector>
#include "ConfigPaths.h"

struct ConfigBase
{
public:
	std::vector<ConfigPaths> DeserializeToYaml;
	std::vector<ConfigPaths> DeserializeToJson;
	std::vector<ConfigPaths> Serialize;
};

#endif //H_CONFIG_BASE
