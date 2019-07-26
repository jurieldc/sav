#include "pch.h"
#include "MovementComponent.h"

MovementComponent::MovementComponent(sf::Sprite& sprite, float maxVelocity, float acceleration, float deceleration, const float gravity, float jumpVelocity, float height)
	: sprite(sprite), maxVelocity(maxVelocity), acceleration(acceleration), deceleration(deceleration), gravity_speed(gravity), jumpVelocity_speed(jumpVelocity), height(height) {
}


MovementComponent::~MovementComponent(){
}

//accessors
const sf::Vector2f & MovementComponent::getVelocity() const{
	return this->velocity;
}

//functions
const bool MovementComponent::getState(const short unsigned states) const{
	//checking the state of the player to be able to provide the right animation
	switch (states) {
	case IDLE:
		if (this->velocity.x == 0.f && this->velocity.y == 0.f)
			return true;
		break;

	case MOVING:
		if (this->velocity.x != 0.f && this->velocity.y != 0.f)
			return true;
		break;

	case MOVING_LEFT:
		if (this->velocity.x < 0.f)
			return true;
		break;

	case MOVING_RIGHT: 
		if (this->velocity.x > 0.f)
			return true;
		break;
	}

	return false;
}

void MovementComponent::move(const float xDir, const float yDir, const float& dt){
	this->velocity.x += this->acceleration * xDir;
	this->velocity.y += this->acceleration * yDir;
	//adds velocity to jump or moving up
	if (this->velocity.y > 0.f)
		velocity.y = -jumpVelocity_speed;
}

void MovementComponent::update(const float & dt){	
	//GRAVITY
	if (sprite.getPosition().y + height < groundHeight || velocity.y < 0) {
		velocity.y += gravity_speed;
	}
	else {
		sprite.setPosition(sprite.getPosition().x, groundHeight - height);
		velocity.y = 0;
	}

	//Decelerates the sprite for a smooth movement
	if (this->velocity.x > 0.f) { //check for right movement
		//Accelerates right movement
		if (this->velocity.x > this->maxVelocity)
			this->velocity.x = this->maxVelocity;
		
		//Decelerates when stopping or going to other direction
		this->velocity.x -= deceleration;
		if (this->velocity.x < 0.f)
			this->velocity.x = 0.f;
	}
	else if (this->velocity.x < 0.f) { //check for left	movement
		//Acceleratesleft movement
		if (this->velocity.x < -this->maxVelocity)
			this->velocity.x = -this->maxVelocity;
		
		//Decelerates when stopping or going to other direction
		this->velocity.x += deceleration;
		if (this->velocity.x > 0.f)
			this->velocity.x = 0.f;
	}

	//Final Move
	this->sprite.move(this->velocity * dt); //uses velocity
}
