include(GoogleTest)

add_executable(unit_tests test_main.cpp)

target_include_directories(unit_tests PRIVATE
    ${CMAKE_SOURCE_DIR}/src
)

target_link_libraries(unit_tests PRIVATE
    GTest::gtest_main
    nlohmann_json::nlohmann_json
)

gtest_discover_tests(unit_tests)