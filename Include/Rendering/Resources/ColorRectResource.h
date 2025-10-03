#ifndef COLORRECTRESOURCE_H
#define COLORRECTRESOURCE_H

#include "Rendering/Buffers/VAO.h"

class ColorRectResource
{
private:
    VAO vao;VBO vbo;EBO ebo;



public:

    const float vertices[12] = {
        -0.5,-0.5,0.0,
        -0.5, 0.5,0.0,
         0.5,-0.5,0.0,
         0.5, 0.5,0.0
    }; 
    std::vector<unsigned int> indices = {
        0,1,2,
        1,2,3
    };

    ColorRectResource();


    
    void bind();
    void unbind();
};


#endif