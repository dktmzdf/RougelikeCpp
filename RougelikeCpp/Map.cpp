#include "Map.h"

Map::Map(sf::Vector2i size)
	:m_size(size), m_tiles(size.x * size.y)
{
}

const sf::Vector2i& Map::getSize() const
{
	// TODO: insert return statement here
	return m_size;
}

const Tile& Map::getTile(int x, int y) const
{
	// TODO: insert return statement here
	return m_tiles[x + y * m_size.x];
}

void Map::setTile(int x, int y, Tile tile)
{
	m_tiles[x + y * m_size.x] = tile;
}

void Map::setBisible(int x, int y, bool flag)
{
	m_tiles[x + y * m_size.x].visible = flag;
}

void Map::setExplored(int x, int y, bool flag)
{
	m_tiles[x + y * m_size.x].explored = flag;
}
