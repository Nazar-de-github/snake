#pragma once

#include "Map.h"
#include "Snake.h"
#include "Apple.h"
#include <iostream>
#include <vector>

class Game
{
private:
	unsigned level;
	std::vector<int> topScore;

	std::vector<std::string> options;

	Map map;
	Snake snake;
	Apple apple;

	void init();
	void moveUnits();
	void putUnits();
	void draw();

	void menu_start();
	void menu_settings();
	void menu_controls();
	void menu_records();
	void menu_exit();
	void reset();

public:
	Game() : level(0), topScore{}, options{"Start", "Settings", "Controls", "Records", "Exit"} {}

	void menu();
};

