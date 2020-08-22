# Copyright (c) 2020 Alexei Gaidulean
# All rights reserved.
#
# Use of this source code is governed by a MIT-style license that
# can be found in the LICENSE file.

# Index group.
add_source_group(Source
	"Public/L2NextConverterDAT.h"
	"Private/L2NextConverterDAT.cpp"
)

# Utils.

# Streams.
add_source_group(Source.Utils.Streams
	"Public/Utils/Streams/InputStream.h"
	"Private/Utils/Streams/InputStream.cpp"
	"Public/Utils/Streams/OutputStream.h"
	"Private/Utils/Streams/OutputStream.cpp"
	"Public/Utils/Streams/DuplexStream.h"
	"Private/Utils/Streams/DuplexStream.cpp"
)
