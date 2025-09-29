#ifndef VAO_H
#define VAO_H

// #include <Rendering/OpenGl/glad/glad.h>
// #include <Rendering/OpenGl/GLFW/glfw3.h>
#include <Rendering/Buffers/EBO.h>
#include <Rendering/Buffers/VBO.h>
#include <iostream>
#include <vector>



class VAO
{
private:
    unsigned int ID;
public:

    VAO();
    template<typename VBOT>
    void linkAttribute(VBOT&vbo,int index,int size,GLenum type,GLenum normalized,int stride,void* offset,unsigned int divisor = 0);
    void bind();
    void unBind();

};

#endif