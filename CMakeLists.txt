# Минимальная версия CMake: 3.8
cmake_minimum_required(VERSION 3.8 FATAL_ERROR)

# Имя проекта: CourseProject
project(CourseProject)

# Подкаталог 00 содержит ещё один CMakeLists.txt
#add_subdirectory(00)

add_executable(start main.cpp)

set(SFML_STATIC_LIBRARIES TRUE)

find_package(Freetype)
find_package(JPEG)
find_package(SFML 2 COMPONENTS window graphics system)

target_compile_features(start PUBLIC cxx_std_17)
target_compile_definitions(start PRIVATE SFML_STATIC)

target_link_libraries(start ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})