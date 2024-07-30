#pragma once
#include "Scene.h"
#include "Button.h"

class MainMenuScene : public Scene
{
	public:
		Button SinglePlayerButton;
		Button CoOpButton;
		Button QuitButton;

		MainMenuScene();
		void Update() override;
		void Draw() override;
		void ResetScore() override;
};