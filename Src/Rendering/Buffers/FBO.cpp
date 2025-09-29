#include <Rendering/Buffers/FBO.h>




FBO::FBO(){
    glGenFramebuffers(1,&ID);
    glBindFramebuffer(GL_FRAMEBUFFER,ID);
    if(!glCheckFramebufferStatus(GL_FRAMEBUFFER)==GL_FRAMEBUFFER_COMPLETE){
        std::cout<<"FBO::INCOMPLETE!"<<std::endl;
    }
}

void FBO::attachTexture(Texture&texture,int width,int height,FrameBufferTypes type){
    glBindFramebuffer(GL_FRAMEBUFFER,ID);

    GLenum internalFormat,dataFormat,dataType,attachmentType;

    switch (type)
    {
    case TEXTURE_COLOR:
        internalFormat=GL_RGB;
        dataFormat=GL_RGB;
        dataType=GL_UNSIGNED_BYTE;
        attachmentType=GL_COLOR_ATTACHMENT0;
        break;

    case TEXTURE_DEPTH24:
        internalFormat=GL_DEPTH_COMPONENT24;
        dataFormat=GL_DEPTH_COMPONENT;
        dataType=GL_FLOAT;
        attachmentType=GL_DEPTH_ATTACHMENT;        
        break;

    case TEXTURE_DEPTH:
        internalFormat=GL_DEPTH_COMPONENT;
        dataFormat=GL_DEPTH_COMPONENT;
        dataType=GL_FLOAT;
        attachmentType=GL_DEPTH_ATTACHMENT;        
        break;

    case TEXTURE_STENCIL:
        internalFormat=GL_STENCIL_INDEX8;
        dataFormat=GL_STENCIL_INDEX;
        dataType=GL_UNSIGNED_BYTE;
        attachmentType=GL_STENCIL_ATTACHMENT;        
        break;

    case TEXTURE_DEPTH_STENCIL:
        internalFormat=GL_DEPTH24_STENCIL8;
        dataFormat=GL_DEPTH_STENCIL;
        dataType=GL_UNSIGNED_INT_24_8;
        attachmentType=GL_DEPTH_STENCIL_ATTACHMENT;        
        break;

    default:
        std::cout<<"WRONG::TEXTURE::TYPE!"<<std::endl;
        return;
        break;
    }

    texture.createNullTexture(width,height,internalFormat,dataFormat,dataType);
    texture.bind();
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_NEAREST);

    glFramebufferTexture2D(GL_FRAMEBUFFER,attachmentType,GL_TEXTURE_2D,texture.getID(),0);

    glBindFramebuffer(GL_FRAMEBUFFER,0);
}



void FBO::attachRenderBuffer(RBO&renderBuffer,int width,int height,FrameBufferTypes type){
    glBindFramebuffer(GL_FRAMEBUFFER,ID);


    GLenum internalFormat,attachmentType;

    switch (type)
    {
    case RBO_COLOR:
        internalFormat=GL_RGB;
        attachmentType=GL_COLOR_ATTACHMENT0;
        break;

    case RBO_DEPTH:
        internalFormat=GL_DEPTH_COMPONENT24;
        attachmentType=GL_DEPTH_ATTACHMENT;        
        break;

    case RBO_DEPTH24:
        internalFormat=GL_DEPTH_COMPONENT;
        attachmentType=GL_DEPTH_ATTACHMENT;        
        break;

    case RBO_STENCIL:
        internalFormat=GL_STENCIL_INDEX8;
        attachmentType=GL_STENCIL_ATTACHMENT;        
        break;

    case RBO_DEPTH_STENCIL:
        internalFormat=GL_DEPTH24_STENCIL8;
        attachmentType=GL_DEPTH_STENCIL_ATTACHMENT;        
        break;

    default:
        std::cout<<"WRONG::RBO::TYPE!"<<std::endl;
        return;
        break;
    }

    glRenderbufferStorage(GL_RENDERBUFFER,internalFormat,width,height);

    glFramebufferRenderbuffer(GL_FRAMEBUFFER,attachmentType,GL_RENDERBUFFER,renderBuffer.getId());

    glBindFramebuffer(GL_FRAMEBUFFER,0);


}


void FBO::activate(){
    glBindFramebuffer(GL_FRAMEBUFFER,ID);
}

void FBO::disactivate(){
    glBindFramebuffer(GL_FRAMEBUFFER,0);
}

void FBO::setDrawBuffer(GLenum value){
    glBindFramebuffer(GL_FRAMEBUFFER,ID);
    glDrawBuffer(value);
    glBindFramebuffer(GL_FRAMEBUFFER,0);
}

void FBO::setReadBuffer(GLenum value){
    glBindFramebuffer(GL_FRAMEBUFFER,ID);
    glReadBuffer(value);
    glBindFramebuffer(GL_FRAMEBUFFER,0);
}

void FBO::destroy(){
    glDeleteFramebuffers(1,&ID);
}
unsigned int FBO::getId(){
        return ID;
    }