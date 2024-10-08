#include "SinglePlayerScene.h"
#include "raylib.h"
#include "SceneManager.h"
#include "Colors.h"
#include <iostream>

SinglePlayerScene::SinglePlayerScene()
    : ball(GetScreenWidth() / 2, GetScreenHeight() / 2, 7, 7, 20),
    p1_paddle(),
    CPU_Paddle()
{
    ResetScore();

    CPU_Paddle.Height = 120;
    CPU_Paddle.Width = 25;
    CPU_Paddle.X = 10;
    CPU_Paddle.Y = GetScreenHeight() / 2 - CPU_Paddle.Height / 2;
    CPU_Paddle.Speed = 6;

    countDownTime = 3;
    countDownTimer = 0.0f;
    bGameStarted = false;
}

void SinglePlayerScene::Update()
{
    if (IsKeyPressed(KEY_ESCAPE))
    {
        currentScene = mainMenuScene;
    }

    if (!bGameStarted)
    {
        countDownTimer += GetFrameTime();

        if (countDownTimer >= 1.0f)
        {
            countDownTimer = 0.0f;
            countDownTime--;
        }

        if (countDownTime <= 0)
        {
            bGameStarted = true;
        }

    }
    else
    {
        ball.Update(PLAYER_ONE_SCORE, PLAYER_TWO_SCORE);
        p1_paddle.Update();
        CPU_Paddle.Update(ball.Y);

        // Check Collision
        if (CheckCollisionCircleRec(Vector2{ ball.X, ball.Y }, ball.Radius, Rectangle{ p1_paddle.X, p1_paddle.Y, p1_paddle.Width, p1_paddle.Height })) {
            ball.SpeedX *= -1;
            PlaySound(ball.sfxPongOne);
        }

        if (CheckCollisionCircleRec(Vector2{ ball.X, ball.Y }, ball.Radius, Rectangle{ CPU_Paddle.X, CPU_Paddle.Y, CPU_Paddle.Width, CPU_Paddle.Height })) {
            ball.SpeedX *= -1;
            PlaySound(ball.sfxPongTwo);
        }
    }
}

void SinglePlayerScene::Draw()
{
    DrawRectangle(GetScreenWidth() / 2, 0, GetScreenWidth() / 2, GetScreenHeight(), BackgroundColorLeft);
    DrawCircle(GetScreenWidth() / 2, GetScreenHeight() / 2, 150, BackgroundCircleColor);
    DrawLine(GetScreenWidth() / 2, 0, GetScreenWidth() / 2, GetScreenHeight(), WHITE);

    ball.Draw();
    p1_paddle.Draw();
    CPU_Paddle.Draw();
    DrawText(TextFormat("%i", PLAYER_TWO_SCORE), GetScreenWidth() / 4 - 20, 20, 80, WHITE);
    DrawText(TextFormat("%i", PLAYER_ONE_SCORE), 3 * GetScreenWidth() / 4 - 20, 20, 80, WHITE);

    // Countdown Timer
    if (!bGameStarted)
    {
        DrawText(TextFormat("%i", countDownTime), GetScreenWidth() / 2 - 30, GetScreenHeight() / 2 - 50, 100, RED);
    }
}

void SinglePlayerScene::ResetScore()
{
    PLAYER_ONE_SCORE = 0;
    PLAYER_TWO_SCORE = 0;

    countDownTime = 3;
    countDownTimer = 0.0f;
    bGameStarted = false;
}