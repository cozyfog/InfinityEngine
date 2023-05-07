#include "InfinityEngine.h"

i32 main() {
	Application app = Application();

	app.onAwake();
	app.renderer.init();
	app.onStart();

	while (!app.window.getGlfwShouldClose()) {
		glClearColor(app.camera.sky_color.x, app.camera.sky_color.y, app.camera.sky_color.z, 1.0f);
		app.renderer.clear();
		app.time.calculateDeltaTime();
		app.renderer.shader.use();
		app.onUpdate();
		app.window.update();
	}

	glfwTerminate(); // Terminate GLFW aswell as it's context window.

	return 0;	// Not needed, but it's a habbit from C programming. :)
}