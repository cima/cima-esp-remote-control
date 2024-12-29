cmake_minimum_required(VERSION 3.20)

set(AZURE_SDK_C_PATH $ENV{AZURE_SDK_C_PATH})

set(CMAKE_SYSTEM_NAME Generic)

# ESP32 imports
# ------------- 
include($ENV{IDF_PATH}/tools/cmake/project.cmake)
list(APPEND EXTRA_COMPONENT_DIRS "../cima-esp32-components/components")

enable_language(CXX)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)

set(CMAKE_C_FLAGS -mlongcalls ${CMAKE_C_FLAGS})
set(CMAKE_CXX_FLAGS -mlongcalls ${CMAKE_CXX_FLAGS})

cmake_policy(SET CMP0074 NEW)
set(Boost_INCLUDE_DIR ${BOOST_ROOT})
set(Boost_LIBRARY_DIR ${BOOST_ROOT}/libs)
find_package(Boost 1.85.0 REQUIRED)

# Adafruit sensor
# ---------------
# TODO components to be referenced using the new component registry system https://components.espressif.com/

# Main code
# ---------

project(CIMA-ESP-REMOTE-CONTROL)
