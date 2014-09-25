cmake_minimum_required(VERSION 2.8)
project(QtMapKit)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(Qt5 COMPONENTS Core WebKit WebKitWidgets Widgets Network Gui REQUIRED)

# We need add -DQT_WIDGETS_LIB when using QtWidgets in Qt 5.
add_definitions(${Qt5Widgets_DEFINITIONS} -D_REENTRANT)

# Executables fail to build with Qt 5 in the default configuration
# without -fPIE. We add that here.
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${Qt5Widgets_EXECUTABLE_COMPILE_FLAGS}")

add_subdirectory(demo)

set(QtMapKit_SOURCES
    src/QMCoordinate.cpp
    src/QMCoordinateRegion.cpp
    src/QMCoordinateSpan.cpp
    src/QMMapView.cpp
    src/QMMarker.cpp
)

# Here go all files that need to be processed by moc
set(QtMapKit_MOCS
    include/QMMapView.h
    include/QMMarker.h
)

# Append header that will be processed by moc to sources
# This is needed in order to CMAKE_AUTOMOC find them (seems that it is not smart enought to look
# in other directories)
# One may ask: Why not use qt5_wrap_cpp?? Because all moc cpp generated files will be places in
# include dir
list(APPEND ${QtMapKit_SOURCES} ${QtMapKit_MOCS})

set(CMAKE_AUTOMOC ON)

set(QtMapKit_HEADERS
    include/QMCoordinate.h
    include/QMCoordinateRegion.h
    include/QMCoordinateSpan.h
    include/QtMapKit.h
    include/qtmapkit_global.h
    include/QMMapView.h
    include/QMMarker.h
)

qt5_add_resources(RESOURCES src/qtmapkit_resources.qrc)

add_definitions(-DQTMAPKIT_LIBRARY)
include_directories(${PROJECT_SOURCE_DIR}/include)
add_library(qtmapkit SHARED ${QtMapKit_SOURCES} ${RESOURCES} ${QtMapKit_MOCS})
target_link_libraries(qtmapkit Qt5::Widgets Qt5::WebKit Qt5::Core Qt5::Gui Qt5::WebKitWidgets
    Qt5::Network)

set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)
add_custom_command(TARGET qtmapkit POST_BUILD COMMAND "${CMAKE_COMMAND}" "-E" "make_directory"
    "${PROJECT_BINARY_DIR}/include/")

foreach(header ${QtMapKit_HEADERS})
    set(SOURCE "${PROJECT_SOURCE_DIR}/${header}")
    set(DEST "${PROJECT_BINARY_DIR}/${header}")
    add_custom_command(TARGET qtmapkit POST_BUILD COMMAND "${CMAKE_COMMAND}" "-E"
        "copy_if_different" "${SOURCE}" "${DEST}")
endforeach()
