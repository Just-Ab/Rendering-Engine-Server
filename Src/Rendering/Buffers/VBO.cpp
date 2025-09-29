#include <Rendering/Buffers/VBO.h>


    template<typename VertexT,typename InstanceDataT>
    VBO<VertexT,InstanceDataT>::VBO(){
        glGenBuffers(1,&ID);
    }

    template<typename VertexT,typename InstanceDataT>
    VBO<VertexT,InstanceDataT>::VBO(std::vector<VertexT>& vertices){
        glGenBuffers(1,&ID);
        setVertices(vertices);
        
    }
    
    template<typename VertexT,typename InstanceDataT>
    void VBO<VertexT,InstanceDataT>::setVertices(std::vector<VertexT>& vertices){
        glBindBuffer(GL_ARRAY_BUFFER,ID);
        glBufferData(GL_ARRAY_BUFFER,vertices.size()*sizeof(VertexT),vertices.data(),GL_STATIC_DRAW);
        glBindBuffer(GL_ARRAY_BUFFER,0);
    }

    template<typename VertexT,typename InstanceDataT>
    void VBO<VertexT,InstanceDataT>::setInstances(std::vector<InstanceDataT>& instances){
        glBindBuffer(GL_ARRAY_BUFFER,ID);
        if(instancesAllocated<instances.size()){
            glBufferData(GL_ARRAY_BUFFER,instances.size()*sizeof(InstanceDataT),instances.data(),GL_DYNAMIC_DRAW);
            instancesAllocated = instances.size();
        }
        else{
            glBufferSubData(GL_ARRAY_BUFFER,0,instances.size()*sizeof(InstanceDataT),instances.data());
        }
        glBindBuffer(GL_ARRAY_BUFFER,0);
    }

    template<typename VertexT,typename InstanceDataT>
    void VBO<VertexT,InstanceDataT>::allocateData(size_t size,GLenum type){
        glBindBuffer(GL_ARRAY_BUFFER,ID);
        glBufferData(GL_ARRAY_BUFFER,size,NULL,type);
        glBindBuffer(GL_ARRAY_BUFFER,0);
    }

    template<typename VertexT,typename InstanceDataT>
    unsigned int VBO<VertexT,InstanceDataT>::getId() const{
        return ID;
    }

    template<typename VertexT,typename InstanceDataT>
    void VBO<VertexT,InstanceDataT>::bind(){
        glBindBuffer(GL_ARRAY_BUFFER,ID);
    }

    template<typename VertexT,typename InstanceDataT>
    void VBO<VertexT,InstanceDataT>::unBind(){
        glBindBuffer(GL_ARRAY_BUFFER,0);
    }

template class VBO<ColorRectVertex,ColorRectDataInstance>;
template class VBO<SpriteVertex,SpriteDataInstance>;
template class VBO<MeshVertex,MeshDataInstance>;
