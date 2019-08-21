#include "Game.h"

Game::Game()
{
	//Variable declaration
	const sf::Vector2i tileSize(16, 16);
	//Screen Width Height

	const sf::Vector2i screenSize(80, 60);
	//Window size 1280x960
	//constexpr int windowWidth = tileWidth * screenWidth;
	//constexpr int windowHeight = tileHeight * screenHeight;
	const sf::Vector2i windowSize(tileSize.x * screenSize.x, tileSize.y * screenSize.y);

	
	m_window.create(sf::VideoMode(windowSize.x, windowSize.y), "Hello, RogueLike!");
	m_window.setVerticalSyncEnabled(true);


	m_tileset.loadFromFile("tileset_ascii_16x16.png");
	m_world.initialize(m_tileset, tileSize, screenSize);
	//Character position is center;
	/*int playerX = screenWidth / 2;
	int playerY = screenHeight / 2;

	sf::Sprite player(texture);
	player.setTextureRect(sf::IntRect(0, 4 * tileWidth, tileWidth, tileHeight));
	player.setPosition(playerX * tileWidth, playerY * tileHeight);*/


}

void Game::run()
{
	while (m_window.isOpen())
	{
		processInput();
		update();
		render();
	}
}

void Game::processInput()
{
	sf::Event event;

	while (m_window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)//when press 'x' key, window is exit
			m_window.close();
		else if (event.type == sf::Event::KeyPressed)
			m_world.handleKeyboard(event.key.code);
	}
}

void Game::update()
{
	m_world.update();
}

void Game::render()
{
	m_window.clear();//Empty the render buffer
	m_world.draw(m_window);
	
	m_window.display();//display Screen
}
