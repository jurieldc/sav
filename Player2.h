#pragma once
#include "Entity.h"

class Player2 : public Entity{
private:
	//Variables

	//Initializer
	void initVariable();
	void initComponent();
public:
	Player2(float x, float y, sf::Texture& texture_sheet);
	virtual ~Player2();

	//functions
	virtual void update(const float& dt);
};

