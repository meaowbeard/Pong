#include "CoOpScene.h"
#include "raylib.h"
#include "SceneManager.h"
#include "Colors.h"
#include <iostream>

CoOpScene::CoOpScene()
    : ball(GetScreenWidth() / 2, GetScreenHeight() / 2, 7, 7, 20),
    p1_paddle(GetScreenWidth() - 35, GetScreenHeight() / 2 - 60, 25, 120, 6, KEY_UP, KEY_DOWN),
    p2_paddle(10, GetScreenHeight() / 2 - 60, 25, 120, 6, KEY_W, KEY_S) 
{
    ResetScore();

    countDownTime = 3;
    countDownTimer = 0.0f;
    bGameStarted = false;
}

void CoOpScene::Update()
{
    if (IsKeyPressed(KEY_ESCAPE)) {
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
        p2_paddle.Update();

        if (CheckCollisionCircleRec(Vector2{ ball.X, ball.Y }, ball.Radius, Rectangle{ p1_paddle.X, p1_paddle.Y, p1_paddle.Width, p1_paddle.Height })) {
            ball.SpeedX *= -1;
            PlaySound(ball.sfxPongOne);
        }

        if (CheckCollisionCircleRec(Vector2{ ball.X, ball.Y }, ball.Radius, Rectangle{ p2_paddle.X, p2_paddle.Y, p2_paddle.Width, p2_paddle.Height })) {
            ball.SpeedX *= -1;
            PlaySound(ball.sfxPongTwo);
        }
    }

}

void CoOpScene::Draw() {
    ClearBackground(BackgroundColorRight);
    DrawRectangle(GetScreenWidth() / 2, 0, GetScreenWidth() / 2, GetScreenHeight(), BackgroundColorLeft);
    DrawCircle(GetScreenWidth() / 2, GetScreenHeight() / 2, 150, BackgroundCircleColor);
    DrawLine(GetScreenWidth() / 2, 0, GetScreenWidth() / 2, GetScreenHeight(), WHITE);

    ball.Draw();
    p1_paddle.Draw();
    p2_paddle.Draw();
    DrawText(TextFormat("%i", PLAYER_ONE_SCORE), 3 * GetScreenWidth() / 4 - 20, 20, 80, WHITE); 
    DrawText(TextFormat("%i", PLAYER_TWO_SCORE), GetScreenWidth() / 4 - 20, 20, 80, WHITE);

    // Countdown Timer
    if (!bGameStarted)
    {
        DrawText(TextFormat("%i", countDownTime), GetScreenWidth() / 2 - 30, GetScreenHeight() / 2 - 50, 100, RED);
    }

}

void CoOpScene::ResetScore()
{
    PLAYER_ONE_SCORE = 0;
    PLAYER_TWO_SCORE = 0;

    countDownTime = 3;
    countDownTimer = 0.0f;
    bGameStarted = false;
}