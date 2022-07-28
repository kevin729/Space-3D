#include <gl/glew.h>
#include <GLFW/glfw3.h>
#include "Engine.h"
#include <vector>
#include <iostream>
#include <glm/mat4x4.hpp>
#include <glm/vec3.hpp> // glm::vec3
#include <glm/vec4.hpp> // glm::vec4
#include <glm/mat4x4.hpp> // glm::mat4
#include <glm/ext/matrix_transform.hpp> // glm::translate, glm::rotate, glm::scale
#include <glm/ext/matrix_clip_space.hpp> // glm::perspective
#include <glm/ext/scalar_constants.hpp> // glm::pi
#include <glm/gtc/type_ptr.hpp>

void loadTransform(Shader shader) {
	glm::mat4 projection, view, transform;
	projection = glm::perspective(glm::radians(90.0f), (float)getScreenWidth() / (float)getScreenWidth(), 0.1f, 10.0f);
	transform *= glm::translate(transform, glm::vec3(0, 0, -5));
	transform *= glm::scale(transform, glm::vec3(1.0f, 1.0f, 1.0f));
	

	glUniformMatrix4fv(shader.projectionLocation, 1, GL_FALSE, glm::value_ptr(projection));
	glUniformMatrix4fv(shader.viewLocation, 1, GL_FALSE, glm::value_ptr(view));
	glUniformMatrix4fv(shader.transformLocation, 1, GL_FALSE, glm::value_ptr(transform));

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

		loadTransform(shader);
		glUniform1i(shader.texture1Location, 0);
		glUniform1i(shader.texture2Location, 1);
		
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, entity.textureBuffer);
		glActiveTexture(GL_TEXTURE1);
		glBindTexture(GL_TEXTURE_2D, entity.overlayTextureBuffer);
		
		glEnableVertexAttribArray(shader.vertexLocation);
		glEnableVertexAttribArray(shader.textureCoLocation);
		glEnableVertexAttribArray(shader.normalLocation);

		glDrawArrays(GL_TRIANGLES, 0, entity.indicesLength);

		glDisableVertexAttribArray(shader.vertexLocation);
		glDisableVertexAttribArray(shader.textureCoLocation);
		glDisableVertexAttribArray(shader.normalLocation);

		glBindTexture(GL_ARRAY_BUFFER, 0);
		glBindTexture(GL_TEXTURE_2D, 0);
		glUseProgram(0);
	}
}