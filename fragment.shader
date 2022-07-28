#version 330 core

in vec2 textureCoords;
uniform sampler2D tex1;
uniform sampler2D tex2;
out vec4 color;

void main() {
	vec4 texture1 = texture(tex1, textureCoords);
	vec4 texture2 = texture(tex2, textureCoords);
	if (texture1.a == 0) {
		discard;
	}
	color = texture2D(tex2, textureCoords);
}
