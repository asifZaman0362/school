cmake_minimum_required(VERSION 3.5)
project(graphics)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_EXPORT_COMPILE_COMMANDS true)

set(NIX COMMAND "nix --version")

if (NOT NIX)
    find_package(GLUT REQUIRED)
endif()
if (APPLE)
    find_package(OpenGL REQUIRED)
endif()

if (WIN32)
    if (CMAKE_SIZEOF_VOID_P EQUAL 8)
        set(ARCH "x64")
    else ()
        set(ARCH "x32")
    endif ()
    if (MSVC)
        set(COMPILER "MSVC")
    elseif (MINGW)
        set(COMPILER "MinGW")
    else ()
        message(FATAL_ERROR "Expected either MSVC or MinGW compiler!")
    endif ()
    SET(GLUT_INCLUDE_DIRS "external/freeglut/${COMPILER}/include")
    SET(GLUT_LIB "external/freeglut/${COMPILER}/lib/${ARCH}/freeglut")
endif()

include_directories(${GLUT_INCLUDE_DIRS} ${OPENGL_INCLUDE_DIR})

add_executable(${CMAKE_PROJECT_NAME} ${GLAD_SRC} src/main.cc)

if (LINUX)
    target_link_libraries(${CMAKE_PROJECT_NAME} GL glut GLU)
elseif (WIN32)
    target_link_libraries(${CMAKE_PROJECT_NAME} ${GLUT_LIB} kernel32 opengl32)
elseif (APPLE)
    target_link_libraries(${CMAKE_PROJECT_NAME}  "-framework GLUT" "-framework OpenGL" "-framework IOKit" "-framework Cocoa")
else ()
    message(FATAL_ERROR "Don't know how to generate a project for the current operating system! Expected OS: windows, linux or macos")
endif()

