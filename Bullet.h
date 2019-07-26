#pragma once

class Bullet{
private:
	sf::RectangleShape bullet;

public:
	Bullet(sf::Vector2f size) { bullet.setSize(size); bullet.setFillColor(sf::Color::Blue); }

	void fire(int speed) { bullet.move(speed, 0); }

	int getRight() { return bullet.getPosition().x + bullet.getSize().x; }
	int getLeft() { return bullet.getPosition().x; }
	int getTop() { return bullet.getPosition().y; }
	int getBottom() { return bullet.getPosition().y + bullet.getSize().y; }
	void setPos(sf::Vector2f newPos) {
		bullet.setPosition(newPos);
	}
		
	virtual ~Bullet();

	void render(sf::RenderWindow &window) {
		//window.draw(this->bullet);
	}
};

