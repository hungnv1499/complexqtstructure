cmake_minimum_required(VERSION 3.16)

project(MyComplexQtQuickApp VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# Enable AUTOMOC and AUTOUIC for Qt Quick and C++
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
#set(CMAKE_AUTORCC ON)

find_package(Qt6 6.5.3 REQUIRED COMPONENTS Quick)

add_subdirectory(external/MyLib)

#qt_standard_project_setup(REQUIRES 6.5)

# Add the main executable
# Automatically include all .cpp and .h files in src and include directories
file(GLOB_RECURSE SOURCES
    src/*.cpp
    include/*.h
)
qt_add_executable(appMyComplexQtQuickApp
    ${SOURCES}             # Add all source files found
    resources.qrc          # Resource file (e.g., images/icons)
)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
set_target_properties(appMyComplexQtQuickApp PROPERTIES
#    MACOSX_BUNDLE_GUI_IDENTIFIER com.example.appMyComplexQtQuickApp
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appMyComplexQtQuickApp PRIVATE
    MyLib                  # External library
    Qt6::Quick             # Qt Quick module
    Qt6::Core              # Qt Core module
)

# Add include directories
target_include_directories(appMyComplexQtQuickApp PRIVATE ${CMAKE_SOURCE_DIR}/include)
# Add QML module
# Automatically include all .qml files in the qml directory
file(GLOB_RECURSE QML_DIR
    qml/*.qml
    qml/components/*.qml  # Include subdirectories if needed
)
qt_add_qml_module(appMyComplexQtQuickApp
    URI MyComplexQtQuickApp
    VERSION 1.0
    #QML_FILES ${QML_FILES} # Add all QML files found
    QML_FILES
        ${QML_DIR}
)
include(GNUInstallDirs)
install(TARGETS appMyComplexQtQuickApp
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
