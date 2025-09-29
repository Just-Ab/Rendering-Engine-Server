#include <Rendering/RenderingServer.h>




RenderingServer* RenderingServer::server = nullptr;



RenderingServer::RenderingServer(){
}


RenderingServer* RenderingServer::getSingleton(){
    if (!server){
        server = new RenderingServer();
    }
    return server;
}

void RenderingServer::createWindow(std::string name,unsigned int width,unsigned height){
    window = std::make_unique<Window>(name,width,height);
}

Window* RenderingServer::getWindow(){
    return window.get();
}

void RenderingServer::beginFrame(){
    glClear(GL_COLOR_BUFFER_BIT);
    glfwPollEvents();
}
void RenderingServer::endFrame(){
    window->swapBuffer();
}


void RenderingServer::destroy(){
    delete server;
    server = nullptr;
}