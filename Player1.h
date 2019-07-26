#pragma once

#include "Bullet.h"
#include "Entity.h"

class Player1:public Entity {
private:
	//Variables

	//Initializer
	void initVariable();
	void initComponent();
public:
	Player1(float x, float y, sf::Texture& texture_sheet);
	virtual ~Player1();

	//variables
	float bottom;
	float left;
	float right;
	float top;
	vector<sf::Vector2i> tiles;

	//functions
	void checkCol(Bullet bullet);

	void update();
	virtual void update(const float& dt);
};

