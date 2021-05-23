#version 460 core
in vec2 textureCoord;

out vec4 FragColor;

uniform sampler2D sampler1;
uniform sampler2D sampler2;

void main()
{
   FragColor=vec4(0.5,0.0,0.0,1);
}