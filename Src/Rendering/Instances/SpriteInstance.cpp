#include <Rendering/Instances/SpriteInstance.h>






SpriteInstance::SpriteInstance(SpriteResource* _resource,Shader* _shader){
    resource = _resource;
    shader = _shader;
}


    void SpriteInstance::setPosition(glm::vec3 _position){
        position = _position;
    }
    const glm::vec3 SpriteInstance::getPosition(){
        return position;
    }

    void SpriteInstance::setTexture(Texture* _texture){
        texture = _texture;
    }
    Texture* SpriteInstance::getTexture(){
        return texture;
    }

    void SpriteInstance::setShader(Shader* _shader){
        shader = _shader;
    }

    Shader* SpriteInstance::getShader(){
        return shader;
    }

    SpriteResource* SpriteInstance::getResource(){
        return resource;
    }
