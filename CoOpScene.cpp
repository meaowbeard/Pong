#include "CoOpScene.h"
#include "raylib.h"
#include "SceneManager.h"

void CoOpScene::Update()
{
    // Add co-op game logic here
    if (IsKeyPressed(KEY_ESCAPE)) {
        currentScene = mainMenuScene;
    }
}

void CoOpScene::Draw()
{
}
