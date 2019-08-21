#pragma once
#include"World.h"
class Game
{
public:
	Game();
	void run();

private:
	void processInput();
	void update();
	void render();

	sf::RenderWindow m_window;
	sf::Texture m_tileset;
	World m_world;
};

