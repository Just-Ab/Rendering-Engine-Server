#include <Rendering/RenderingServer.h>

int main(){

    RenderingServer::getSingleton()->createWindow("ghdh",900,900);
    glClearColor(0.2,1.0,0.0,1.0f);
    while (!RenderingServer::getSingleton()->getWindow()->shouldClose())
    {
        RenderingServer::getSingleton()->beginFrame();
        RenderingServer::getSingleton()->endFrame();
    }
    return 0;
}