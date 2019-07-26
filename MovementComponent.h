#pragma once

using namespace std;

enum movementStates{IDLE = 0, MOVING, MOVING_LEFT, MOVING_RIGHT};

class MovementComponent{
private:
	sf::Sprite& sprite;

	float maxVelocity;
	float deceleration;
	float acceleration;

	int groundHeight = 600;

	float height;
	float gravity_speed;
	float jumpVelocity_speed;

	//initializer

public:
	MovementComponent(sf::Sprite& sprite, float maxVelocity, float acceleration, float deceleration, const float gravity, float jumpVelocity, float height);
	virtual ~MovementComponent();

	sf::Vector2f velocity;
	const unsigned WINDOW_WIDTH = 1000;
	const unsigned WINDOW_HEIGHT = 720;

	//Accessors
	const sf::Vector2f& getVelocity() const;

	//functions
	const bool getState(const short unsigned states) const;

	void move(const float xDir, const float yDir, const float& dt);
	void update(const float& dt);
};

