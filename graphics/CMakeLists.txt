cmake_minimum_required(VERSION 3.5)
project(graphics)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_EXPORT_COMPILE_COMMANDS true)

if (NOT APPLE)
    include_directories(external/glad/include)
    set(GLAD_SRC external/glad/src/glad.c)
else()
    find_package(glfw3 3.4 REQUIRED)
    find_package(OpenGL REQUIRED)
    # this whole mess took me about an hour of my precious time to dig up
    # from the depths of the interwebs, all because clangd doesnt know how to
    # resolve framework include paths apparently.
    # also, why on god's green earth is the variable naming scheme for opengl's
    # cmake entries so inconsistent?
    # some variables have an OpenGL_ prefix, others have OPENGL_
    # its only thanks to <https://gist.github.com/christopheredsall/e778177bd584e7f17ca32530017f854a>
    # (god bless his soul) that I could even get it working.
    message( STATUS "OPENGL_INCLUDE_DIR = ${OPENGL_INCLUDE_DIR}" )
    file(MAKE_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/include")
    file(CREATE_LINK "${OPENGL_INCLUDE_DIR}/Headers" "${CMAKE_CURRENT_BINARY_DIR}/include/OpenGL" SYMBOLIC)
    #add_custom_command(
    #    OUTPUT "${CMAKE_CURRENT_BINARY_DIR}/include/OpenGL"
    #    COMMAND ls "${OPENGL_INCLUDE_DIR}/Headers" #"${CMAKE_CURRENT_BINARY_DIR}/include/OpenGL"
    #    DEPENDS ${OPENGL_INCLUDE_DIR}
    #)
    include_directories("${CMAKE_CURRENT_BINARY_DIR}/include")
    #include_directories(external/GLFW_MACOS_CLANGD_FIX)
endif()

add_executable(${CMAKE_PROJECT_NAME} ${GLAD_SRC} src/main.cc)

if (LINUX)
    target_link_libraries(${CMAKE_PROJECT_NAME} GL glfw)
elseif (WIN32)
    target_link_libraries(${CMAKE_PROJECT_NAME} glfw3 kernel32 opengl32)
elseif (APPLE)
    target_link_libraries(${CMAKE_PROJECT_NAME} glfw "-framework OpenGL" "-framework IOKit" "-framework Cocoa")
else ()
    message(FATAL_ERROR "Don't know how to generate a project for the current operating system! Expected OS: windows, linux or macos")
endif()

