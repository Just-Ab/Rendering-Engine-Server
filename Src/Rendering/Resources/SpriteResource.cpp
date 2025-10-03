#include <Rendering/Resources/SpriteResource.h>




SpriteResource::SpriteResource(){
    vao.bind();

    vbo.bind();
    ebo.bind();
    
    vbo.setVertices(vertices,sizeof(vertices),GL_STATIC_DRAW);
    ebo.setIndices(indices);
    vao.linkAttribute(vbo,0,3,GL_FLOAT,0,5*sizeof(float),(void*)0);
    vao.linkAttribute(vbo,1,2,GL_FLOAT,0,5*sizeof(float),(void*)(3*sizeof(float)));
    vbo.unBind();
    ebo.unBind();
    vao.unBind();

}

void SpriteResource::bind(){
    vao.bind();
}

void SpriteResource::unbind(){
    vao.unBind();
}