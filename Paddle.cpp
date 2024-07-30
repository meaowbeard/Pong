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
}

void Paddle::Draw()
{
	DrawRectangleRounded(Rectangle{ X, Y, Width, Height }, 0.8, 0, WHITE);
	//std::cout << "X: " << X;
	//std::cout << " Y: " << Y << std::endl;

}

void Paddle::Update()
{
	if (IsKeyDown(KEY_UP))
	{
		Y = Y - Speed;
		//std::cout << "Update Called" << std::endl;
	}
	
	if (IsKeyDown(KEY_DOWN))
	{
		Y = Y + Speed;
	}
	
	LimitMovement();

	std::cout << GetScreenWidth() - Width - 10 << " X: ";
	std::cout << X << std::endl;
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