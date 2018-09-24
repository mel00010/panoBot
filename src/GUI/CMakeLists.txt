find_package(Protobuf REQUIRED)
find_package(PkgConfig REQUIRED)
pkg_check_modules(GTKMM gtkmm-3.0)
include(GNUInstallDirs)
add_definitions(-DGETTEXT_PACKAGE="${PROJECT_NAME}")
add_definitions(-DPROGRAMNAME_LOCALEDIR="${DATADIR}/locale")

include_directories(
	${GTKMM_INCLUDE_DIRS}
	${PROTOBUF_INCLUDE_DIRS}
)

add_executable(panoBot-gui "")
target_sources(panoBot-gui 
	PUBLIC
		${CMAKE_CURRENT_SOURCE_DIR}/MainWindow.hpp
	PRIVATE
		main.cpp
		MainWindow.cpp
)
target_link_libraries(panoBot-gui
	PUBLIC
		${GTKMM_LIBRARIES}
)