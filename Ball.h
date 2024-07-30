#pragma once

class Ball {
public:
	float X;
	float Y;
	int SpeedX;
	int SpeedY;
	int Radius;

	Ball(float x, float y, int speedX, int speedY, int radius);
	void Draw();
	void Update(int& p1_score, int& p2_score);
	void ResetBall();
};