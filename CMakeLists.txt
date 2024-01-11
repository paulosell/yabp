cmake_minimum_required(VERSION 3.15.0)
project(base64url VERSION 0.0.1)

add_compile_options(-Werror -Wall)
include_directories(include)

add_subdirectory(src)
message(${BUILD_EXAMPLE})
if(BUILD_EXAMPLE)
add_subdirectory(example)
endif()

if(BUILD_TESTING)
  enable_testing()
  add_subdirectory(tests)
endif()

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

