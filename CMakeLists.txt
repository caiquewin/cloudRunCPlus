cmake_minimum_required(VERSION 3.10)
project(cloudrun-cpp)

set(CMAKE_CXX_STANDARD 17)

include(FetchContent)

# httplib
FetchContent_Declare(
  httplib
  GIT_REPOSITORY https://github.com/yhirose/cpp-httplib.git
  GIT_TAG v0.15.3
)
FetchContent_MakeAvailable(httplib)

# nlohmann/json
FetchContent_Declare(
  json
  GIT_REPOSITORY https://github.com/nlohmann/json.git
  GIT_TAG v3.11.3
)
FetchContent_MakeAvailable(json)

add_executable(server main.cpp)
target_link_libraries(server httplib::httplib nlohmann_json::nlohmann_json)
