#pragma once
#include "Paddle.h"

class AI_Paddle : public Paddle {
	public:
		void Update(int BallY)
		{
			if (Y + Height / 2 > BallY)
			{
				Y = Y - Speed;
			}
			if (Y + Height / 2 < BallY)
			{
				Y = Y + Speed;
			}
			LimitMovement();
		}
};