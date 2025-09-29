#include <Rendering/Sprite.h>




Sprite::Sprite(){
    vertices = PrimitiveShapes::SpriteQuad.vertices;
    indices = PrimitiveShapes::SpriteQuad.indices;
    setup();
}

void Sprite::setup(){    
    vao.bind();
    vbo.setVertices(vertices);
    EBO ebo(indices);
    vbo.unBind();
    vao.unBind();
}

void Sprite::setTexture(const char* path){
    texture.createPathTexture(path);
}

void Sprite::setTexture(Texture _texture){
    texture = _texture;
}

void Sprite::draw(Shader& shader,unsigned int instances){
    shader.activate();
    vao.bind();
    glActiveTexture(GL_TEXTURE0);
    texture.bind();
    glDrawElementsInstanced(GL_TRIANGLES,indices.size(),GL_UNSIGNED_INT,0,instances);
    glBindTexture(GL_TEXTURE_2D,0);
    vao.unBind();
    shader.disactivate();
}

void Sprite::draw(Shader& shader,std::vector<SpriteDataInstance>& instances){
    unsigned int instancesCount = instances.size();
    shader.activate();
    vao.bind();
    glActiveTexture(GL_TEXTURE0);
    texture.bind();
    if (instancesCount>=1){
        instanceVbo.setInstances(instances);
        glDrawElementsInstanced(GL_TRIANGLES,indices.size(),GL_UNSIGNED_INT,0,instancesCount);
    }
    else{
        glDrawElements(GL_TRIANGLES,indices.size(),GL_UNSIGNED_INT,0);
    }
    glBindTexture(GL_TEXTURE_2D,0);
    vao.unBind();
    shader.disactivate();
}