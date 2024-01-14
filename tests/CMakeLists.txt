find_package(GTest REQUIRED)
add_executable(base64url_test base64url_test.cpp)
target_link_libraries(base64url_test base64url gtest::gtest)

