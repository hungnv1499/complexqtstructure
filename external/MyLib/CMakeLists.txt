# External Library CMakeLists.txt
project(MyLib LANGUAGES CXX)

# Find the QtCore module for QString and other core features
find_package(Qt6 REQUIRED COMPONENTS Core)

add_library(MyLib STATIC
    mylib.cpp
    mylib.h
)
# Link against QtCore
target_link_libraries(MyLib PUBLIC Qt6::Core)

# Specify that MyLib is a static library with public headers
target_include_directories(MyLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

