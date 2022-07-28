#version 330 core
in vec3 vertex;
in vec2 textureCo;
in vec3 normal;

uniform mat4 projection;
uniform mat4 view;
uniform mat4 transform;

out vec2 textureCoords;
void main() 
{
	gl_Position = projection * view * transform * vec4(vertex, 1.0);
	textureCoords = textureCo;
}
