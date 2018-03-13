include(avr-arduino-toolchain)

add_executable_avr(panoBot "panoBot.cpp")

target_link_libraries(panoBot
	PUBLIC
		Setup
		Camera
		Display
#		Connection
#		Util
		m # Math library
		c # C standard library
)

include_directories(${CMAKE_BINARY_DIR}/avr-uart-src)

add_subdirectory(Camera)
add_subdirectory(Display)
add_subdirectory(Servo)
add_subdirectory(Setup)
add_subdirectory(Util)
