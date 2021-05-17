#version 460 core
in vec3 color;
in vec2 textureCoord;

out vec4 FragColor;

uniform sampler2D sampler;

void main()
{
   FragColor=texture(sampler,textureCoord)*vec4(color,1.0);
}