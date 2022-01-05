cmake_minimum_required(VERSION 3.0.0)
project(rpiclientc VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(rpiclientc src/test.c)

find_package(cJSON CONFIG REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE cjson)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
