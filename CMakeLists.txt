cmake_minimum_required(VERSION 3.1)
project(iscore_addon_tutorial LANGUAGES CXX)

# General initialization
iscore_common_setup()

# Source files
set(HDRS
    iscore_addon_tutorial.hpp
)
set(SRCS
    iscore_addon_tutorial.cpp
)

# Creation of the library
add_library(${PROJECT_NAME} ${SRCS} ${HDRS} ${QRCS})

# Code generation
iscore_generate_command_list_file(${PROJECT_NAME} "${HDRS}")

# Link
target_link_libraries(${PROJECT_NAME} PUBLIC iscore_plugin_engine)

# Target-specific options
setup_iscore_plugin(${PROJECT_NAME})
