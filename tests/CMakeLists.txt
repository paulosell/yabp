find_package(GTest REQUIRED)
add_definitions(-DBUILD_TEST=1)
add_executable(base64url_test base64url_test.cpp)
target_link_libraries(base64url_test base64url gtest::gtest)

