include(avr-arduino-toolchain)
include(GetNanoPB)
include(${CMAKE_BINARY_DIR}/nanopb-src/extra/FindNanopb.cmake)

include_directories(${CMAKE_BINARY_DIR}/nanopb-src)
nanopb_generate_cpp(PROTO_SRCS PROTO_HDRS simple.proto)

include_directories(${CMAKE_CURRENT_BINARY_DIR})

#add_library(Connection STATIC "")
#
#target_sources(Connection
#	PUBLIC
#		
#	PRIVATE
#	
#)
