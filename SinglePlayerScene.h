#pragma once
#include "Scene.h"
#include "Ball.h"
#include "Paddle.h"
#include "AI_Paddle.h"

class SinglePlayerScene : public Scene
{
	public:
		Ball ball;
		Paddle p1_paddle;
		AI_Paddle CPU_Paddle;

		int PLAYER_ONE_SCORE;
		int PLAYER_TWO_SCORE;

		SinglePlayerScene();

		void Update() override;
		void Draw() override;
		void ResetScore() override;

		// Countdown Variables
		int countDownTime;
		float countDownTimer;
		bool bGameStarted;
};