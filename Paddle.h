#pragma once

class Paddle {
public:
	float X;
	float Y;
	float Width;
	float Height;
	int Speed;

	Paddle();
	void Draw();
	void Update();

protected:
	void LimitMovement();
};