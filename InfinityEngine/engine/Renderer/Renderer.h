#pragma once

#include <base/typedef.h>
#include <GL/glew.h>
#include <packt/Shader.h>
#include <Entity/Entity.h>
#include <Camera/Camera.h>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>

struct Renderer {
	Renderer();
	~Renderer();

	u32 vao;
	u32 vbo;
	u32 ebo;
	Shader shader;

	void clear();
	void init();
	void drawEntity(Camera &camera, Entity &entity);
};