#ifndef RBO_H
#define RBO_H

#include <Rendering/OpenGl/glad/glad.h>
#include <Rendering/OpenGl/GLFW/glfw3.h>
#include <iostream>


class RBO
{
private:
    unsigned int ID;
public:
    RBO();
    void activate();
    void disactivate();
    void disable();
    void destroy();
    unsigned int getId();
};





#endif