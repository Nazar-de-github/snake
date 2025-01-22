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
	{
		std::cout << map[i]<<"\n";
	}
}


void Map::putSnake(Snake snake)
{
	map[snake.getBody().at(0).y][snake.getBody().at(0).x] = snake.HeadSymbol;
	for (int i = 1; i < snake.getBody().size(); i++)
	{
		map[snake.getBody().at(i).y][snake.getBody().at(i).x] = snake.TailSymbol;
	}
}

void Map::putApple(Apple& apple)
{
	map[apple.getPoint().y][apple.getPoint().x] = apple.getSymbol();
	apple.setEaten(false);
}
