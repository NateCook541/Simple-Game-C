cmake_minimum_required(VERSION 3.14)
project(gameV3)
set(CMAKE_CXX_STANDARD 17)

# FetchContent added in CMake 3.11, downloads during the configure step
include(FetchContent)

# Fetch raylib
FetchContent_Declare(
  raylib
  GIT_REPOSITORY https://github.com/raysan5/raylib.git
  GIT_TAG 4.0.0
)

# Make the raylib source available
FetchContent_MakeAvailable(raylib)

# Define the executable
add_executable(gameV3 src/main.cpp src/config.cpp src/screens.cpp src/gameplay.cpp)

# Link raylib
target_link_libraries(gameV3 raylib)
