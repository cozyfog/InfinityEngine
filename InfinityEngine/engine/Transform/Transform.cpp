#include <base/typedef.h>
#include "Transform.h"

Transform::Transform() {
	position = Vec3(0.0f, 0.0f, 0.0f);
	scale = Vec3(1.0f, 1.0f, 1.0f);
	rotation = Vec4(0.0f, 0.0f, 0.0f, 0.0f);
}

Transform::Transform(Vec3 p_position, Vec3 p_scale, Vec4 p_rotation) {
	position = p_position;
	scale = p_scale;
	rotation = p_rotation;
}

Transform::~Transform() {
	return;
}