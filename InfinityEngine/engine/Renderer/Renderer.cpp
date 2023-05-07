#include <base/typedef.h>
#include <GL/glew.h>
#include <packt/Shader.h>
#include <Entity/Entity.h>
#include <Camera/Camera.h>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "Renderer.h"

f32 vertices[] = {
	 0.5f,  0.5f, 0.0f,		1.0f, 1.0f, 1.0f,		0.0f, 0.0f,
	 0.5f, -0.5f, 0.0f,		1.0f, 1.0f, 1.0f,		0.0f, 1.0f,
	-0.5f, -0.5f, 0.0f,		1.0f, 1.0f, 1.0f,		1.0f, 1.0f,
	-0.5f,  0.5f, 0.0f,		1.0f, 1.0f, 1.0f,		1.0f, 0.0f,
};

u32 indices[] = {
	0, 1, 3,
	1, 2, 3,
};

Renderer::Renderer() {
	return;
}

Renderer::~Renderer() {
	glDeleteVertexArrays(1, &vao);
	glDeleteBuffers(1, &vbo);
	glDeleteBuffers(1, &ebo);
}

void Renderer::clear() {
	glClear(GL_COLOR_BUFFER_BIT);
}

void Renderer::init() {
	glGenVertexArrays(1, &vao);
	glGenBuffers(1, &vbo);
	glGenBuffers(1, &ebo);

	glBindVertexArray(vao);

	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(GLfloat)));
	glEnableVertexAttribArray(1);

	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(GLfloat)));
	glEnableVertexAttribArray(2);

	glBindVertexArray(0);
}

void Renderer::drawEntity(Camera &camera, Entity &entity) {
	shader.use();

	i32 u_projLoc = glGetUniformLocation(shader.Program, "u_proj");
	glUniformMatrix4fv(u_projLoc, 1, GL_FALSE, glm::value_ptr(camera.getProjectionMatrix()));

	i32 u_modelLoc = glGetUniformLocation(shader.Program, "u_model");
	Mat4 model = Mat4(1.0f);
	model = glm::translate(model, Vec3(1.0f) * entity.transform.position);
	model = glm::rotate(model, glm::radians(entity.transform.rotation.x), Vec3(1.0f, 0.0f, 0.0f));
	model = glm::rotate(model, glm::radians(entity.transform.rotation.y), Vec3(0.0f, 1.0f, 0.0f));
	model = glm::rotate(model, glm::radians(entity.transform.rotation.z), Vec3(0.0f, 0.0f, 1.0f));
	model = glm::scale(model, entity.transform.scale);
	glUniformMatrix4fv(u_modelLoc, 1, GL_FALSE, glm::value_ptr(model));

	entity.texture.use();
	glUniform1i(glGetUniformLocation(shader.Program, "ourTexture"), 0);
	glBindVertexArray(vao);

	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

	glBindVertexArray(0);
}