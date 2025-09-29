#version 330 core

layout (location = 0) in vec3 vertpos;
layout (location = 1) in vec2 vertexel;
layout (location = 2) in vec2 shift;
layout (std140) uniform matrices{
    mat4 projection;
    mat4 view;
};


out vec2 fragtexel;


void main(){
    gl_Position = projection*view*vec4(vertpos.xy+shift,1.0f,1.0f);
    fragtexel = vertexel;
}