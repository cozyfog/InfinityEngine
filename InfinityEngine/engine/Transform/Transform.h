#pragma once

#include <base/typedef.h>

struct Transform {
	Transform();
	Transform(Vec3 p_position, Vec3 p_scale, Vec4 p_rotation);
	~Transform();

	Vec3 position;
	Vec3 scale;
	Vec4 rotation;

	Vec3 up = Vec3(0.0f, 1.0f, 0.0f);
	Vec3 forward = Vec3(0.0f, 0.0f, 1.0f);
	Vec3 right = Vec3(1.0f, 0.0f, 0.0f);
};