#include <gl/glew.h>
#include <GLFW/glfw3.h>
#include "Engine.h"
#include <vector>
#include <iostream>

void renderTest() {

	glBegin(GL_TRIANGLES);
	glVertex3f(0.0f, 1.0f, 0.0f);
	glVertex3f(-1.0f, -1.0f, 0.0f);
	glVertex3f(1.0f, -1.0f, 0.0f);
	glEnd();
}

void render() {
	const auto entities = getEntities();
	for (auto it = entities.begin(); it != entities.end(); ++it) {
		Entity entity = *it;
		Shader shader = getShaders()[0];

		glUseProgram(shader.program);
		glBindBuffer(GL_ARRAY_BUFFER, entity.vertexBuffer);
		glVertexAttribPointer(shader.vertexLocation, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
		
		glBindBuffer(GL_ARRAY_BUFFER, entity.textureCoBuffer);
		glVertexAttribPointer(shader.textureCoLocation, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)0);

		glBindBuffer(GL_ARRAY_BUFFER, entity.normalBuffer);
		glVertexAttribPointer(shader.normalLocation, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);

		
		glBindTexture(GL_TEXTURE_2D, entity.textureBuffer);
		glActiveTexture(GL_TEXTURE0);
		

		glEnableVertexAttribArray(shader.vertexLocation);
		glEnableVertexAttribArray(shader.textureCoLocation);
		glEnableVertexAttribArray(shader.normalLocation);

		glDrawArrays(GL_TRIANGLES, 0, entity.indicesLength);

		glDisableVertexAttribArray(shader.vertexLocation);
		glDisableVertexAttribArray(shader.textureCoLocation);
		glDisableVertexAttribArray(shader.normalLocation);

		glBindTexture(GL_ARRAY_BUFFER, entity.textureBuffer);
		glBindTexture(GL_TEXTURE_2D, entity.textureBuffer);
	}
}