cmake_minimum_required(VERSION 3.16)
project(MyProject LANGUAGES CXX)

# Require modern C++
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add the library
add_subdirectory(AllegroCPP)

# Create main example executable
add_executable(hello_world examples/hello_world.cpp)

# Link to your library
target_link_libraries(hello_world PRIVATE AllegroCPP)

# Include your library's headers (for IDEs and builds)
target_include_directories(hello_world PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/AllegroCPP/include
)
