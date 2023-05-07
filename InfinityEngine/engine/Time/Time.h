#pragma once

#include <base/typedef.h>

class Time {
private:
	f32 last_time = 0.0f;	// Variable for the calculation of the deltaTime variable.
public:
	Time();
	~Time();

	f32 delta_time;

	void calculateDeltaTime();
};