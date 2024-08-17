cmake_minimum_required(VERSION 3.5)
project(graphics)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_EXPORT_COMPILE_COMMANDS true)

find_package(GLUT REQUIRED)
if (APPLE)
    find_package(OpenGL REQUIRED)
endif()
include_directories(${GLUT_INCLUDE_DIRS} ${OPENGL_INCLUDE_DIR})

add_executable(${CMAKE_PROJECT_NAME} ${GLAD_SRC} src/main.cc)

if (LINUX)
    target_link_libraries(${CMAKE_PROJECT_NAME} GL glut)
elseif (WIN32)
    target_link_libraries(${CMAKE_PROJECT_NAME} glut kernel32 opengl32)
elseif (APPLE)
    target_link_libraries(${CMAKE_PROJECT_NAME}  "-framework GLUT" "-framework OpenGL" "-framework IOKit" "-framework Cocoa")
else ()
    message(FATAL_ERROR "Don't know how to generate a project for the current operating system! Expected OS: windows, linux or macos")
endif()

