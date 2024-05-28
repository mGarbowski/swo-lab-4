set(TEST_NAME WhiteBearCatch2ApprovalTests)
add_executable(${TEST_NAME})
target_sources(${TEST_NAME} PRIVATE WhiteBearCatch2ApprovalTests.cc main.cc)
target_link_libraries(${TEST_NAME} approval_tests_lib WhiteBear Catch2::Catch2WithMain)
set_property(TARGET ${TEST_NAME} PROPERTY CXX_STANDARD 17)
add_test(NAME ${TEST_NAME} COMMAND ${TEST_NAME})

