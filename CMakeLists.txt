cmake_minimum_required(VERSION 3.10)

project(2025_LW_OOP_4)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Install Google Test
include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG v1.17.0
  TLS_VERIFY false
)
FetchContent_MakeAvailable(googletest)

set(INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
include_directories(${INCLUDE_DIR})

add_library(Array_lib   INTERFACE)
add_library(Point_lib   INTERFACE)
add_library(Figure_lib  INTERFACE)
add_library(Square_lib  INTERFACE)
add_library(Triangle_lib INTERFACE)
add_library(Octagon_lib INTERFACE)

# Build
target_include_directories(Array_lib   INTERFACE ${INCLUDE_DIR})
target_include_directories(Point_lib   INTERFACE ${INCLUDE_DIR})
target_include_directories(Figure_lib  INTERFACE ${INCLUDE_DIR})
target_include_directories(Square_lib  INTERFACE ${INCLUDE_DIR})
target_include_directories(Triangle_lib INTERFACE ${INCLUDE_DIR})
target_include_directories(Octagon_lib INTERFACE ${INCLUDE_DIR})
add_executable(Figures_exe main.cpp)
target_link_libraries(Figures_exe PRIVATE Figure_lib Point_lib Square_lib Triangle_lib Octagon_lib Array_lib)

# Build Tests
enable_testing()
add_executable(Figures_tests test/tests.cpp)
target_link_libraries(Figures_tests Figure_lib Point_lib Square_lib Triangle_lib Octagon_lib Array_lib gtest_main)
