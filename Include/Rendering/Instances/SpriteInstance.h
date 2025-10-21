#ifndef SPRITEINSTANCE_H
#define SPRITEINSTANCE_H

#include <Algebra/glm/glm.hpp>
#include <Rendering/Resources/SpriteResource.h>
#include <Rendering/Texture.h>
#include <Rendering/ShaderProgram.h>

#include <memory>


class SpriteInstance
{
private:

    glm::vec3 position=glm::vec3(0.0f);
    glm::vec3 rotation=glm::vec3(0.0f);
    glm::vec3 scale=glm::vec3(1.0f);

    Texture* texture=nullptr;
    SpriteResource* resource=nullptr;
    ShaderProgram* shaderProgram=nullptr;

public:
    SpriteInstance(SpriteResource* _resource,ShaderProgram* _shader);
    
    void setPosition(glm::vec3 _position);
    const glm::vec3 getPosition();

    void setRotation(glm::vec3 _rotation);
    const glm::vec3 getRotation();
    
    void setScale(glm::vec3 _scale);
    const glm::vec3 getScale();

    void setTexture(Texture* _texturePath);
    Texture* getTexture();

    void setShader(ShaderProgram* _shader);
    ShaderProgram* getShader();

    SpriteResource* getResource();
};


#endif