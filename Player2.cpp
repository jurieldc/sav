#include "pch.h"
#include "Player2.h"

//Initializer Function
void Player2::initVariable(){

}

void Player2::initComponent(){

}

//Constructor/Destructor
Player2::Player2(float x, float y, sf::Texture& texture_sheet){
	this->initVariable();

	this->setPosition(x, y);
	this->getPosition();

	this->CreateHitboxComponent(this->sprite, 25.f, 15.f, 40.f, 45.f);
	this->CreateMovementComponent(170.f, 5.f, 3.f, 15.0f, 7.f, 80);
	this->CreateAnimationComponent1(texture_sheet);

	this->animationComponent1->addAnimation("PLAYER_IDLE", 10.f, 0, 0, 7, 0, 80, 80);
	this->animationComponent1->addAnimation("PLAYER_ANIMATION", 10.f, 0, 1, 7, 1, 80, 80);
}

Player2::~Player2(){
}

void Player2::update(const float & dt){
	this->movementComponent->update(dt);

	if (this->movementComponent->getState(IDLE)) {
		this->animationComponent1->play("PLAYER_IDLE", dt);
	}
	else if (this->movementComponent->getState(MOVING_RIGHT)) {
		this->sprite.setOrigin(0.f, 0.f);
		this->sprite.setScale(1.f, 1.f);
		this->animationComponent1->play("PLAYER_ANIMATION", dt);
	}
	else if (this->movementComponent->getState(MOVING_LEFT)) {
		this->sprite.setOrigin(88.f, 0.f);
		this->sprite.setScale(-1.f, 1.f);
		this->animationComponent1->play("PLAYER_ANIMATION", dt);
	}

	this->hitBoxComponent->update();
}
