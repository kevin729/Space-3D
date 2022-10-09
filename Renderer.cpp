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

void loadTransform(Shader shader, Entity& entity) {
	Camera camera = *getCamera();
	glm::mat4 projection, view, translate;
	projection = glm::perspective(glm::radians(90.0f), (float)getScreenWidth() / (float)getScreenHeight(), 0.1f, 10.0f);
	translate = glm::translate(glm::mat4(1.f), glm::vec3(entity.x, entity.y, entity.z));
	translate *= glm::rotate(glm::mat4(1.f), entity.rotation[0] * 3.14159f/180, glm::vec3(1, 0, 0));
	translate *= glm::rotate(glm::mat4(1.f), entity.rotation[1] * 3.14159f / 180, glm::vec3(0, 1, 0));
	translate *= glm::rotate(glm::mat4(1.f), entity.rotation[2] * 3.14159f / 180, glm::vec3(0, 0, 1));
	translate *= glm::scale(glm::mat4(1.f), glm::vec3(entity.scale[0], entity.scale[1], entity.scale[2]));
	view = glm::lookAt(glm::vec3(camera.x, camera.y, 0), glm::vec3(camera.x, camera.y, -1), glm::vec3(0, 1, 0));
	glUniformMatrix4fv(shader.projectionLocation, 1, GL_FALSE, glm::value_ptr(projection));
	glUniformMatrix4fv(shader.viewLocation, 1, GL_FALSE, glm::value_ptr(view));
	glUniformMatrix4fv(shader.transformLocation, 1, GL_FALSE, glm::value_ptr(translate));

	//glm::vec3(0.5, -0.5, 0), glm::vec3(0.5, -0.5, -1)
}

void render() {
	const auto entities = getEntities();
	for (auto it = entities.begin(); it != entities.end(); ++it) {
		Entity entity = **it;
		Shader shader = getShaders()[0];

		glUseProgram(shader.program);
		
		glBindBuffer(GL_ARRAY_BUFFER, entity.vertexBuffer);
		glVertexAttribPointer(shader.vertexLocation, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
		
		glBindBuffer(GL_ARRAY_BUFFER, entity.textureCoBuffer);
		glVertexAttribPointer(shader.textureCoLocation, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)0);

		glBindBuffer(GL_ARRAY_BUFFER, entity.normalBuffer);
		glVertexAttribPointer(shader.normalLocation, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);

		loadTransform(shader, entity);
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