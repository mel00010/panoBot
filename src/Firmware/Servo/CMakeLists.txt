include(avr-arduino-toolchain)

add_library(ServoControl STATIC "")

target_sources(ServoControl
	PUBLIC
		${CMAKE_CURRENT_SOURCE_DIR}/PIDObj.hpp
#		${CMAKE_CURRENT_SOURCE_DIR}/Servo.hpp
	PRIVATE
		PIDObj.cpp
)
