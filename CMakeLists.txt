cmake_minimum_required(VERSION 3.14)
project(cloudrun_cpp)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

include(FetchContent)

# httplib
FetchContent_Declare(
  httplib
  GIT_REPOSITORY https://github.com/yhirose/cpp-httplib.git
  GIT_TAG v0.15.3
)
FetchContent_GetProperties(httplib)
if(NOT httplib_POPULATED)
  FetchContent_Populate(httplib)
  add_subdirectory(${httplib_SOURCE_DIR} ${httplib_BINARY_DIR} EXCLUDE_FROM_ALL)
endif()

# nlohmann/json
FetchContent_Declare(
  nlohmann_json
  GIT_REPOSITORY https://github.com/nlohmann/json.git
  GIT_TAG v3.11.3
)
FetchContent_GetProperties(nlohmann_json)
if(NOT nlohmann_json_POPULATED)
  FetchContent_Populate(nlohmann_json)
  add_subdirectory(${nlohmann_json_SOURCE_DIR} ${nlohmann_json_BINARY_DIR} EXCLUDE_FROM_ALL)
endif()

add_executable(server main.cpp)

target_include_directories(server PRIVATE
  ${httplib_SOURCE_DIR}
  ${nlohmann_json_SOURCE_DIR}/include
)

target_link_libraries(server PRIVATE httplib::httplib nlohmann_json::nlohmann_json)
