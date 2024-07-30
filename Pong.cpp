#include <iostream>
#include "SceneManager.h"
#include "Ball.h"
#include "Paddle.h"
#include "AI_Paddle.h"
#include "Scene.h"
#include "MainMenuScene.h"
#include "SinglePlayerScene.h"
#include "CoOpScene.h"
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

Color Green = Color{ 23, 21, 59, 255};
Color BackgroundColor = Color{ 2, 21, 38, 255 };
Color Light_Green = Color{ 67, 61, 139, 255 };
Color Yellow = Color{ 243, 213, 91, 255 };

int main()
{
	std::cout << "Starting the game" << std::endl;

	InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_NAME);
	SetTargetFPS(TARGET_FPS);

	// Initialize Scenes
	mainMenuScene = new MainMenuScene();
	singlePlayerScene = new SinglePlayerScene();
	coOpScene = new CoOpScene();

	currentScene = mainMenuScene;

	while (WindowShouldClose() == false && currentScene != nullptr)
	{
		BeginDrawing();
		
		if (currentScene != nullptr)
		{
			currentScene->Update();
		}

		// Drawing
		
		ClearBackground(BackgroundColor);
		if (currentScene != nullptr)
		{
			currentScene->Draw();
		}

		EndDrawing();
	}

	delete mainMenuScene;
	delete singlePlayerScene;
	delete coOpScene;

	CloseWindow();
	return 0;
}