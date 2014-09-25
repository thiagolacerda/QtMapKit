set(Demo_SOURCES
    main.cpp
    Widget.cpp
)

qt5_wrap_cpp(Demo_MOCS Widget.h)

include_directories(${PROJECT_BINARY_DIR}/include)
link_directories(${PROJECT_BINARY_DIR}/lib)

add_executable(demo ${Demo_SOURCES} ${Demo_MOCS})
add_dependencies(demo qtmapkit)
target_link_libraries(demo -lqtmapkit Qt5::Widgets Qt5::WebKit Qt5::Core Qt5::Gui Qt5::WebKitWidgets
    Qt5::Network)
