add_library(
        WhiteBear
        WhiteBear.cc WhiteBear.h
        items/Item.cc items/Item.h
        items/Legendary.cc items/Legendary.h
        items/Ticket.cc items/Ticket.h
        items/CheeseBrie.cc items/CheeseBrie.h
)

target_include_directories(WhiteBear PUBLIC .)

add_subdirectory(tests)

set_target_properties(WhiteBear
PROPERTIES 
    CXX_CLANG_TIDY clang-tidy
)
