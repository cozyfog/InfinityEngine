#include <base/typedef.h>
#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <imgui/imgui.h>
#include <imgui/imgui_impl_glfw.h>
#include <imgui/imgui_impl_opengl3.h>
#include <Keyboard/Keyboard.h>
#include "Window.h"

Window::Window(const char *title, i32 width, i32 height) {
	if (!glfwInit())
		std::cout << "GLFW Initialization failed. ---- GL_ERROR: " << glGetError() << std::endl;

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, false);
	glfwWindowHint(GLFW_RESIZABLE, false);

	this->title = title;
	this->width = width;
	this->height = height;

	window = glfwCreateWindow(width, height, title, NULL, NULL);
	if (!window) {
		std::cout << "GLEW Window creation failed. ---- GL_ERROR: " << glGetError() << std::endl;
		glfwTerminate();
	}

	glfwMakeContextCurrent(window);

	glfwSetKeyCallback(window, Keyboard::callback);

	if (glewInit() != GLEW_OK)
		std::cout << "GLEW Initialization failed. ---- GL_ERROR: " << glGetError() << std::endl;

	ImGui::CreateContext();
	ImGui_ImplGlfw_InitForOpenGL(window, true);
	ImGui_ImplOpenGL3_Init("#version 330");
}

Window::Window() {
	return;
}

Window::~Window() {
	return;
}

void Window::update() {
	glfwSwapBuffers(window);
	glfwPollEvents();
}

void Window::changeTitle(const char *new_title) {
	this->title = new_title;
	glfwSetWindowTitle(window, new_title);
}

GLFWwindow *Window::getGlfwWindow() {
	return this->window;
}

bool Window::getGlfwShouldClose() {
	return glfwWindowShouldClose(this->window);
}