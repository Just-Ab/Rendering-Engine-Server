#include <Rendering/Instances/ColorRectInstance.h>






ColorRectInstance::ColorRectInstance(ColorRectResource* _resource,ShaderProgram* _shaderProgram){
    resource = _resource;
    shaderProgram = _shaderProgram;
}


    void ColorRectInstance::setPosition(glm::vec3 _position){
        position = _position;
    }
    const glm::vec3 ColorRectInstance::getPosition(){
        return position;
    }

    void ColorRectInstance::setRotation(glm::vec3 _rotation){
        rotation = _rotation;
    }
    const glm::vec3 ColorRectInstance::getRotation(){
        return rotation;
    }

    void ColorRectInstance::setScale(glm::vec3 _scale){
        scale = _scale;
    }
    const glm::vec3 ColorRectInstance::getScale(){
        return scale;
    }

    void ColorRectInstance::setColor(colorf _color){
        color = _color;
    }
    const ColorRectInstance::colorf ColorRectInstance::getColor(){
        return color;
    }

    void ColorRectInstance::setShader(ShaderProgram* _shaderProgram){
        shaderProgram = _shaderProgram;
    }

    ShaderProgram* ColorRectInstance::getShader(){
        return shaderProgram;
    }

    ColorRectResource* ColorRectInstance::getResource(){
        return resource;
    }
