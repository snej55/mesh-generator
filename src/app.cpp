//
// Created by Jens Kromdijk on 04/04/25.
//

#include "app.h"

#include <iostream>

App::App(const int width, const int height, const char *title) {
    if (!init(width, height, title)) {
        std::cout << "Failed to initialize!" << std::endl;
    } else {
        std::cout << "Initialized OpenGL context!" << std::endl;
    }
}

bool App::init(const int width, const int height, const char* title) {
    // initialize opengl context
    glfwInit();

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    m_Window = glfwCreateWindow(width, height, title, nullptr, nullptr);
    if (!m_Window) {
        std::cout << "Failed to create GLFW window!" << std::endl;
        glfwTerminate();
        return false;
    }
    glfwMakeContextCurrent(m_Window);

    if (!gladLoadGLLoader(reinterpret_cast<GLADloadproc>(glfwGetProcAddress))) {
        std::cout << "Failed to initialize GLAD!" << std::endl;
        return false;
    }

    // set up viewport
    m_width = width;
    m_height = height;
    glViewport(0, 0, m_width, m_height);

    // make sure callbacks can access data
    glfwSetWindowUserPointer(m_Window, this);

    // configure window callbacks
    glfwSetFramebufferSizeCallback(m_Window, win_framebuffer_size_callback);
    glfwSetCursorPosCallback(m_Window, win_mouse_callback);
    glfwSetScrollCallback(m_Window, win_scroll_callback);

    return true;
}


// getters and setters
bool App::shouldClose() const {
    return glfwWindowShouldClose(m_Window);
}

GLFWwindow* App::getWindow() const {
    return m_Window;
}

int App::getWidth() const {
    return m_width;
}

int App::getHeight() const {
    return m_height;
}
