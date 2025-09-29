#version 330 core

layout (location=0) in vec3 position;
layout (location=1) in vec2 texel;


layout (std140) uniform matrices{
    mat4 projection;
    mat4 view;
};

out vec3 vertexPosition;
out vec2 vertexTexel;

void main(){
    gl_Position = projection*view*vec4(position,1.0f);
    vertexPosition = position;
    vertexTexel = texel;
}