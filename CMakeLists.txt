#=====================================================================================
cmake_minimum_required(VERSION 3.0)

project (panoBot C CXX ASM)

include(GNUInstallDirs)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

set( CMAKE_CXX_FLAGS_COVERAGE "${CMAKE_CXX_FLAGS_DEBUG}" CACHE STRING
    "Flags used by the C++ compiler during coverage builds."
    FORCE )
set( CMAKE_C_FLAGS_COVERAGE "${CMAKE_C_FLAGS_DEBUG}" CACHE STRING
    "Flags used by the C compiler during coverage builds."
    FORCE )
set( CMAKE_EXE_LINKER_FLAGS_COVERAGE
    "${CMAKE_EXE_LINKER_FLAGS_COVERAGE}" CACHE STRING
    "Flags used for linking binaries during coverage builds."
    FORCE )
set( CMAKE_SHARED_LINKER_FLAGS_COVERAGE
    "${CMAKE_SHARED_LINKER_FLAGS_COVERAGE}" CACHE STRING
    "Flags used by the shared libraries linker during coverage builds."
    FORCE )
mark_as_advanced(
    CMAKE_CXX_FLAGS_COVERAGE
    CMAKE_C_FLAGS_COVERAGE
    CMAKE_EXE_LINKER_FLAGS_COVERAGE
    CMAKE_SHARED_LINKER_FLAGS_COVERAGE )
# Update the documentation string of CMAKE_BUILD_TYPE for GUIs
set( CMAKE_BUILD_TYPE "${CMAKE_BUILD_TYPE}" CACHE STRING
    "Choose the type of build, options are: None Debug Release RelWithDebInfo MinSizeRel Coverage."
    FORCE )

# necessary settings for the chip we use
set(MCU         atmega328p)
set(F_CPU       16000000)
set(BAUD        19200)

# set the programmer and the device to use (arduino, usbasp, ...)
set(PROGRAMMER  stk500v1)
set(SERIAL_DEV  /dev/ttyACM0)

# Fetch and add googletest to the build
include(GetGoogleTest)

# The version number.
set(panoBot_VERSION_MAJOR 0)
set(panoBot_VERSION_MINOR 1)
set(CMAKE_INCLUDE_CURRENT_DIR ON)


#Subdirectories

add_subdirectory(src)
add_subdirectory(test)


add_subdirectory(docs)

# uninstall target
configure_file(
    "${CMAKE_SOURCE_DIR}/cmake/Uninstall.cmake.in"
    "${CMAKE_CURRENT_BINARY_DIR}/Uninstall.cmake"
    IMMEDIATE @ONLY)

add_custom_target(uninstall
    COMMAND ${CMAKE_COMMAND} -P ${CMAKE_CURRENT_BINARY_DIR}/Uninstall.cmake)



