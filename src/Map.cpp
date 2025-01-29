#include "Map.h"
#include "Snake.h"
#include "Apple.h"
#include <iostream>

void Map::erase()
{
	for (int i = 0; i < Data.height; i++)
		for (int j = 0; j < Data.width; j++)
			map[i][j] = ' ';
}

const std::string& Map::operator[](int i)const
{
	return map[i];
}

void Map::init()
{
	erase();
	for (int i = 0; i < Data.height; i++)
		map[i][0] = map[i][Data.width - 1] = Data.border;

	map[0].assign(Data.width, Data.border);
	map[Data.height - 1].assign(Data.width, Data.border);
}

void Map::show()
{
	for (int i = 0; i < Data.height; i++)
		std::cout << map[i]<<"\n";
}


void Map::putSnake(Snake snake)
{
	for (int i = snake.getBody().size()-1; i > 0 ; i--)
	{
		map[snake.getBody().at(i).y][snake.getBody().at(i).x] = snake.TailSymbol;
	}
	map[snake.getBody().at(0).y][snake.getBody().at(0).x] = snake.HeadSymbol;
}

void Map::putApple(Apple& apple)
{
	map[apple.getPoint().y][apple.getPoint().x] = apple.getSymbol();
	apple.setEaten(false);
}

std::vector<Point> Map::getEmptyPos()const
{
	std::vector<Point> emptyPos;
	for (int i = 0; i < Data.height; i++)
		for (int j = 0; j < Data.width; j++)
			if(map[i][j] == ' ')
				emptyPos.push_back({ j, i });
	return emptyPos;
}
