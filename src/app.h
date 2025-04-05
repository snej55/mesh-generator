//
// Created by Jens Kromdijk on 04/04/25.
//

#ifndef APP_H
#define APP_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>

class App {
public:
    App(int width, int height, const char* title);
    ~App();

    [[nodiscard]] bool shouldClose() const;

    [[nodiscard]] GLFWwindow* getWindow() const;

    [[nodiscard]] int getWidth() const;

    [[nodiscard]] int getHeight() const;

    void setTitle(const char* title) const;

private:
    GLFWwindow* m_Window{nullptr};
    int m_width{0};
    int m_height{0};

    bool init(int width, int height, const char* title);

    static void win_framebuffer_size_callback(GLFWwindow* window, int width, int height);

    static void win_mouse_callback(GLFWwindow* window, double xPosIn, double yPosIn);
    static void win_scroll_callback(GLFWwindow* window, double xOffset, double yOffset);
};



#endif //APP_H
