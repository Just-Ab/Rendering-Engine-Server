#include <Rendering/Entity.h>


template<typename VertexT,typename InstanceDataT> 
void Entity<VertexT,InstanceDataT>::defineVertexAttributes(Attribute attribute){
    vao.linkAttribute(
        vbo,
        attribute.index,
        attribute.size,
        attribute.type,
        GL_FALSE,
        sizeof(VertexT),
        (void*)attribute.offset
    );            
    glVertexAttribDivisor(attribute.index,0);
}

template<typename VertexT,typename InstanceDataT> 
void Entity<VertexT,InstanceDataT>::defineVertexAttributes(std::vector<Attribute> attributes){
    for (uint8_t i = 0; i < attributes.size(); i++)
    {
        vao.linkAttribute(
            vbo,
            attributes[i].index,
            attributes[i].size,
            attributes[i].type,
            GL_FALSE,
            sizeof(VertexT),
            (void*)attributes[i].offset
        );
        glVertexAttribDivisor(attributes[i].index,0);
    }
}

template<typename VertexT,typename InstanceDataT> 
void Entity<VertexT,InstanceDataT>::defineInstanceAttributes(Attribute attribute){
    vao.linkAttribute(
        instanceVbo,
        attribute.index,
        attribute.size,
        attribute.type,
        GL_FALSE,
        sizeof(InstanceDataT),
        (void*)attribute.offset,
        1
    );       
}

template<typename VertexT,typename InstanceDataT> 
void Entity<VertexT,InstanceDataT>::defineInstanceAttributes(std::vector<Attribute> attributes){
    for (uint8_t i = 0; i < attributes.size(); i++)
    {
        vao.linkAttribute(
            instanceVbo,
            attributes[i].index,
            attributes[i].size,
            attributes[i].type,
            GL_FALSE,
            sizeof(InstanceDataT),
            (void*)attributes[i].offset,
            1
        );
    }




}

template<typename VertexT,typename InstanceDataT> 
void Entity<VertexT,InstanceDataT>::setInstances(InstanceDataT& instance){
    vao.bind();
    instanceVbo.bind();
    std::vector<InstanceDataT> ins = {{instance}};
    instanceVbo.setInstances(ins);
    instanceVbo.unBind();
    vao.unBind();
}

template<typename VertexT,typename InstanceDataT> 
void Entity<VertexT,InstanceDataT>::setInstances(std::vector<InstanceDataT>& instances){
    vao.bind();
    instanceVbo.bind();
    instanceVbo.setInstances(instances);
    instanceVbo.unBind();
    vao.unBind();
}

template<typename VertexT,typename InstanceDataT> 
void Entity<VertexT,InstanceDataT>::draw(Shader& shader,unsigned int instances){
    shader.activate();
    vao.bind();
    if (instances>0){
        glDrawElementsInstanced(GL_TRIANGLES,indices.size(),GL_UNSIGNED_INT,0,instances);
    }
    vao.unBind();
    shader.disactivate();
}


template<typename VertexT,typename InstanceDataT> 
void Entity<VertexT,InstanceDataT>::draw(Shader& shader,std::vector<InstanceDataT>& instances){
    unsigned int instancesCount = instances.size();
    shader.activate();
    vao.bind();
    if (instancesCount>0){
        instanceVbo.setInstances(instances);
        glDrawElementsInstanced(GL_TRIANGLES,indices.size(),GL_UNSIGNED_INT,0,instancesCount);
    }
    vao.unBind();
    shader.disactivate();
}



template class Entity<ColorRectVertex,ColorRectDataInstance>;
template class Entity<SpriteVertex,SpriteDataInstance>;
template class Entity<MeshVertex,MeshDataInstance>;
