include(avr-arduino-toolchain)

add_library(Camera STATIC "")

target_sources(Camera
	PUBLIC
		${CMAKE_CURRENT_SOURCE_DIR}/Camera.hpp
	PRIVATE
		Camera.cpp
)
