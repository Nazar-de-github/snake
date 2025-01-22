#pragma once
#include "Tools.h"

class Snake;
class Map;

class Apple {
	Point coord;
	char symbol = '@';
	int value;
	bool isEaten = true;
public:
	Apple() : coord({ 40, 20 }),value(10),isEaten(false) {}
	char getSymbol() { return symbol; }
	int getValue() { return value; }
	Point getPoint() { return coord; }
	void setEaten(bool eaten) { isEaten = eaten; }
	void move(Map &map, Snake &snake, bool force = false);
	bool getEaten() { return isEaten; }
};

