#include <Rendering/Buffers/UBO.h>





    UBO::UBO(size_t size){
        glGenBuffers(1,&ID);
        glBindBuffer(GL_UNIFORM_BUFFER,ID);
        glBufferData(GL_UNIFORM_BUFFER,size,NULL,GL_STATIC_DRAW);
        glBindBuffer(GL_UNIFORM_BUFFER,0);
    }

    void UBO::bindToIndex(unsigned int index){
        glBindBufferBase(GL_UNIFORM_BUFFER,index,ID);
    }

    void UBO::setData(size_t offset,size_t size,const void* data){
        glBindBuffer(GL_UNIFORM_BUFFER,ID);
        glBufferSubData(GL_UNIFORM_BUFFER,offset,size,data);
        glBindBuffer(GL_UNIFORM_BUFFER,0);
    }


    unsigned int UBO::getId(){
        return ID;
    }

    void UBO::bind(){
        glBindBuffer(GL_UNIFORM_BUFFER,ID);
    }

    void UBO::unBind(){
        glBindBuffer(GL_UNIFORM_BUFFER,0);
    }