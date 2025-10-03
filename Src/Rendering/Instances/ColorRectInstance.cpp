#include <Rendering/Instances/ColorRectInstance.h>






ColorRectInstance::ColorRectInstance(ColorRectResource* _resource,Shader* _shader){
    resource = _resource;
    shader = _shader;
}


    void ColorRectInstance::setPosition(glm::vec3 _position){
        position = _position;
    }
    const glm::vec3 ColorRectInstance::getPosition(){
        return position;
    }

    void ColorRectInstance::setColor(colorf _color){
        color = _color;
    }
    const ColorRectInstance::colorf ColorRectInstance::getColor(){
        return color;
    }

    void ColorRectInstance::setShader(Shader* _shader){
        shader = _shader;
    }

    Shader* ColorRectInstance::getShader(){
        return shader;
    }

    ColorRectResource* ColorRectInstance::getResource(){
        return resource;
    }
