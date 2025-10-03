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

Shader* RenderingServer::createShader(std::string vertexShader,std::string fragmentShader,std::string geometryShader){
    shaders.emplace_back(vertexShader.c_str(),fragmentShader.c_str());
    return &shaders.back();
}


ColorRectInstance* RenderingServer::createColorRect(Shader* _shader,unsigned int count){
    colorRectResources.emplace_back();
    ColorRectResource* resource = &colorRectResources.back();
    colorRectInstances.emplace_back(resource,_shader);
    return &colorRectInstances.back();
}




void RenderingServer::beginFrame(){
    glClear(GL_COLOR_BUFFER_BIT);
    glfwPollEvents();
}

void RenderingServer::drawFrame(){
    //draw color rects
    for (unsigned i = 0; i < colorRectInstances.size(); i++)
    {
        ColorRectInstance* inst=&colorRectInstances[i];
        inst->getResource()->bind();
        inst->getShader()->activate();
        inst->getShader()->setVec3("position",inst->getPosition());
        inst->getShader()->setVec3("color",{inst->getColor().r,inst->getColor().g,inst->getColor().b});
        glDrawElements(GL_TRIANGLES,colorRectInstances[i].getResource()->indices.size(), GL_UNSIGNED_INT,0);
        inst->getResource()->unbind();
    }
}

void RenderingServer::endFrame(){
    window->swapBuffer();
}


void RenderingServer::destroy(){
    delete server;
    server = nullptr;
}


