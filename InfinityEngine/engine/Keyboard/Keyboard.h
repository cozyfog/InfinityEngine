#pragma once

#include <base/typedef.h>
#include <GLFW/glfw3.h>

namespace Keyboard {
	bool isPressed(i32 key);
	void callback(GLFWwindow* window, i32 key, i32 scancode, i32 action, i32 mods);
};