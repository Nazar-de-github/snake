#pragma once
#pragma once
#ifndef MAP
#define MAP
#include <vector>
#include <string>
#include "Tools.h"

class Snake;
class Apple;


class Map
{
	struct DATA{
		int height = 25;
		int width = 50;
		char border = '#';
		char wall = 'w';
		bool isBorderStrong = true;
	}Data;
	
	std::vector<std::string>map;

	void erase();

public:
	Map() {
		for (int i = 0; i <= Data.height; i++)
			map.push_back(std::string(Data.width, ' '));
	}

	const std::string& operator [] (int i)const;

	void init();
	void show();
	void putSnake(Snake snake);
	void putApple(Apple &apple);
	const DATA& getData()const { return Data; }
	std::vector<Point> getEmptyPos()const;
};

#endif