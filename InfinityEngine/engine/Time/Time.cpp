#include <GLFW/glfw3.h>
#include "Time.h"

Time::Time() {
	return;
}

Time::~Time() {
	return;
}

void Time::calculateDeltaTime() {
	f32 current_time = glfwGetTime();
	this->delta_time = (current_time - this->last_time) * 60.0f;
	this->last_time = current_time;
}