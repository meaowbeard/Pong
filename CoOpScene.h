#pragma once
#include "Scene.h"
#include "Ball.h"
#include "AI_Paddle.h"

class CoOpScene : public Scene {
public:
    Ball ball;
    Paddle p1_paddle;
    Paddle p2_paddle;

    int PLAYER_ONE_SCORE;
    int PLAYER_TWO_SCORE;

    CoOpScene();

    void Update() override;
    void Draw() override;
    void ResetScore() override;

    // Countdown Variables
    int countDownTime;
    float countDownTimer;
    bool bGameStarted;

};