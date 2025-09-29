#ifndef INPUT_H
#define INPUT_H

#include <iostream>
#include <Rendering/OpenGl/glad/glad.h>
#include <Rendering/OpenGl/GLFW/glfw3.h>
#include <Window/Window.h>
#include <utility>

class Input
{
private:
    int prevKey=GLFW_KEY_UNKNOWN;
    float prevMousePoX=0.0f;
    float prevMousePoY=0.0f;

    GLFWwindow*window;
public:
    Input(Window window):window(window.getGLFWWindow()){
        prevMousePoX = (float)window.getWidth()/1;
        prevMousePoY = (float)window.getHeight()/1;

    }

    bool isKeyPressed(GLenum key);

    bool isKeyJustPressed(GLenum key);
    
    std::pair<float,float> getMouseOffset(float mouseX,float mouseY,float sensitivity);

};




#endif