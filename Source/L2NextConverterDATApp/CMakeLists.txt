# Copyright (c) 2020 Alexei Gaidulean
# All rights reserved.
#
# Use of this source code is governed by a MIT-style license that
# can be found in the LICENSE file.

# Project metadata.
project(${PROJECT_NAME} VERSION 1.0.0)

# Add sources.
include(App/Sources)

# Add executable target.
add_executable(${PROJECT_NAME} WIN32 ${L2NextConverterDATApp_SOURCES})

# Add resources.
include(App/Resources)

# Set test app properties.
set_test_app_properties(L2NextConverterDAT)

# Link third party dependencies. 
link_external_dependency(yaml ${PROJECT_NAME})

# Add project dependencies.
link_internal_dependency(L2NextConverterDAT)

# Install export.
if (L2NEXT_CPP_INSTALL)
	export_install_configs()
endif()