# Минимальная версия CMake: 3.8
cmake_minimum_required(VERSION 3.8 FATAL_ERROR)

# Имя проекта: CourseProject
project(CourseProject)

add_executable(start main.cpp Game.cpp Menu.cpp obstacles.cpp PickUps.cpp Player.cpp)

set(SFML_STATIC_LIBRARIES TRUE)

find_package(Freetype)
find_package(JPEG)
find_package(SFML 2 COMPONENTS window graphics system)

target_compile_features(start PUBLIC cxx_std_17)
target_compile_definitions(start PRIVATE SFML_STATIC)

target_link_libraries(
    start 
    ${SFML_LIBRARIES} 
    ${SFML_DEPENDENCIES} 
    )

include_directories()