cmake_minimum_required(VERSION 3.0.0)
project(rpiclientc VERSION 0.1.0)

include(CTest)
enable_testing()

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_executable(rpiclientc src/main.c)
#add_executable(rpiclientc src/testmosq.c)
#add_executable(rpiclientc src/testmosq.c)

find_package(mosquitto REQUIRED)
find_package(cJSON CONFIG REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE cjson mosquitto)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack) 
