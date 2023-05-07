#include <base/typedef.h>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <Transform/Transform.h>
#include "Camera.h"

Camera::Camera() {
	return;
}

Camera::~Camera() {
	return;
}

Mat4 Camera::getProjectionMatrix() {
	Vec2 c_viewport = viewport * Vec2(0.5f);

	return glm::ortho(
		-c_viewport.x + transform.position.x,
		 c_viewport.x + transform.position.x,
		 c_viewport.y + transform.position.y,
		-c_viewport.y + transform.position.y,
		 view_distnce, transform.position.z
	);
}