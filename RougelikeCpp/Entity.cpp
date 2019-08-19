#include "Entity.h"

Entity::Entity(const sf::Texture& texture, sf::Vector2i tileSize, int tileNumber)
	:m_sprite(texture), m_tileSize(tileSize)
{
		//생정자의 파라미터(매개변수)는 sf::Sprite를 초기화하기 위한 변수들인데
		//지난 번과 다른 점은 텍스쳐의 범위를 직접 지정하는 것이 아니라 타일 번호를 이용한다는 것이다
		//생성자에 있는 계산식은 타일 번호로부터 타일 위치(행과 열)를 역산하는 과정인데
		//4행 15열에 있는 ‘O’ 문자라면 타일 번호는 0x4F(79)가 되고, 이로부터 다시(15, 4)를 구하는 과정이라고 보면 된다
	const int tu = tileNumber % (texture.getSize().x / tileSize.x);
	const int tv = tileNumber / (texture.getSize().x / tileSize.x);
	m_sprite.setTextureRect({ tu * tileSize.x, tv * tileSize.y, tileSize.x, tileSize.y });
}

const sf::Vector2i& Entity::getPosition() const
{
	// TODO: insert return statement here
	return m_position;

}

void Entity::setPosition(int x, int y)
{
	//불필요한 경고 메세지를 줄이기 위한 타입 캐스팅;
	const float fx = static_cast<float>(x * m_tileSize.x);
	const float fy = static_cast<float>(y * m_tileSize.y);
	m_sprite.setPosition(fx, fy);
	m_position.x = x;
	m_position.y = y;


}
void Entity::setPosition(sf::Vector2i pos)
{
	setPosition(pos.x, pos.y);
}

void Entity::move(int dx, int dy)
{
	setPosition(m_position.x + dx, m_position.y + dy);
}

void Entity::draw(sf::RenderWindow& window) const
{
	window.draw(m_sprite);
}
