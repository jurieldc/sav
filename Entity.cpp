#include "pch.h"
#include "Entity.h"

void Entity::initVariable(){
	//initializes the each components to null
	this->hitBoxComponent = NULL;
	this->movementComponent = NULL;
	this->animationComponent1 = NULL;
}

Entity::Entity(){
	this->initVariable();
}

Entity::~Entity(){
	//delete the components after use
	delete this->hitBoxComponent;
	delete this->movementComponent;
	delete this->animationComponent1;
}

//component function

void Entity::setTexture(sf::Texture& texture){
	this->sprite.setTexture(texture);
}

void Entity::CreateHitboxComponent(sf::Sprite & sprite, float offset_x, float offset_y, float width, float height){
	this->hitBoxComponent = new HitBoxComponent(sprite, offset_x, offset_y, width, height);//to be able to create an instance of HitBoxComponent
}

void Entity::CreateMovementComponent(const float maxVelocity, const float acceleration, const float deceleration, const float gravity, float jumpVelocity, float height){
	this->movementComponent = new MovementComponent(this->sprite, maxVelocity, acceleration, deceleration, gravity, jumpVelocity, height);//to be able to create an instance of MovementComponent
}

void Entity::CreateAnimationComponent1(sf::Texture & texture_sheet){
	this->animationComponent1 = new AnimationComponent(this->sprite, texture_sheet);//to be able to create an instance of Animation
}

//function
void Entity::setPosition(const float x, const float y){
	this->sprite.setPosition(x, y);//mimics the sfml setPosition for sprite
}

sf::Vector2f Entity::getPosition()
{
	return sf::Vector2f(this->sprite.getPosition());//mimics the sfml getPosition for spite
}

sf::Vector2f Entity::getSize(){
	//mimics the sfml getSize for spite
	sf::Texture text;
	return sf::Vector2f(text.getSize());
}

void Entity::move(const float xDir, const float yDir, const float& dt){
	if (this->movementComponent) {
		this->movementComponent->move(xDir, yDir, dt); //sets velocity
	}
}

void Entity::update(const float & dt){
	if (this->movementComponent)
		this->movementComponent->update(dt);
}

void Entity::render(sf::RenderTarget& target){
		target.draw(this->sprite);

		if (this->hitBoxComponent)
			this->hitBoxComponent->render(target);
}
