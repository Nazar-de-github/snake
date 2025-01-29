//#include <iostream>
//#include "Map.h"
//#include "Snake.h"
//#include "Apple.h"
//#include <Windows.h>
#include "Game.h"


int main()
{
	/*Map map;
	Snake snake;
	Apple apple;

	while(1)
	{
		try { snake.move(map, apple, snake.inputDirection()); }
		catch (...)
		{
			Sleep(1000);
			system("cls");
			std::cout << "GameOVER";
			return 0;
		}
		if (apple.getEaten())
		{
			apple.move(map, snake);
		}
		map.init();
		
		map.putApple(apple);
		map.putSnake(snake);
		

		map.show();
		Sleep(80);
		std::cout << "Score: " << snake.getScore() << '\n' << "\033[H";
	}*/

	Game game;
	game.menu();

	return 0;
}