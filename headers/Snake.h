#pragma once
#ifndef SNAKE
#define SNAKE

#include <vector>
#include "Tools.h"


class Map;
class Apple;


class Snake
{
public:

	enum DIRECTION {
		UP, RIGHT, DOWN, LEFT, NONE
	};
	const char TailSymbol = 'o';
	const char HeadSymbol = 'O';
private:

	int score = 0;
	bool selfDestruction = true;
	std::vector<Point> body;
	
	
	DIRECTION Direction;
	

public:
	Snake() : Direction(DIRECTION::NONE) { body.push_back({ 10,10 }); }
	Snake(int x, int y) : Direction(DIRECTION::NONE) { body.push_back({ x,y }); }
	void move(Map &map, Apple &apple, DIRECTION Direction);
	DIRECTION inputDirection();
	int getScore() { return score; }

	std::vector<Point> getBody() const { return body; }
};


#endif // !SNAKE