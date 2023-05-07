#include <base/typedef.h>
#include <Transform/Transform.h>
#include <Texture/Texture.h>
#include "Entity.h"

Entity::Entity(std::string p_name, std::string p_tag) {
	name = p_name;
	tag = p_tag;
}

void Entity::onAwake() {
	return;
}

void Entity::onUpdate() {
	return;
}