#include <Rendering/ColorRect.h>



ColorRect::ColorRect(){
    vertices = PrimitiveShapes::ColorQuad.vertices;
    indices = PrimitiveShapes::ColorQuad.indices;

    setup();
}

void ColorRect::setup(){
    vao.bind();
    vbo.setVertices(vertices);
    EBO ebo(indices);
    vao.unBind();
}

void ColorRect::setColor(float _r,float _g,float _b,float _a){
    color = {_r,_g,_b,_a};
}
void ColorRect::setColor(fColor _color,float _a){
    color = {_color.R,_color.G,_color.B,_a};
}


void ColorRect::draw(Shader& shader,unsigned int instances){
    shader.activate();
    shader.setVec3("color",glm::vec3(color.R,color.G,color.B));
    vao.bind();
    if (instances>0){
        glDrawElementsInstanced(GL_TRIANGLES,indices.size(),GL_UNSIGNED_INT,0,instances);
    }
    vao.unBind();
    shader.disactivate();
}


void ColorRect::draw(Shader& shader,std::vector<ColorRectDataInstance>& instances){
    unsigned int instancesCount = instances.size();
    shader.activate();
    // shader.setVec3("color",glm::vec3(color.R,color.G,color.B));
    vao.bind();
    if (instancesCount>0){
        instanceVbo.setInstances(instances);
        glDrawElementsInstanced(GL_TRIANGLES,indices.size(),GL_UNSIGNED_INT,0,instancesCount);
    }
    vao.unBind();
    shader.disactivate();
}
