include(FetchContent)

FetchContent_Declare(json URL https://github.com/nlohmann/json/releases/download/v3.11.3/json.tar.xz)
FetchContent_MakeAvailable(json)

add_executable(a.out main.cpp) 

target_link_libraries(a.out PRIVATE nlohmann_json::nlohmann_json)
