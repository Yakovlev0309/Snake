cmake_minimum_required(VERSION 3.20)

project(Snake LANGUAGES CXX)

include(FetchContent)

FetchContent_Declare(
    SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 3.1.0
)

FetchContent_MakeAvailable(SFML)

set(SOURCES
    src/main.cpp
    src/Game.cpp

    src/Render/Renderer.cpp
)

add_executable(Snake ${SOURCES})

target_link_libraries(Snake PRIVATE
    SFML::Graphics
)

target_include_directories(Snake PRIVATE include)

target_compile_features(Snake PRIVATE cxx_std_20)
