#version 330 core

in vec2 textureCoords;
uniform sampler2D tex;
out vec4 color;

void main() {
	vec4 texture = texture(tex, textureCoords);
	
	if (texture.a == 0) {
		discard;
	}

	color = texture;
	color = vec4(0+textureCoords.x, 0.2+textureCoords.y, 9, 1);
}
