#include <Rendering/Texture.h>







    void Texture::createPathTexture(std::string path){
        method = LoadingMethod::PATHTEXTURE;
        path=path;
        id = textureLoader.loadTexture2D(path);
    }
    void Texture::createNullTexture(unsigned int _width,unsigned int _height,GLenum _internalFormat,GLenum _format,GLenum _contentType){
        method = LoadingMethod::NULLTEXTURE;
        id = textureLoader.generateTexture(_width,_height,_internalFormat,_format,_contentType);
        internalFormat = _internalFormat;format=_format;contentType=_contentType;
    }
    void Texture::setTextureData(unsigned int _xoffset,unsigned int _yoffset,unsigned int _xlength,unsigned int _ylength,void* _data){
        if(method != LoadingMethod::NULLTEXTURE){return;}
        glBindTexture(GL_TEXTURE_2D,id);
        glTexSubImage2D(GL_TEXTURE_2D,0,_xoffset,_yoffset,_xlength,_ylength,format,contentType,_data);
        glBindTexture(GL_TEXTURE_2D,0);
    }


    void Texture::bind(){
        glBindTexture(GL_TEXTURE_2D,id);
    }

    void Texture::unbind(){
        glBindTexture(GL_TEXTURE_2D,0);
    }

    unsigned int Texture::getID(){
        return id;
    }
    unsigned int Texture::getWidth(){
        return width;
    }
    unsigned int Texture::getHeight(){
        return height;
    }


    std::string Texture::getPath(){
        return path;
    }