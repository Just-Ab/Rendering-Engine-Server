#ifndef TEXTURE_H
#define TEXTURE_H

#include<Rendering/TextureLoader.h>

class Texture
{
private:
    enum class LoadingMethod{PATHTEXTURE,NULLTEXTURE};

    unsigned int height,width;
    std::string path;
    LoadingMethod method;
    GLenum internalFormat,format,contentType;
    
    unsigned int id;
public:
    TextureLoader textureLoader;
    
    void createPathTexture(std::string path);
    void createNullTexture(unsigned int _width,unsigned int _height,GLenum _internalFormat,GLenum _format,GLenum _contentType);
    void setTextureData(unsigned int _xoffset,unsigned int _yoffset,unsigned int _xlength,unsigned int _ylength,void* _data);

    void bind();
    void unbind();

    unsigned int getID();
    unsigned int getWidth();
    unsigned int getHeight();
    std::string getPath();

};


#endif