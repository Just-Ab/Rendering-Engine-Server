#version 330 core 

layout (location=0) in vec3 apos;
layout (location=1) in vec2 texel;
layout (location=2) in mat4 model;
layout (location=6) in mat4 model2;


layout (std140) uniform matrices
{
    mat4 projection;
    mat4 view;
};

out vec2 vertexTexel;

void main(){
    gl_Position = projection*view*model*vec4(apos,1.0f);
    vertexTexel = texel;
}




