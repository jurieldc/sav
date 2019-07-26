#pragma once

using namespace std;

class HitBoxComponent{
private:
	sf::Sprite& sprite;
	float offsetX;
	float offsetY;

	sf::RectangleShape hitbox;
public:
	HitBoxComponent(sf::Sprite& sprite, float offset_x, float offset_y, float width, float height);
	virtual ~HitBoxComponent();

	//functions
	bool checkIntersect(const sf::FloatRect& frect);

	void update();
	void render(sf::RenderTarget& target);
};

