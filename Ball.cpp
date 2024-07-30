#include "Ball.h"
#include "raylib.h"

void Ball::Draw()
{
	DrawCircle(X, Y, Radius, WHITE);
}

void Ball::Update(int& p1_score, int& p2_score)
{
	X += SpeedX;
	Y += SpeedY;

	if (Y + Radius >= GetScreenHeight() || Y - Radius <= 0) // PLAYER ONE WINS
	{
		SpeedY *= -1;
	}
	if (X + Radius >= GetScreenWidth()) // PLAYER TWO WINS
	{
		p2_score++;
		ResetBall();
	}
	if (X - Radius <= 0) 
	{
		p1_score++;
		ResetBall();
	}
}

void Ball::ResetBall()
{
	X = GetScreenWidth() / 2;
	Y = GetScreenHeight() / 2;

	int SpeedChoices[2] = { -1, 1 };

	SpeedX *= SpeedChoices[GetRandomValue(0, 1)];
	SpeedY *= SpeedChoices[GetRandomValue(0, 1)];
}

Ball::Ball(float x, float y, int speedX, int speedY, int radius)
{
	X = x;
	Y = y;
	SpeedX = speedX;
	SpeedY = speedY;
	Radius = radius;
}
