#pragma once
#include "Entity.h"
#include"FOV.h"
#include "TileMap.h"
#include"Dungeon.h"
class World
{
public:
	
	void initialize(sf::Texture& tileset, sf::Vector2i tileSize, sf::Vector2i mapSize);

	void handleKeyboard(sf::Keyboard::Key key);
	void update();
	void draw(sf::RenderWindow& window);

	const sf::Texture& getTileset() const;
	const sf::Vector2i& getTileSize() const;
	const sf::Vector2i& getMapSize() const;

	bool isPassable(sf::Vector2i pos) const;
	Entity* getEntity(sf::Vector2i pos) const;
	void addEntity(std::unique_ptr<Entity> entity);

private:
	const sf::Texture* m_tileset = nullptr;
	sf::Vector2i m_tileSize;
	sf::Vector2i m_mapSize;
	std::unique_ptr<Dungeon> m_currentLevel = nullptr;
	std::vector<std::unique_ptr<Entity>> m_entities;
	Entity* m_playerActor = nullptr;
	FOV m_fov;
	TileMap m_tileMap;
};
