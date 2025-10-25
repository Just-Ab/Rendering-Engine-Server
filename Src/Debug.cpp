#include <Rendering/RenderingServer.h>

int main(){

    RenderingServer::getSingleton()->initServer("Window",900,900);
    glClearColor(0.2,0.3,0.7,1.0f);

    Camera2D* camera = RenderingServer::getSingleton()->createCamera2D(2.0f,2.0f,-4.0f,4.0f);
    RenderingServer::getSingleton()->makeCamera2DCurrent(camera);
    
    Texture* texture = RenderingServer::getSingleton()->createTexture("Assets/Textures/socrat.jpg");
    SpriteInstance* rects[10000];
    for(int i =0;i<5000;i++){
        rects[i]=RenderingServer::getSingleton()->createSprite(texture);
        // rects[i]->setColor({0.4,0.3,0.6});
        rects[i]->setPosition({(float)i*0.1f,0.0f,0.0f});
        // std::cout<<"created: "<<i<<'\n';
    }

    while (!RenderingServer::getSingleton()->getWindow()->shouldClose())
    {
        RenderingServer::getSingleton()->beginFrame();
        RenderingServer::getSingleton()->drawFrame();
        RenderingServer::getSingleton()->endFrame();
    }
}