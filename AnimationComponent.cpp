#include "pch.h"
#include "AnimationComponent.h"

AnimationComponent::AnimationComponent(sf::Sprite& sprite, sf::Texture& texture_sheet) : sprite(sprite), textureSheet(texture_sheet), lastAnimation(NULL){

}


AnimationComponent::~AnimationComponent(){
	//Deletes animation each frame
	for (auto &i : this->animations)
		delete i.second;
}

void AnimationComponent::addAnimation(const string key, float animation_timer,
	int start_x, int start_y, int frames_x, int frames_y, 
	int width, int height){
	
	this->animations[key] = new Animation(this->sprite, this->textureSheet, animation_timer, start_x, start_y, frames_x, frames_y, width, height);
}

//functions
void AnimationComponent::play(const string key, const float & dt){
	//does the animation
	if (this->lastAnimation != this->animations[key]) {
		if (this->lastAnimation == NULL)
			this->lastAnimation = this->animations[key];
		else{
			this->lastAnimation->reset();
			this->lastAnimation = this->animations[key];
		}

	}
	
	this->animations[key]->play(dt);
}
