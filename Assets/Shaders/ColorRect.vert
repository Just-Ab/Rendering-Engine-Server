#version 330 core

layout (location=0) in vec3 apos;

out vec3 fragColor;

uniform vec3 position;
uniform vec3 color;
void main(){
    gl_Position = vec4(apos+position,1.0f);
    fragColor = color;
}