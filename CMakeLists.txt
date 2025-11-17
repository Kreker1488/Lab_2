cmake_minimum_required(VERSION 3.15)

set(PROJECT_NAME labwork_4)
project("${PROJECT_NAME}")

set(CMAKE_CXX_STANDARD 20)

add_executable("${PROJECT_NAME}" crs/main/main.cpp crs/generate/generate.cpp crs/authorization/authorization.cpp)



