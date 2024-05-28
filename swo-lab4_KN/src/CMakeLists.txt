add_library(WhiteBear WhiteBear.cc WhiteBear.h)

target_include_directories(WhiteBear PUBLIC .)

add_subdirectory(tests)

set_target_properties(WhiteBear
PROPERTIES 
    CXX_CLANG_TIDY clang-tidy
)
