cmake_minimum_required(VERSION 3.13.0)
project(SWO_WhiteBear VERSION 1.0.0 LANGUAGES CXX)

set (CMAKE_CXX_STANDARD 17)
set (CMAKE_CXX_STANDARD_REQUIRED ON)

# Include Catch2
include(FetchContent)
FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v3.3.0)
FetchContent_GetProperties(Catch2)
if(NOT catch2_POPULATED)
    FetchContent_Populate(Catch2)
    add_subdirectory("${catch2_SOURCE_DIR}" "${catch2_BINARY_DIR}")
endif()

add_compile_options(-Wall -Wextra -pedantic -Werror)

include(CTest)

add_subdirectory(src)
add_subdirectory(ext)
add_subdirectory(app)
add_subdirectory(tests)
