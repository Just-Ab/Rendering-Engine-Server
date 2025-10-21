#include <Rendering/RenderingServer.h>

int main(){

    RenderingServer::getSingleton()->initServer("Window",900,900);
    glClearColor(0.2,0.3,0.7,1.0f);

    Camera2D* camera = RenderingServer::getSingleton()->createCamera2D(2.0f,2.0f,-4.0f,4.0f);
    RenderingServer::getSingleton()->makeCamera2DCurrent(camera);

    Texture* texture = RenderingServer::getSingleton()->createTexture("Assets/Textures/socrat.jpg");
    SpriteInstance* sprite = RenderingServer::getSingleton()->createSprite(texture);
    sprite->setPosition({0.0f,0.0f,0.0f});

    ColorRectInstance* rect = RenderingServer::getSingleton()->createColorRect();
    rect->setColor({1.0f,1.0f,0.0f});
    rect->setPosition({0.5f,0.0f,0.0f});
    rect->setRotation({0.0f,0.0f,180.0f});
    while (!RenderingServer::getSingleton()->getWindow()->shouldClose())
    {
        sprite->setRotation({(float)sin(glfwGetTime()),0.0f,0.0f});
        RenderingServer::getSingleton()->beginFrame();
        RenderingServer::getSingleton()->drawFrame();
        RenderingServer::getSingleton()->endFrame();
    }
}