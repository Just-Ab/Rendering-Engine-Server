#include <Rendering/Instances/SpriteInstance.h>






SpriteInstance::SpriteInstance(SpriteResource* _resource,ShaderProgram* _shaderProgram){
    resource = _resource;
    shaderProgram = _shaderProgram;
}


    void SpriteInstance::setPosition(glm::vec3 _position){
        position = _position;
    }
    const glm::vec3 SpriteInstance::getPosition(){
        return position;
    }

    void SpriteInstance::setRotation(glm::vec3 _rotation){
        rotation = _rotation;
    }
    const glm::vec3 SpriteInstance::getRotation(){
        return rotation;
    }

    void SpriteInstance::setScale(glm::vec3 _scale){
        scale = _scale;
    }
    const glm::vec3 SpriteInstance::getScale(){
        return scale;
    }


    void SpriteInstance::setTexture(Texture* _texture){
        texture = _texture;
    }
    Texture* SpriteInstance::getTexture(){
        return texture;
    }

    void SpriteInstance::setShader(ShaderProgram* _shaderProgram){
        shaderProgram = _shaderProgram;
    }

    ShaderProgram* SpriteInstance::getShader(){
        return shaderProgram;
    }

    SpriteResource* SpriteInstance::getResource(){
        return resource;
    }
