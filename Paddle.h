#pragma once

class Paddle {
public:
	float X;
	float Y;
	float Width;
	float Height;
	int Speed;

	Paddle();

	// For Co-Op
	Paddle(float x, float y, float width, float height, int speed, int upKey, int downKey);

	void Draw();
	void Update();

protected:
	void LimitMovement();

private:
	int UpKey;
	int DownKey;
};