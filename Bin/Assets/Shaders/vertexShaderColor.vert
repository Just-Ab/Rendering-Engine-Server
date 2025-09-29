#version 330 core 

layout (location=0) in vec3 apos;
layout (location=1) in mat4 model;


layout (std140) uniform matrices
{
    mat4 projection;
    mat4 view;
};

uniform vec3 color;

out vec3 vertexColor;
void main(){
    gl_Position = projection*view*model*vec4(apos,1.0f);
    vertexColor = color;
}




