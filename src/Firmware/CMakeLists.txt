include(avr-arduino-toolchain)

add_executable_avr(panoBot "panoBot.cpp")

target_link_libraries(panoBot
	PUBLIC
		Setup
		m # Math library
		c # C standard library
)
add_subdirectory(Connection)
add_subdirectory(ServoControl)
add_subdirectory(Setup)
