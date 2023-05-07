#pragma once

#include <base/typedef.h>
#include <GL/glew.h>
#include <stb/stb_image.h>

class Texture {
private:
	i32 channels;
public:
	Texture();
	~Texture();

	u32 id;
	i32 width;
	i32 height;

	void load(const char *filename, bool has_alpha = true);
	void use();
};