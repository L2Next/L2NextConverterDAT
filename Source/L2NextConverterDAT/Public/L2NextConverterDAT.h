#ifndef H_L2NEXT_CONVERTER_DAT
#define H_L2NEXT_CONVERTER_DAT

#include <memory>
#include <string>
#include <algorithm>
#include <iterator>
#include <sstream>
#include <ostream>
#include "Utils/Streams/InputStream.h"
#include "Utils/Streams/OutputStream.h"
#include "Utils/Streams/DuplexStream.h"

using namespace L2NextConverterDATStreams;

class L2NextConverterDAT
{
public:
	std::string Deserialize(const std::stringstream& serialized);
};

#endif // H_L2NEXT_CONVERTER_DAT
