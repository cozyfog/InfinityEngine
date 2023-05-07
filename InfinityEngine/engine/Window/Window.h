#pragma once

#include <base/typedef.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <imgui/imgui.h>
#include <imgui/imgui_impl_glfw.h>
#include <imgui/imgui_impl_opengl3.h>
#include <Keyboard/Keyboard.h>

class Window {
private:
	i32 width;
	i32 height;
	const char *title;
	GLFWwindow *window;
public:
	Window(const char *title, i32 width, i32 height);
	Window();
	~Window();

	void update();
	void changeTitle(const char *new_title);

	// THIS FUNCTION IS MET FOR RESTRICTED BACKEND USAGE INSIDE THE ENGINE.
	GLFWwindow *getGlfwWindow();

	// THIS FUNCTION IS MET FOR RESTRICTED BACKEND USAGE INSIDE THE ENGINE.
	bool getGlfwShouldClose();
};