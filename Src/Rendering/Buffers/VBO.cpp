#include <Rendering/Buffers/VBO.h>


    VBO::VBO(){
        glGenBuffers(1,&ID);
    }

    VBO::VBO(const void* vertices,size_t size,GLenum usage){
        glGenBuffers(1,&ID);
        setVertices(vertices,size,usage);
        
    }
    
    void VBO::setVertices(const void* vertices,size_t size,GLenum usage){
        glBindBuffer(GL_ARRAY_BUFFER,ID);
        glBufferData(GL_ARRAY_BUFFER,size,vertices,usage);
        glBindBuffer(GL_ARRAY_BUFFER,0);
    }

    void VBO::setInstances(const void* instances,size_t stride,size_t count){
        glBindBuffer(GL_ARRAY_BUFFER,ID);
        size_t size = stride*count;
        activeInstances = count;
        if(instancesAllocated!=count){
            glBufferData(GL_ARRAY_BUFFER,size,instances,GL_DYNAMIC_DRAW);
            instancesAllocated = count;
        }
        else{
            glBufferSubData(GL_ARRAY_BUFFER,0,size,instances);
        }
        glBindBuffer(GL_ARRAY_BUFFER,0);
    }

    void VBO::allocateData(size_t size,GLenum type){
        glBindBuffer(GL_ARRAY_BUFFER,ID);
        glBufferData(GL_ARRAY_BUFFER,size,NULL,type);
        glBindBuffer(GL_ARRAY_BUFFER,0);
    }

    unsigned int VBO::getId() const{
        return ID;
    }

    void VBO::bind(){
        glBindBuffer(GL_ARRAY_BUFFER,ID);
    }

    void VBO::unBind(){
        glBindBuffer(GL_ARRAY_BUFFER,0);
    }
