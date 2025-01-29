#include "Game.h"
#include <Windows.h>
#include <algorithm>

void Game::init()
{
	map.init();
}

void Game::moveUnits()
{
	snake.move(map, apple, snake.inputDirection());

	if (apple.getEaten())
	{
		apple.move(map, snake);
	}
}

void Game::putUnits()
{
	map.putApple(apple);
	map.putSnake(snake);
}

void Game::draw()
{
	map.show();
	Sleep(80);
	std::cout << "Score: " << snake.getScore() << '\n' << "\033[H";
}

void Game::menu_start()
{
	try {
		while (1)
		{
			moveUnits();
			init();
			putUnits();
			draw();
		}
	}
	catch (...)
	{
		Sleep(1000);
		std::cout << "\033[H\033[J";
		std::cout << "\t\tGameOVER\n\t\tScore: " << snake.getScore();
		Sleep(2000);
		std::cout << "\033[H\033[J";
		reset();
		
		topScore.push_back(snake.getScore());
		std::sort(topScore.begin(), topScore.end(), std::greater<>{});

		menu();
	}
	
}

void Game::menu_settings()
{
	menu();
}

void Game::menu_controls()
{
	menu();
}

void Game::menu_records()
{
	std::cout << "\033[H\033[J";
	std::cout << "\t\t\tTOP SCORE    \n\n";
	for (int i = 0; i < topScore.size(); i++)
	{
		std::cout << "Score: " << topScore[i] << '\n';
	}
	
	while (!GetAsyncKeyState(VK_ESCAPE) & 0b1) { Sleep(50); }
	std::cout << "\033[H\033[J";
	menu();

}

void Game::menu_exit()
{
	std::cout << "\033[H\033[J";
	exit(0);
}

void Game::reset()
{
	map.init();
	snake = Snake();
	apple = Apple();
}

void Game::menu()
{
	int option = 0;
	
	while (!(GetAsyncKeyState(VK_SPACE) & 0b1))
	{
		std::cout << "\n\n\n\n\n";

		for (int i = 0; i < options.size(); i++)
		{
			if(i == option)
				std::cout << "              > " << options[i] << " <    \n";
			else
				std::cout << "                " << options[i] << "      \n";
		}

		if (GetAsyncKeyState('S') & 0b1 && option < options.size()-1)
			option++;
		if (GetAsyncKeyState('W') & 0b1 && option > 0)
			option--;
		Sleep(60);
		std::cout << "\033[H";
	}

	if (options[option] == "Start")
		menu_start();
	else if (options[option] == "Settings")
		menu_settings();
	else if (options[option] == "Controls")
		menu_controls();
	else if (options[option] == "Records")
		menu_records();
	else if (options[option] == "Exit")
		menu_exit();
	

}

