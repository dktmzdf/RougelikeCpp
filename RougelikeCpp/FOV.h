#pragma once

#include"Map.h"

class FOV
{
public: 
	void initialize(Map& map, int radius);
	void compute(sf::Vector2i pos);

private:
	void castRay(sf::Vector2i start, sf::Vector2i end);
	int distanceSquared(sf::Vector2i from, sf::Vector2i to);

	Map* m_map = nullptr;
	int m_radius = 0;
};

