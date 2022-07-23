#version 330 core
in vec3 vertex;
in vec2 textureCo;
in vec3 normal;
void main() 
{
	gl_Position = vec4(vertex, 1.0);
}
