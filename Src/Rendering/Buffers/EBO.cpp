#include <Rendering/Buffers/EBO.h>



    EBO::EBO(){}

    EBO::EBO(std::vector<unsigned int> indices){
        glGenBuffers(1,&ID);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,ID);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER,indices.size()*sizeof(int),indices.data(),GL_STATIC_DRAW);
    }

    void EBO::setIndices(std::vector<unsigned int> indices){
        glGenBuffers(1,&ID);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,ID);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER,indices.size()*sizeof(int),indices.data(),GL_STATIC_DRAW);
    }

    unsigned int EBO::getId(){
        return ID;
    }

    void EBO::bind(){
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,ID);
    }

    void EBO::unBind(){
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,0);

    }
