include(avr-arduino-toolchain)

add_executable_avr(panoBot "panoBot.cpp")

target_link_libraries(panoBot
	PUBLIC
		Camera
		Display
		Servo
		Setup
		Util
		m # Math library
		c # C standard library
)

add_subdirectory(Camera)
add_subdirectory(Display)
add_subdirectory(Servo)
add_subdirectory(Setup)
add_subdirectory(Util)
