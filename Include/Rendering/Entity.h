#ifndef ENTITY_H
#define ENTITY_H

#include <Rendering/OpenGl/glad/glad.h>

#include <Rendering/Buffers/VAO.h>
#include <Rendering/Shader.h>

#include <Shapes.hpp>
#include <Types.hpp>
#include <vector>
#include <iostream>


template<typename VertexT,typename InstanceDataT>
class Entity
{
protected:

    unsigned int verticesCount,indicesCount;

    std::vector<VertexT> vertices;
    std::vector<unsigned int> indices;

    VAO vao;
    VBO<VertexT,InstanceDataT>vbo,instanceVbo;

    virtual void setup() = 0;


public:
    Entity() = default;

    virtual void defineVertexAttributes(Attribute attribute);
    virtual void defineVertexAttributes(std::vector<Attribute> attributes);

    virtual void defineInstanceAttributes(Attribute attribute);
    virtual void defineInstanceAttributes(std::vector<Attribute> attributes);


    virtual void setInstances(InstanceDataT& instances);
    virtual void setInstances(std::vector<InstanceDataT>& instances);


    virtual void draw(Shader& shader,unsigned int instances);
    virtual void draw(Shader& shader,std::vector<InstanceDataT>& instances);
};

#endif