#version 330 core

layout (location = 0) in vec3 apos;
layout (location = 1) in vec2 atexel;



out vec2 fragtexel;

uniform vec3 position;
uniform mat4 projection;
uniform mat4 view;

void main(){
    gl_Position = projection*view*vec4(apos+position,1.0f);
    fragtexel = atexel;
}