#pragma once

#include <base/typedef.h>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <Transform/Transform.h>

struct Camera {
	Camera();
	~Camera();

	Transform transform = Transform(Vec3(0.0f, 0.0f, -10.0f), Vec3(1.0f, 1.0f, 1.0f), Vec4(0.0f, 0.0f, 0.0f, 0.0f));
	Vec2 viewport = Vec2(1.0f, 1.0f);
	Vec3 sky_color = Vec3(0.2f, 0.3, 0.4f);
	f32 view_distnce = 10.0f;

	Mat4 getProjectionMatrix();
};