#ifndef COLORRECTINSTANCE_H
#define COLORRECTINSTANCE_H

#include <Algebra/glm/glm.hpp>
#include <Rendering/Resources/ColorRectResource.h>
#include <Rendering/ShaderProgram.h>

#include <memory>


class ColorRectInstance
{
private:
    struct colorf{float r;float g;float b;float a;};
    glm::vec3 position=glm::vec3(0.0f);
    glm::vec3 rotation=glm::vec3(0.0f);
    glm::vec3 scale=glm::vec3(1.0f);

    colorf color = {0.0f,0.0f,0.0f,1.0f};

    ColorRectResource* resource=nullptr;
    ShaderProgram* shaderProgram=nullptr;

public:
    ColorRectInstance(ColorRectResource* _resource,ShaderProgram* _shader);
    
    void setPosition(glm::vec3 _position);
    const glm::vec3 getPosition();

    void setRotation(glm::vec3 _rotation);
    const glm::vec3 getRotation();
    
    void setScale(glm::vec3 _scale);
    const glm::vec3 getScale();

    void setColor(colorf _color);
    const colorf getColor();

    void setShader(ShaderProgram* _shader);
    ShaderProgram* getShader();

    ColorRectResource* getResource();
};


#endif