#include "MainMenuScene.h"
#include "SceneManager.h"
#include <iostream>


MainMenuScene::MainMenuScene() :
	SinglePlayerButton(540, 300, 200, 50, "Single Player"),
	CoOpButton(540, 370, 200, 50, "Co-Op"),
	QuitButton(540, 440, 200, 50, "Quit Game")
{

}

void MainMenuScene::Update()
{
	if (SinglePlayerButton.IsClicked())
	{
		currentScene = singlePlayerScene;
		std::cout << "Single Player Button Clicked";
	}
	if (CoOpButton.IsClicked())
	{
		currentScene = coOpScene;
	}
	if (QuitButton.IsClicked())
	{
		currentScene = nullptr;
	}
}

void MainMenuScene::Draw()
{
	DrawText("Crazy Ball", GetScreenWidth() / 2 - MeasureText("Main Menu", 40) / 2, 150, 40, WHITE);
	
	SinglePlayerButton.Draw();
	CoOpButton.Draw();
	QuitButton.Draw();
}



