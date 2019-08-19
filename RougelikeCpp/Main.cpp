#include<iostream>
#include<SFML/Graphics.hpp>
#include"Entity.h"
#include"TileMap.h"
#include"Dungeon.h"
#include"FOV.h"

int main()
{
	//Variable declaration
	const sf::Vector2i tileSize(16, 16);
	//Screen Width Height
	
	const sf::Vector2i screenSize(80, 60);
	//Window size 1280x960
	//constexpr int windowWidth = tileWidth * screenWidth;
	//constexpr int windowHeight = tileHeight * screenHeight;
	const sf::Vector2i windowSize(tileSize.x * screenSize.x, tileSize.y * screenSize.y);

	sf::RenderWindow window(sf::VideoMode(windowSize.x,windowSize.y), "Hello, RogueLike!");
	window.setVerticalSyncEnabled(true);

	sf::Texture texture;
	texture.loadFromFile("tileset_ascii_16x16.png");
	
	//Character position is center;
	/*int playerX = screenWidth / 2;
	int playerY = screenHeight / 2;

	sf::Sprite player(texture);
	player.setTextureRect(sf::IntRect(0, 4 * tileWidth, tileWidth, tileHeight));
	player.setPosition(playerX * tileWidth, playerY * tileHeight);*/



	Dungeon dungeon(screenSize);
	dungeon.generate();

	Entity player(texture, tileSize, '@');
	player.setPosition(dungeon.findPassableTile());

	FOV fov;
	fov.initialize(dungeon, 10);
	fov.compute(player.getPosition());

	TileMap tileMap(texture, tileSize);
	tileMap.load(dungeon);


	
	while (window.isOpen())
	{
		sf::Event event;
		int dx = 0;
		int dy = 0;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)//when press 'x' key, window is exit
				window.close();
			else if (event.type == sf::Event::KeyPressed)
			{
				switch (event.key.code)
				{
				case sf::Keyboard::Left:
					dx--;
					break;
				case sf::Keyboard::Right:
					dx++;
					break;
				case sf::Keyboard::Up:
					dy--;
					break;
				case sf::Keyboard::Down:
					dy++;
					break;

					
				default:
					break;
				}
				//player position Update;
				if (dx != 0 || dy != 0)
				{
					const sf::Vector2i pos = player.getPosition();
					const sf::Vector2i newPos = { pos.x + dx, pos.y + dy };

					if (newPos.x >= 0 && newPos.y >= 0 &&
						newPos.x < screenSize.x && newPos.y < screenSize.y)
					{
						if (dungeon.getTile(newPos.x, newPos.y).passable)
						{
							player.move(dx, dy);
							//Recompute fov
							fov.compute(player.getPosition());
							tileMap.load(dungeon);
						}
					}
				}
			}
			
		}
		
		window.clear();//Empty the render buffer
		tileMap.draw(window);
		player.draw(window);//draw player in render buffer
		window.display();//display Screen

	}
	
}

/*//sf:::VertexArray는 std::Vector<sf::vertex>의 랩퍼(wrapper) 클래스
		sf::VertexArray Triangle(sf::Triangles, 3);
		//three points of triangle
		Triangle[0].position = sf::Vector2f(10.f, 10.f);
		Triangle[1].position = sf::Vector2f(100.f, 10.f);
		Triangle[2].position = sf::Vector2f(100.f, 100.f);
		//three colors of triangle
		Triangle[0].color = sf::Color::Red;
		Triangle[0].color = sf::Color::Blue;
		Triangle[0].color = sf::Color::Green;
*/