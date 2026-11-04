cmake_minimum_required(VERSION 3.20)

project(SFSModpackManager LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 COMPONENTS Core Gui Widgets REQUIRED)
find_package(nlohmann_json REQUIRED)

add_executable(${PROJECT_NAME} main.cpp
    styling/styling.hpp
    styling/styling.cpp)

add_custom_target(copy_styles
    COMMAND ${CMAKE_COMMAND} -E copy_directory "${CMAKE_CURRENT_SOURCE_DIR}/styles" "${CMAKE_CURRENT_BINARY_DIR}/styles"
    COMMENT "Copying styles"
)

add_dependencies(${PROJECT_NAME} copy_styles)

target_link_libraries(${PROJECT_NAME} PRIVATE Qt6::Core Qt6::Gui Qt6::Widgets nlohmann_json::nlohmann_json)