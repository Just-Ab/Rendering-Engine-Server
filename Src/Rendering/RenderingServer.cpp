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

void RenderingServer::initServer(std::string name,unsigned int width,unsigned height){
    window = std::make_unique<Window>(name,width,height);
    spriteResource = new SpriteResource();
    colorRectResource = new ColorRectResource();

}

Window* RenderingServer::getWindow(){
    return window.get();
}

ShaderProgram* RenderingServer::createShaderProgram(std::string vertexPath,std::string fragmentPath){
    for (ShaderProgram &program:shaderPrograms)
    {
        if (program.getVertexShaderPath()==vertexPath && program.getFragmentShaderPath()==fragmentPath)
        {
            return &program;
        }
    }
    
    shaderPrograms.emplace_back(vertexPath.c_str(),fragmentPath.c_str());
    return &shaderPrograms.back();
}

ShaderProgram* RenderingServer::createShaderProgram(std::string vertexPath,std::string fragmentPath,std::string geometryPath){
    for (ShaderProgram & program:shaderPrograms)
    {
        if (program.getVertexShaderPath()==vertexPath && program.getFragmentShaderPath()==fragmentPath && program.getGeometryShaderPath()==geometryPath)
        {
            return &program;
        }
    }
    shaderPrograms.emplace_back(vertexPath.c_str(),fragmentPath.c_str(),geometryPath.c_str());
    return &shaderPrograms.back();
}


Camera2D* RenderingServer::createCamera2D(float width,float height,float near,float far){
    cameras.emplace_back(glm::vec3(0.0f,0.0f,0.0f),width,height,near,far);
    return &cameras.back();
}


void RenderingServer::makeCamera2DCurrent(Camera2D* camera){
    currentCamera=camera;
}

Texture* RenderingServer::createTexture(std::string path){
    for (Texture& texture:textures)
    {
        if(texture.getPath()==path){
            return &texture;
        }
    }
    
    textures.emplace_back();
    textures.back().createPathTexture(path);
    return &textures.back();    
}


ColorRectInstance* RenderingServer::createColorRect(){
    ShaderProgram* shaderProgram = createShaderProgram("Assets/Shaders/ColorRect.vert","Assets/Shaders/ColorRect.frag");
    colorRectInstances.emplace_back(colorRectResource,shaderProgram);
    return &colorRectInstances.back();
}

ColorRectInstance* RenderingServer::createColorRect(ShaderProgram* _shaderProgram){
    colorRectInstances.emplace_back(colorRectResource,_shaderProgram);
    return &colorRectInstances.back();
}


SpriteInstance* RenderingServer::createSprite(Texture* texture){
    ShaderProgram* shaderProgram = createShaderProgram("Assets/Shaders/Sprite.vert","Assets/Shaders/Sprite.frag");
    spriteInstances.emplace_back(spriteResource,shaderProgram);
    spriteInstances.back().setTexture(texture);
    return &spriteInstances.back();
}



SpriteInstance* RenderingServer::createSprite(Texture* texture,ShaderProgram * _shaderProgram){
    spriteInstances.emplace_back(spriteResource,_shaderProgram);
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

        inst->getShader()->setVec3("color",{inst->getColor().r,inst->getColor().g,inst->getColor().b});
        glm::mat4 model;
        model = glm::translate(glm::mat4(1.0f),inst->getPosition());

        model = glm::rotate(model,inst->getRotation().x,glm::vec3(1.0f,0.0f,0.0f));
        model = glm::rotate(model,inst->getRotation().y,glm::vec3(0.0f,1.0f,0.0f));
        model = glm::rotate(model,inst->getRotation().z,glm::vec3(0.0f,0.0f,1.0f));
        model = glm::scale(model,inst->getScale());

        inst->getShader()->setMat4("model",model);
        inst->getShader()->setMat4("projection",currentCamera->getProjection());
        inst->getShader()->setMat4("view",currentCamera->getView());

        glDrawElements(GL_TRIANGLES,colorRectInstances[i].getResource()->indices.size(), GL_UNSIGNED_INT,0);
        
        inst->getShader()->disactivate();
        inst->getResource()->unbind();
    }
    //draw sprites
    spriteResource->bind();
    for (unsigned int i = 0; i < spriteInstances.size(); i++)
    {
        SpriteInstance* inst=&spriteInstances[i];
        inst->getShader()->activate();
        inst->getTexture()->bind();

        glm::mat4 model;
        model = glm::translate(glm::mat4(1.0f),inst->getPosition());

        model = glm::rotate(model,inst->getRotation().x,glm::vec3(1.0f,0.0f,0.0f));
        model = glm::rotate(model,inst->getRotation().y,glm::vec3(0.0f,1.0f,0.0f));
        model = glm::rotate(model,inst->getRotation().z,glm::vec3(0.0f,0.0f,1.0f));
        model = glm::scale(model,inst->getScale());

        inst->getShader()->setMat4("model",model);
        inst->getShader()->setMat4("projection",currentCamera->getProjection());
        inst->getShader()->setMat4("view",currentCamera->getView());
        glDrawElements(GL_TRIANGLES,spriteInstances[i].getResource()->indices.size(), GL_UNSIGNED_INT,0);
        
        inst->getTexture()->unbind();
        inst->getShader()->disactivate();
    }
    spriteResource->unbind();

}

void RenderingServer::endFrame(){
    window->swapBuffer();
}


void RenderingServer::destroy(){
    delete server;
    server = nullptr;
}


