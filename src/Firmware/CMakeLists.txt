include(avr-arduino-toolchain)

add_executable_avr(panoBot "panoBot.cpp")
target_link_libraries(panoBot
	PUBLIC
		Arduino-Core
)
add_subdirectory(Arduino-Core)
add_subdirectory(Connection)
add_subdirectory(ServoControl)
