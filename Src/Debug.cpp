#include <Rendering/RenderingServer.h>

int main(){

    RenderingServer::getSingleton()->createWindow("Window",900,900);
    glClearColor(0.2,0.3,0.7,1.0f);

    Texture* texture = RenderingServer::getSingleton()->createTexture("Assets/Textures/socrat.jpg");
    Camera2D* camera = RenderingServer::getSingleton()->createCamera2D(2.0f,2.0f);
    Camera2D* camera2 = RenderingServer::getSingleton()->createCamera2D(4.0f,4.0f);
    RenderingServer::getSingleton()->makeCamera2DCurrent(camera);
    SpriteInstance* sprite = RenderingServer::getSingleton()->createSprite(texture);
    sprite->setPosition({0.0f,0.0f,0.0f});
    float timer=0;
    while (!RenderingServer::getSingleton()->getWindow()->shouldClose())
    {
        timer+=1;
        if (timer>=100){
            timer=0;
            RenderingServer::getSingleton()->makeCamera2DCurrent(camera2);
        }
        std::cout<<timer<<'\n';
        RenderingServer::getSingleton()->beginFrame();
        RenderingServer::getSingleton()->drawFrame();
        RenderingServer::getSingleton()->endFrame();
    }
}