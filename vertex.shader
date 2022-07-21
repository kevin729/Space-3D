#version 330 core
layout(location = 0) in vec3 vertex;
layout(location = 1) in vec2 textureCo;
layout(location = 2) in vec3 normal;
out vec2 texcoords;
void main() 
{
	gl_Position = vec4(vertex, 1.0);
	texcoords = textureCo;
}
