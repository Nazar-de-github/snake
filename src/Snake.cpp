#include "Snake.h"
#include "Map.h"
#include "Apple.h"
#include <iostream>
#include <windows.h>
#include <Xinput.h>

void Snake::move(Map &map, Apple &apple, DIRECTION Direction )
{
	Point endOfTail = body[body.size() - 1];
	for (size_t i = body.size() - 1; i > 0; i--)
		body[i] = body[i - 1];
	
	switch (Direction)
	{
	case Snake::DIRECTION::UP:
		body[0].y--;
		break;
	case Snake::DIRECTION::RIGHT:
		body[0].x++;
		break;
	case Snake::DIRECTION::DOWN:
		body[0].y++;
		break;
	case Snake::DIRECTION::LEFT:
		body[0].x--;
		break;
	}

	if (map[body[0].y][body[0].x] == map.getData().border)
	{
		if (map.getData().isBorderStrong)
			throw "Game Over";
		else
		{
			switch (Direction)
			{
			case Snake::DIRECTION::UP:
				body[0].y = map.getData().height - 2;
				break;
			case Snake::DIRECTION::RIGHT:
				body[0].x = 1;
				break;
			case Snake::DIRECTION::DOWN:
				body[0].y = 1;
				break;
			case Snake::DIRECTION::LEFT:
				body[0].x = map.getData().width - 2;
				break;
			}
		}
	}
	if (map[body[0].y][body[0].x] == TailSymbol)
		throw "Game Over";

	if (map[body[0].y][body[0].x] == apple.getSymbol())
	{
		score += apple.getValue();
		body.push_back(endOfTail);
		apple.setEaten(true);
	}
}

Snake::DIRECTION Snake::inputDirection()
{
	XINPUT_STATE state;
	ZeroMemory(&state, sizeof(XINPUT_STATE));

	if (GetAsyncKeyState('W') & 0b1 && Direction != DIRECTION::DOWN)
		Direction = DIRECTION::UP;
	else if (GetAsyncKeyState('A') & 0b1 && Direction != DIRECTION::RIGHT)
		Direction = DIRECTION::LEFT;
	else if (GetAsyncKeyState('D') & 0b1 && Direction != DIRECTION::LEFT)
		Direction = DIRECTION::RIGHT;
	else if (GetAsyncKeyState('S') & 0b1 && Direction != DIRECTION::UP)
		Direction = DIRECTION::DOWN;

	//SetKeyboardState(VK_ESCAPE);
	return Direction;
}

