#pragma once

#include "HitBoxComponent.h"
#include "MovementComponent.h"
#include "AnimationComponent.h"

class Entity{
private:
	void initVariable();

protected:
	sf::Sprite sprite;

	HitBoxComponent* hitBoxComponent;
	MovementComponent* movementComponent;
	AnimationComponent* animationComponent1;

	float movementSpeed;

public:
	Entity();
	virtual ~Entity();

	//component function
	void setTexture(sf::Texture& texture);
	void CreateHitboxComponent(sf::Sprite& sprite, float offset_x, float offset_y, float width, float height);
	void CreateMovementComponent(const float maxVelocity, const float acceleration, const float deceleration, const float gravity, float jumpVelocity, float height);
	void CreateAnimationComponent1(sf::Texture& texture_sheet);

	//functions
	virtual void setPosition(const float x, const float y);
	virtual sf::Vector2f getPosition();
	virtual sf::Vector2f getSize();
	virtual void move(const float xDir, const float yDir, const float& dt);

	virtual void update(const float& dt);
	virtual void render(sf::RenderTarget& target);
};

