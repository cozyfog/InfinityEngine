#include <InfinityEngine/InfinityEngine.h>

std::vector<Entity> level_items;

Entity player = Entity("Player", "Player");

void Application::onAwake() {
	window = Window("hello world", 1280, 720);
	camera.viewport = Vec2(256, 144);
	camera.sky_color = Vec4(0.0f, 0.0f, 0.0f, 1.0f);
	renderer.shader = Shader("engine/shader/vertex.shader", "engine/shader/fragment.shader");
}

void Application::onStart() {
	player.texture.load("res/player.png", true);
	player.transform.scale = Vec3(14.0f, 16.0f, 0.0f);
}

void Application::onUpdate() {
	player.transform.position.x += 5 * Keyboard::isPressed('D') * time.delta_time;

	renderer.drawEntity(camera, player);
}