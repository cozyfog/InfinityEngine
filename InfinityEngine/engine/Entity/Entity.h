#pragma once

#include <base/typedef.h>
#include <Transform/Transform.h>
#include <Texture/Texture.h>

struct Entity {
	Entity(std::string name, std::string tag);
	~Entity() {};

	std::string name;
	std::string tag;
	Transform transform;
	Texture texture;

	void onAwake();
	void onUpdate();
};
