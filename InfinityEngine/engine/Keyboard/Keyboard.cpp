#include <base/typedef.h>
#include <GLFW/glfw3.h>
#include "Keyboard.h"

i32 keys[256] = { 0 };

bool Keyboard::isPressed(i32 key) {
	return keys[key];
}

void Keyboard::callback(GLFWwindow* window, i32 key, i32 scancode, i32 action, i32 mods) {
	keys[key] = !keys[key];
}
