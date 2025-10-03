#ifndef SPRITERESOURCE_H
#define SPRITERESOURCE_H

#include "Rendering/Buffers/VAO.h"

class SpriteResource
{
private:
    VAO vao;VBO vbo;EBO ebo;



public:

    const float vertices[20] = {
        //VERTEX POSITION    TEXEL
        -0.5,-0.5,0.0,      0.0f,0.0f,
        -0.5, 0.5,0.0,      0.0f,1.0f,
         0.5,-0.5,0.0,      1.0f,0.0f,
         0.5, 0.5,0.0,      1.0f,1.0f
    }; 
    std::vector<unsigned int> indices = {
        0,1,2,
        1,2,3
    };

    SpriteResource();


    
    void bind();
    void unbind();
};


#endif