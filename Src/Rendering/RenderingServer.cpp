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


Camera2D* RenderingServer::createCamera2D(float width,float height){
    cameras.emplace_back(glm::vec3(0.0f,0.0f,0.0f),width,height,0.0f,1.0f);
    return &cameras.back();
}


void RenderingServer::makeCamera2DCurrent(Camera2D* camera){
    currentCamera=camera;
}

Texture* RenderingServer::createTexture(std::string path){
    textures.emplace_back();
    textures.back().createPathTexture(path);
    return &textures.back();    
}


ColorRectInstance* RenderingServer::createColorRect(unsigned int count){
    colorRectResources.emplace_back();
    Shader* shader = createShader("Assets/Shaders/ColorRect.vert","Assets/Shaders/ColorRect.frag");
    colorRectInstances.emplace_back(&colorRectResources.back(),shader);
    return &colorRectInstances.back();
}

ColorRectInstance* RenderingServer::createColorRect(Shader* _shader,unsigned int count){
    colorRectResources.emplace_back();
    colorRectInstances.emplace_back(&colorRectResources.back(),_shader);
    return &colorRectInstances.back();
}


SpriteInstance* RenderingServer::createSprite(Texture* texture,unsigned int count){
    spriteResources.emplace_back();
    Shader* shader = createShader("Assets/Shaders/Sprite.vert","Assets/Shaders/Sprite.frag");
    spriteInstances.emplace_back(&spriteResources.back(),shader);
    spriteInstances.back().setTexture(texture);
    return &spriteInstances.back();
}



SpriteInstance* RenderingServer::createSprite(Texture* texture,Shader* _shader,unsigned int count){
    spriteResources.emplace_back();
    spriteInstances.emplace_back(&spriteResources.back(),_shader);
    spriteInstances.back().setTexture(texture);
    return &spriteInstances.back();
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
        inst->getShader()->setMat4("projection",currentCamera->getProjection());
        inst->getShader()->setMat4("view",currentCamera->getView());

        glDrawElements(GL_TRIANGLES,colorRectInstances[i].getResource()->indices.size(), GL_UNSIGNED_INT,0);
        
        inst->getShader()->disactivate();
        inst->getResource()->unbind();
    }
    //draw sprites
    for (unsigned int i = 0; i < spriteInstances.size(); i++)
    {
        SpriteInstance* inst=&spriteInstances[i];
        inst->getResource()->bind();
        inst->getShader()->activate();
        inst->getTexture()->bind();

        inst->getShader()->setVec3("position",inst->getPosition());
        inst->getShader()->setMat4("projection",currentCamera->getProjection());
        inst->getShader()->setMat4("view",currentCamera->getView());
        glDrawElements(GL_TRIANGLES,spriteInstances[i].getResource()->indices.size(), GL_UNSIGNED_INT,0);
        
        inst->getTexture()->unbind();
        inst->getShader()->disactivate();
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


