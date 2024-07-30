#include <iostream>
#include "Ball.h"
#include "Paddle.h"
#include "AI_Paddle.h"
#include "raylib.h"

// TODO:
// SECOND PLAYER
// SCENE MANAGEMENT
// ????

const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 720;
const char WINDOW_NAME[] = "Pong";
const int TARGET_FPS = 60;

int PLAYER_ONE_SCORE = 0;
int PLAYER_TWO_SCORE = 0;

Color Green = Color{39, 185, 154, 255};
Color Dark_Green = Color{ 20, 160, 133, 255 };
Color Light_Green = Color{ 129, 204, 184, 255 };
Color Yellow = Color{ 243, 213, 91, 255 };

bool bIsCoOp = true;

int main()
{
	std::cout << "Starting the game" << std::endl;

	InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_NAME);
	SetTargetFPS(TARGET_FPS);

	Ball ball(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 7, 7, 20);
	Paddle p1_paddle;

		AI_Paddle CPU_Paddle;
		CPU_Paddle.Height = 120;
		CPU_Paddle.Width = 25;
		CPU_Paddle.X = 10;
		CPU_Paddle.Y = SCREEN_HEIGHT / 2 - CPU_Paddle.Height / 2;
		CPU_Paddle.Speed = 6;


	while (WindowShouldClose() == false)
	{
		BeginDrawing();

		// Updating
		ball.Update(PLAYER_ONE_SCORE, PLAYER_TWO_SCORE);
		p1_paddle.Update();
		CPU_Paddle.Update(ball.Y);

		// Check Collision
		if (CheckCollisionCircleRec(Vector2{ ball.X, ball.Y }, ball.Radius, Rectangle{ p1_paddle.X, p1_paddle.Y, p1_paddle.Width, p1_paddle.Height }))
		{
			ball.SpeedX *= -1;
			std::cout << "Hi";
		}

		if (CheckCollisionCircleRec(Vector2{ ball.X, ball.Y }, ball.Radius, Rectangle{ CPU_Paddle.X, CPU_Paddle.Y, CPU_Paddle.Width, CPU_Paddle.Height }))
		{
			ball.SpeedX *= -1;
		}

		// Drawing
		ClearBackground(Dark_Green);

		DrawRectangle(SCREEN_WIDTH / 2, 0, SCREEN_WIDTH / 2, SCREEN_HEIGHT, Green);
		DrawCircle(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 150, Light_Green);
		DrawLine(SCREEN_WIDTH / 2, 0, SCREEN_WIDTH / 2, SCREEN_HEIGHT, WHITE);

		ball.Draw();
		p1_paddle.Draw();
		CPU_Paddle.Draw();
		DrawText(TextFormat("%i",PLAYER_TWO_SCORE), SCREEN_WIDTH / 4 - 20, 20, 80, WHITE);
		DrawText(TextFormat("%i", PLAYER_ONE_SCORE), 3 * SCREEN_WIDTH / 4 - 20, 20, 80, WHITE);

		EndDrawing();
	}

	CloseWindow();
	return 0;
}