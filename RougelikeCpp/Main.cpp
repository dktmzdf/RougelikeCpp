#include"Game.h"

int main()
{
	Game game;
	game.run();
	 
	return 0;
	
	
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