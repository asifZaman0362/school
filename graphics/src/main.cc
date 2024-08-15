#define GLFW_INCLUDE_NONE
#ifdef __APPLE__
#define GLFW_INCLUDE_GLCOREARB
#define GL_SILENCE_DEPRECATION
#endif
#include <GLFW/glfw3.h>

#ifndef __APPLE__
#include <glad/glad.h>
#endif

int main(int argc, char** argv) {
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit()) {
        return -1;
    }

#ifdef __APPLE__
    /* We need to explicitly ask for a 3.2 context on OS X */
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#endif

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(1280, 720, "Hello World", NULL, NULL);
    if (!window) {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window)) {
        /* Render here */
        glClearColor(0.5f, 0.4f, 0.8f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT |
                GL_DEPTH_BUFFER_BIT);  // Clear the buffers

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
