#include "Paddle.h"
#include "raylib.h"
#include <iostream>

float SCREEN_WIDTH;
float SCREEN_HEIGHT;

Paddle::Paddle()
{
	SCREEN_WIDTH = GetScreenWidth();
	SCREEN_HEIGHT = GetScreenHeight();

	Width = 25;
	Height = 120;
	X = SCREEN_WIDTH - Width - 10;
	Y = SCREEN_HEIGHT / 2 - Height / 2;
	Speed = 6;

	UpKey = KEY_UP;
	DownKey = KEY_DOWN;
}

Paddle::Paddle(float x, float y, float width, float height, int speed, int upKey, int downKey)
	: X(x), Y(y), Width(width), Height(height), Speed(speed), UpKey(upKey), DownKey(downKey)
{
	SCREEN_WIDTH = GetScreenWidth();
	SCREEN_HEIGHT = GetScreenHeight();
}

void Paddle::Draw()
{
	DrawRectangleRounded(Rectangle{ X, Y, Width, Height }, 0.8, 0, WHITE);
}

void Paddle::Update()
{
	if (IsKeyDown(UpKey))
	{
		Y = Y - Speed;
		//std::cout << "Update Called" << std::endl;
	}

	if (IsKeyDown(DownKey))
	{
		Y = Y + Speed;
	}

	LimitMovement();
}

void Paddle::LimitMovement()
{
	if (Y <= 0)
	{
		Y = 0;
	}

	if (Y + Height >= GetScreenHeight())
	{
		Y = GetScreenHeight() - Height;
	}
}