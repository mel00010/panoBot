include(avr-arduino-toolchain)

add_library(Setup STATIC "")
target_sources(Setup
	PUBLIC
		${CMAKE_CURRENT_SOURCE_DIR}/Setup.hpp
		${CMAKE_CURRENT_SOURCE_DIR}/SetupPins.hpp
		${CMAKE_CURRENT_SOURCE_DIR}/SetupSerial.hpp
	PRIVATE
		Setup.cpp
		SetupPins.cpp
		SetupSerial.cpp
)
