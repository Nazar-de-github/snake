#include <iostream>
#include "Map.h"
#include "Snake.h"
#include "Apple.h"
#include <Windows.h>



int main()
{
	Map map;
	Snake snake;
	Apple apple;

	while(1)
	{
		map.init();
		if (apple.getEaten())
		{
			apple.move(map, snake);
		}

		map.putApple(apple);
		map.putSnake(snake);
		try { snake.move(map, apple, snake.inputDirection()); }
		catch (...)
		{
			Sleep(1000);
			system("cls");
			std::cout << "GameOVER";
			return 0;
		}
		map.show();
		Sleep(80);
		std::cout << "Score: " << snake.getScore() << '\n' << "\033[H";
	}

	return 0;
}