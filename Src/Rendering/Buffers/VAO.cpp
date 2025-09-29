#include <Rendering/Buffers/VAO.h>


    VAO::VAO(){
        glGenVertexArrays(1,&ID);
    }

    template<typename VBOT>
    void VAO::linkAttribute(VBOT&vbo,int index,int size,GLenum type,GLenum normalized,int stride,void* offset,unsigned int divisor){
        glBindVertexArray(ID);
        vbo.bind();
        glVertexAttribPointer(index,size,type,normalized,stride,offset);
        glEnableVertexAttribArray(index);

        GLint result;
        glGetVertexAttribiv(index,GL_VERTEX_ATTRIB_ARRAY_ENABLED,&result);
        if(!result){
            std::cout<<"Enabling Attribute "<<index<<" Failed!"<<std::endl;
        }
        glVertexAttribDivisor(index,divisor);
        glBindBuffer(GL_ARRAY_BUFFER,0);
        glBindVertexArray(0);
    }
    void VAO::bind(){
        glBindVertexArray(ID);
    }

    void VAO::unBind(){
        glBindVertexArray(0);
    }


template void VAO::linkAttribute<VBO<ColorRectVertex, ColorRectDataInstance>>
(VBO<ColorRectVertex, ColorRectDataInstance>&, int, int, GLenum, GLenum, int, void*, unsigned int);

template void VAO::linkAttribute<VBO<SpriteVertex, SpriteDataInstance>>
(VBO<SpriteVertex, SpriteDataInstance>&, int, int, GLenum, GLenum, int, void*, unsigned int);

template void VAO::linkAttribute<VBO<MeshVertex, MeshDataInstance>>
(VBO<MeshVertex, MeshDataInstance>&, int, int, GLenum, GLenum, int, void*, unsigned int);

