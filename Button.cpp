#include "Button.h"
#include <iostream>

Button::Button(float x, float y, float width, float height, const char* text)
{
	Rect = { x, y, width, height };
	this->ButtonText = text;
	ButtonColor = DARKGRAY;
	HoverColor = GRAY;
	TextColor = WHITE;
}

void Button::Draw()
{
	Color CurrentColor = CheckCollisionPointRec(GetMousePosition(), Rect) ? HoverColor : ButtonColor;
	DrawRectangleRec(Rect, CurrentColor);
	DrawText(ButtonText, Rect.x + (Rect.width - MeasureText(ButtonText, 20)) / 2, Rect.y + (Rect.height - 20) / 2, 20, TextColor);

}

bool Button::IsClicked()
{
	return CheckCollisionPointRec(GetMousePosition(), Rect) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT);
}
