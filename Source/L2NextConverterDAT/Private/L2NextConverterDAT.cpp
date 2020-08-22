#include "L2NextConverterDAT.h"

std::string L2NextConverterDAT::Deserialize(const std::stringstream& serialized)
{
	InputStream input(serialized);
	OutputStream output;

	input >> output;

	return output.GetResult();
}