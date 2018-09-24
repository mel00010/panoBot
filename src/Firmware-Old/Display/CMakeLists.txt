include(avr-arduino-toolchain)

add_library(Display STATIC "")
target_sources(Display
	PUBLIC
		${CMAKE_CURRENT_SOURCE_DIR}/Display.hpp
		${CMAKE_CURRENT_SOURCE_DIR}/Coordinate.hpp
	PRIVATE
		Display.cpp
)

target_link_libraries(Display
	PUBLIC
		Util
)