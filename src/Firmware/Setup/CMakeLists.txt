include(avr-arduino-toolchain)

add_library(Setup STATIC "")
target_sources(Setup
	PUBLIC
		${CMAKE_CURRENT_SOURCE_DIR}/Setup.hpp
	PRIVATE
		Setup.cpp
)

target_link_libraries(Setup
	PUBLIC
)