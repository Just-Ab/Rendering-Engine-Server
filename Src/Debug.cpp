#include <Rendering/RenderingServer.h>

int main(){

    RenderingServer::getSingleton()->createWindow("Window",900,900);
    glClearColor(0.2,0.3,0.7,1.0f);

    Texture* texture = RenderingServer::getSingleton()->createTexture("Assets/Textures/socrat.jpg");
    SpriteInstance* sprite = RenderingServer::getSingleton()->createSprite(texture);
    sprite->setPosition({0.5f,0.5f,0.0f});
    while (!RenderingServer::getSingleton()->getWindow()->shouldClose())
    {
        RenderingServer::getSingleton()->beginFrame();
        RenderingServer::getSingleton()->drawFrame();
        RenderingServer::getSingleton()->endFrame();
    }
}