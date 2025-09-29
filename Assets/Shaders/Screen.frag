#version 330 core


out vec4 FragColor;

in vec3 vertexPosition;
in vec2 vertexTexel;

uniform sampler2D imageSample;



void main(){
    vec3 data = texture(imageSample,vec2(vertexTexel.x,1-vertexTexel.y)).rgb;
    FragColor = vec4(data,1.0f);
}