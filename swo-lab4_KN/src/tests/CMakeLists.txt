Include(FetchContent)
    FetchContent_Declare(
      Catch2
      GIT_REPOSITORY https://github.com/catchorg/Catch2.git
      GIT_TAG        v3.3.0)
    # cmake > 3.15 FetchContent_MakeAvailable(Catch2)
    FetchContent_GetProperties(Catch2)
    if(NOT catch2_POPULATED)
        FetchContent_Populate(Catch2)
        add_subdirectory("${catch2_SOURCE_DIR}" "${catch2_BINARY_DIR}")
    endif()

add_executable(WhiteBearUnitTests
        ItemUnitTests.cpp
        LegendaryUnitTests.cpp)
target_link_libraries(WhiteBearUnitTests WhiteBear Catch2::Catch2WithMain)
add_test(NAME WhiteBearUnitTests COMMAND WhiteBearUnitTests)

set_target_properties(WhiteBearUnitTests
    PROPERTIES 
        CXX_CLANG_TIDY clang-tidy
)
