#version 460 core
in vec3 color;
in vec2 textureCoord;

out vec4 FragColor;

uniform sampler2D finalTexture;

void main()
{
//    FragColor=vec4(color,1.0);
   FragColor=texture(finalTexture,textureCoord);
}