#version 330 core 

out vec4 FragColor;

in vec2 vertexTexel;
uniform sampler2D texture2d;

void main(){




    FragColor = texture(texture2d,vertexTexel);
}




