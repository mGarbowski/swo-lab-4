add_executable(WhiteBearApp WhiteBearMain.cc)
target_link_libraries(WhiteBearApp WhiteBear)

set_target_properties(WhiteBearApp
PROPERTIES 
    CXX_CLANG_TIDY clang-tidy
)
