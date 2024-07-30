#pragma once
#include "raylib.h"

class Button {
	public:
		Rectangle Rect;
		const char* ButtonText;
		Color ButtonColor;
		Color HoverColor;
		Color TextColor;

		Button(float x, float y, float width, float height, const char* text);
		void Draw();
		bool IsClicked();
};