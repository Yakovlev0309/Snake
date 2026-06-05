cmake_minimum_required(VERSION 3.20)

project(Snake LANGUAGES CXX)

include(FetchContent)

FetchContent_Declare(
    SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 3.1.0
)

FetchContent_MakeAvailable(SFML)

add_executable(Snake
    src/main.cpp
)

target_link_libraries(Snake PRIVATE
    SFML::Graphics
)

target_compile_features(Snake PRIVATE cxx_std_20)
