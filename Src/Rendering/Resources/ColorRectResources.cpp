#include <Rendering/Resources/ColorRectResource.h>




ColorRectResource::ColorRectResource(){
    vao.bind();

    vbo.bind();
    ebo.bind();
    
    vbo.setVertices(vertices,sizeof(vertices),GL_STATIC_DRAW);
    ebo.setIndices(indices);
    vao.linkAttribute(vbo,0,3,GL_FLOAT,0,3*sizeof(float),0);
    vbo.unBind();
    ebo.unBind();

}

void ColorRectResource::bind(){
    vao.bind();
}

void ColorRectResource::unbind(){
    vao.unBind();
}