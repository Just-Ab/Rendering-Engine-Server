#ifndef COLORRECTINSTANCE_H
#define COLORRECTINSTANCE_H

#include <Algebra/glm/glm.hpp>
#include <Rendering/Resources/ColorRectResource.h>
#include <Rendering/Shader.h>

#include <memory>


class ColorRectInstance
{
private:
    struct colorf{float r;float g;float b;float a;};
    glm::vec3 position=glm::vec3(0.0f);
    colorf color = {0.0f,0.0f,0.0f,1.0f};

    ColorRectResource* resource=nullptr;
    Shader* shader=nullptr;

public:
    ColorRectInstance(ColorRectResource* _resource,Shader* _shader);
    
    void setPosition(glm::vec3 _position);
    const glm::vec3 getPosition();

    void setColor(colorf _color);
    const colorf getColor();

    void setShader(Shader* _shader);
    Shader* getShader();

    ColorRectResource* getResource();
};


#endif