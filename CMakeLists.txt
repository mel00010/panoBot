#=====================================================================================
cmake_minimum_required(VERSION 3.0)

# the toolchain file
set(CMAKE_TOOLCHAIN_FILE cmake/avr-arduino-toolchain.cmake)

# if you want to compile Arduino sketches, set this to the Arduino SDK dir (1.6.5)
set(ARDUINO_SDK_PATH "/usr/share/arduino" CACHE STRING "Arduino SDK Path")

# project name and code types we use
project (panoBot C CXX ASM)

# necessary settings for the chip we use
set(MCU         atmega328p)
set(F_CPU       16000000)
set(BAUD        115200)

# set the programmer and the device to use (arduino, usbasp, ...)
set(PROGRAMMER  arduino)
set(SERIAL_DEV  /dev/cu.SLAB_USBtoUART)
