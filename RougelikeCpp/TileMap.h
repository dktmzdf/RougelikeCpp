#pragma once

#include"Map.h"
class TileMap
{
public:
	

	void load(const Map& map);
	void load(const sf::Texture& texture, const sf::Vector2i& tileSize);
	void update(const Map& map);
	void draw(sf::RenderWindow& window) const;

private:
	const sf::Texture* m_texture = nullptr;
	sf::Vector2i m_tileSize;
	std::vector<sf::Vertex> m_vertices;
};

