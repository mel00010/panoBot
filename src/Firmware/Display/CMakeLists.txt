include(avr-arduino-toolchain)

add_library(Display STATIC "")
target_sources(Display
	PUBLIC
		${CMAKE_CURRENT_SOURCE_DIR}/screen.hpp
	PRIVATE
		Setup.cpp
)

target_link_libraries(Setup
	PUBLIC
)