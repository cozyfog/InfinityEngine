#include <base/typedef.h>
#include <GL/glew.h>
#include <stb/stb_image.h>
#include "Texture.h"

Texture::Texture() {
	return;
}

Texture::~Texture() {
	return;
}

void Texture::load(const char *filename, bool has_alpha) {
	unsigned char *data = stbi_load(filename, &width, &height, &channels, 0);

	glGenTextures(1, &id);
	glBindTexture(GL_TEXTURE_2D, id);

	if (!has_alpha)
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
	else
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
}

void Texture::use() {
	glBindTexture(GL_TEXTURE_2D, id);
}