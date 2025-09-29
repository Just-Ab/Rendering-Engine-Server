#ifndef FBO_H
#define FBO_H

#include <Rendering/OpenGl/glad/glad.h>
#include <Rendering/OpenGl/GLFW/glfw3.h>
#include <Rendering/Buffers/RBO.h>
#include <Rendering/Texture.h>
#include <iostream>


class FBO
{
private:
    unsigned int ID;
public:
    FBO();

    void attachTexture(Texture&texture,int width,int height,FrameBufferTypes type);
    void attachRenderBuffer(RBO&renderBuffer,int width,int height,FrameBufferTypes type);

    void activate();
    void disactivate();
    void setDrawBuffer(GLenum value);
    void setReadBuffer(GLenum value);
    void destroy();
    unsigned int getId();

};





#endif