#ifndef SPRITEINSTANCE_H
#define SPRITEINSTANCE_H

#include <Algebra/glm/glm.hpp>
#include <Rendering/Resources/SpriteResource.h>
#include <Rendering/Texture.h>
#include <Rendering/Shader.h>

#include <memory>


class SpriteInstance
{
private:

    glm::vec3 position=glm::vec3(0.0f);

    Texture* texture=nullptr;
    SpriteResource* resource=nullptr;
    Shader* shader=nullptr;

public:
    SpriteInstance(SpriteResource* _resource,Shader* _shader);
    
    void setPosition(glm::vec3 _position);
    const glm::vec3 getPosition();

    void setTexture(Texture* _texturePath);
    Texture* getTexture();

    void setShader(Shader* _shader);
    Shader* getShader();

    SpriteResource* getResource();
};


#endif