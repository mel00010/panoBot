include(DoxygenTargets)

set(DOXYGEN_SOURCE_INPUTS 
	"${PROJECT_SOURCE_DIR}/assignment1 \
	${PROJECT_SOURCE_DIR}/assignment2 \
	${PROJECT_SOURCE_DIR}/assignment3 \
	${PROJECT_SOURCE_DIR}/assignment4 \
	${PROJECT_SOURCE_DIR}/README.md")
configure_file(Doxyfile.in Doxyfile @ONLY)
add_doxygen(${CMAKE_CURRENT_BINARY_DIR}/Doxyfile)

install(DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/docs-generated/man/man3 DESTINATION /usr/local/man)