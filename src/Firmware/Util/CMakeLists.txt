add_library(Util STATIC "")

target_sources(Util
	PUBLIC
		${CMAKE_CURRENT_SOURCE_DIR}/RingBuffer.hpp
	PRIVATE
		RingBuffer.cpp
)