include(avr-arduino-toolchain)

add_library(Servo STATIC "")

target_sources(Servo
	PUBLIC
		${CMAKE_CURRENT_SOURCE_DIR}/PIDObj.hpp
		${CMAKE_CURRENT_SOURCE_DIR}/Servo.hpp
	PRIVATE
		PIDObj.cpp
		Servo.cpp
)
