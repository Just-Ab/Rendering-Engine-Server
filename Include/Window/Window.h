#ifndef WINDOW_H
#define WINDOW_H


#include <Rendering/OpenGl/glad/glad.h>
#include <Rendering/OpenGl/GLFW/glfw3.h>
#include <iostream>

class Window
{
private:
    GLFWwindow *window;
    float width,height;
    void errorCallBack(int error, const char* description);
public:
    Window(std::string name,int width,int height);
    GLFWwindow *getGLFWWindow();
    bool shouldClose();
    int getWidth();
    int getHeight();
    void swapBuffer();
    void close();
    void destroy();
};







#endif