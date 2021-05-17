#version 460 core
layout (location = 0) in vec3 pos;
layout (location = 1) in vec3 inColor;
layout (location = 2) in vec2 inputTextureCoord;

out vec3 color;
out vec2 textureCoord;

uniform mat4 transform;

void main()
{
    //gl_Position=vec4(pos.x,pos.y,pos.z,1.0);
    color=inColor;
    gl_Position=transform * vec4(pos,1.0f);
    textureCoord=inputTextureCoord;
}