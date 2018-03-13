add_library(Util STATIC "")

target_sources(Util
	PUBLIC
		${CMAKE_CURRENT_SOURCE_DIR}/delay.hpp
		${CMAKE_CURRENT_SOURCE_DIR}/delete.hpp
		${CMAKE_CURRENT_SOURCE_DIR}/new.hpp
		${CMAKE_CURRENT_SOURCE_DIR}/Pair.hpp
		${CMAKE_CURRENT_SOURCE_DIR}/RingBuffer.hpp
		
	PRIVATE
		delay.cpp
		delete.cpp
		new.cpp
		RingBuffer.cpp
)