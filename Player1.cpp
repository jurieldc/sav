#include "pch.h"
#include "Player1.h"

//Initializer Function
void Player1::initVariable() {

}

void Player1::initComponent() {

}

//Constructor/Destructor
Player1::Player1(float x, float y, sf::Texture& texture_sheet) {
	this->initVariable();

	this->setPosition(x, y);
	this->getPosition();
	this->getSize();

	this->CreateHitboxComponent(this->sprite, 25.f, 15.f, 40.f, 45.f);//passes the required parameter to create a HitBoxComponent
	this->CreateMovementComponent(170.f, 5.f, 3.f, 20.f, 7.f, 80);//passes parameters to create a MovementComponent

	this->CreateAnimationComponent1(texture_sheet);//passes texture to create animation

	this->animationComponent1->addAnimation("PLAYER_IDLE", 10.f, 0, 0, 7, 0, 80, 80); //if idle animation
	this->animationComponent1->addAnimation("PLAYER_ANIMATION", 10.f, 0, 1, 7, 1, 80, 80);//if the player is moving animation
}

Player1::~Player1() {
}

void Player1::update(){

}

void Player1::update(const float & dt) {
	this->movementComponent->update(dt);

	/**SETTING UP THE SIZE OF THE COLLISION IN EACH TILE**/
	this->bottom = this->sprite.getPosition().y + 75;
	this->left = this->sprite.getPosition().x;
	this->right = this->sprite.getPosition().x + 75;
	this->top = this->sprite.getPosition().y;

	sf::Vector2i topLeft(sf::Vector2i((int)left / 75, (int)top / 75));
	sf::Vector2i topRight(sf::Vector2i((int)right / 75, (int)top / 75));
	sf::Vector2i bottomleft(sf::Vector2i((int)left / 75, (int)bottom / 75));
	sf::Vector2i bottomRight(sf::Vector2i((int)right / 75, (int)bottom / 75));

	tiles.clear();

	tiles.push_back(topLeft);
	if(find(tiles.begin(), tiles.end(), topRight) == tiles.end()) tiles.push_back(topRight);
	if(find(tiles.begin(), tiles.end(), bottomleft) == tiles.end()) tiles.push_back(bottomleft);
	if(find(tiles.begin(), tiles.end(), bottomRight) == tiles.end()) tiles.push_back(bottomRight);
	/**END COLLISION**/

	/**GIVES A PROPER ANIMATION DEPENDING ON WHAT STATE THE PLAYER IS IN, IDLE, MOVING LEFT, MOVING RIGHT**/
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
	/**END ANIMATION**/

	this->hitBoxComponent->update();

}
