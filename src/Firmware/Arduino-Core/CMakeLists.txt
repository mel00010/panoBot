include(avr-arduino-toolchain)

add_library(Arduino-Core STATIC "")
target_sources(Arduino-Core
	PUBLIC
		${CMAKE_CURRENT_SOURCE_DIR}/avr-libc/sectionname.h
		${CMAKE_CURRENT_SOURCE_DIR}/avr-libc/stdlib_private.h
		${CMAKE_CURRENT_SOURCE_DIR}/Arduino.h
		${CMAKE_CURRENT_SOURCE_DIR}/binary.h
		${CMAKE_CURRENT_SOURCE_DIR}/Client.h
		${CMAKE_CURRENT_SOURCE_DIR}/HardwareSerial.h
		${CMAKE_CURRENT_SOURCE_DIR}/IPAddress.h
		${CMAKE_CURRENT_SOURCE_DIR}/new.h
		${CMAKE_CURRENT_SOURCE_DIR}/pins_arduino.h
		${CMAKE_CURRENT_SOURCE_DIR}/Platform.h
		${CMAKE_CURRENT_SOURCE_DIR}/Print.h
		${CMAKE_CURRENT_SOURCE_DIR}/Printable.h
		${CMAKE_CURRENT_SOURCE_DIR}/Server.h
		${CMAKE_CURRENT_SOURCE_DIR}/Stream.h
		${CMAKE_CURRENT_SOURCE_DIR}/Udp.h
		${CMAKE_CURRENT_SOURCE_DIR}/USBAPI.h
		${CMAKE_CURRENT_SOURCE_DIR}/USBCore.h
		${CMAKE_CURRENT_SOURCE_DIR}/USBDesc.h
		${CMAKE_CURRENT_SOURCE_DIR}/WCharacter.h
		${CMAKE_CURRENT_SOURCE_DIR}/wiring_private.h
		${CMAKE_CURRENT_SOURCE_DIR}/WString.h
	PRIVATE
		CDC.cpp
		HardwareSerial.cpp
		HID.cpp
		IPAddress.cpp
		new.cpp
		Print.cpp
		Stream.cpp
		Tone.cpp
		USBCore.cpp
		wiring_analog.c
		wiring_digital.c
		wiring_pulse.c
		wiring_shift.c
		wiring.c
		WMath.cpp
		WString.cpp
)
target_include_directories(Arduino-Core PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
		
		
		