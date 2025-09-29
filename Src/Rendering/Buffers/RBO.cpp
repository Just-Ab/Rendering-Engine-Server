#include <Rendering/Buffers/RBO.h>





RBO::RBO(){
    glGenRenderbuffers(1,&ID);
    glBindRenderbuffer(GL_RENDERBUFFER,ID);
}

void RBO::activate(){
    glBindRenderbuffer(GL_RENDERBUFFER,ID);
}

void RBO::disactivate(){
    glBindRenderbuffer(GL_RENDERBUFFER,0);

}

void RBO::destroy(){
    glDeleteRenderbuffers(1,&ID);
}

unsigned int RBO::getId(){
        return ID;
    }
