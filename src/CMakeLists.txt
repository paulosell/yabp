file(GLOB_RECURSE HEADER_LIST "${PROJECT_SOURCE_DIR}/include/*.h")
file(GLOB_RECURSE SRC_LIST "*.cpp")
message(${CMAKE_INSTALL_PREFIX})
add_library(base64url ${HEADER_LIST} ${SRC_LIST})

target_compile_features(base64url PUBLIC cxx_std_11)

install(TARGETS base64url DESTINATION ${CMAKE_INSTALL_PREFIX})
install(FILES ${HEADER_LIST} DESTINATION ${CMAKE_INSTALL_PREFIX}/include )

