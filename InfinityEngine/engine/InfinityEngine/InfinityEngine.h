#pragma once

#include <base/typedef.h>
#include <Window/Window.h>
#include <Time/Time.h>
#include <Renderer/Renderer.h>
#include <Logging/Logging.h>
#include <Camera/Camera.h>
#include <Keyboard/Keyboard.h>

struct Application {
	Window window;
	Time time;
	Renderer renderer;
	Camera camera;

	void onAwake();
	void onStart();
	void onUpdate();
};