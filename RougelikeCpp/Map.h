#pragma once
#include<SFML/Graphics.hpp>


struct Tile
{
	int tileNumber = 0;//tile number(ascii)
	bool passable = true;//possible move tile?
	bool transparent = true;//block sight?
	bool visible = false;
	bool explored = false;
};
class Map
{
public:
	Map(sf::Vector2i size);
	const sf::Vector2i& getSize() const;
	const Tile& getTile(int x, int y) const;
	void setTile(int x, int y, Tile tile);

	void setBisible(int x, int y, bool flag);
	void setExplored(int x, int y, bool flag);

protected:
	sf::Vector2i m_size;// map size
	std::vector<Tile> m_tiles;//The tiles that make up the map.



};

