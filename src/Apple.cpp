#include "Apple.h"
#include "Map.h"
#include "Snake.h"
#include <random>
#include <chrono>

int randomNum(int min, int max)
{
	time_t seed = std::chrono::steady_clock::now().time_since_epoch().count();
	std::mt19937 engine(seed);
	std::uniform_int_distribution<> dist(min, max);
	return dist(engine);
}

void Apple::move(Map& map, Snake& snake, bool force)
{
	if(isEaten || force)
		coord = map.getEmptyPos().at(randomNum(0, map.getEmptyPos().size()-1));
}
