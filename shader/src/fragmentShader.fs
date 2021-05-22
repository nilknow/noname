#version 460 core
in vec3 color;
in vec2 textureCoord;

out vec4 FragColor;

uniform sampler2D sampler1;
uniform sampler2D sampler2;

void main()
{
   FragColor=mix(texture(sampler1,textureCoord),texture(sampler2,textureCoord),0.2);
}