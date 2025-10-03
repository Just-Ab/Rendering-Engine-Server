#include <Rendering/RenderingServer.h>

int main(){

    RenderingServer::getSingleton()->createWindow("Window",900,900);
    glClearColor(0.2,0.3,0.7,1.0f);
    Shader* shader = RenderingServer::getSingleton()->createShader("Assets/Shaders/ColorRect.vert","Assets/Shaders/ColorRect.frag");
    ColorRectInstance* rect1 = RenderingServer::getSingleton()->createColorRect(shader);
    ColorRectInstance* rect2 = RenderingServer::getSingleton()->createColorRect(shader);
    ColorRectInstance* rect3 = RenderingServer::getSingleton()->createColorRect(shader);
    
    rect1->setPosition({-0.3f,-0.1,0.0f});
    rect2->setPosition({0.1f,-0.4,0.0f});
    rect3->setPosition({0.0f,0.2,0.0f});

    while (!RenderingServer::getSingleton()->getWindow()->shouldClose())
    {
        RenderingServer::getSingleton()->beginFrame();
        rect1->setColor({(float)sin(glfwGetTime()),0.2,0.0f});
        rect2->setColor({0.1,(float)sin(glfwGetTime()),0.0f});
        rect3->setColor({0.2,0.2,(float)sin(glfwGetTime())});

        RenderingServer::getSingleton()->drawFrame();
        RenderingServer::getSingleton()->endFrame();
    }
}