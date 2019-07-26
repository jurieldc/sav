#pragma once

using namespace std;

class AnimationComponent
{
private:
	class Animation {
	public:
		//Variable
		sf::Sprite& sprite;
		sf::Texture& textureSheet;
		float animationTimer;
		float timer;
		int width;
		int height;
		sf::IntRect startRect;
		sf::IntRect currentRect;
		sf::IntRect endRect;

		Animation(sf::Sprite& sprite, sf::Texture& texture_Sheet, float animation_timer, 
			int start_x, int start_y, int frames_x, int frames_y, int width, int height)
			:sprite(sprite), textureSheet(texture_Sheet), animationTimer(animation_timer), width(width), height(height) {
			
			this->timer = 0.f;//timer for animation
			this->startRect = sf::IntRect(start_x * width, start_y * height, width, height);
			this->currentRect = this->startRect;
			this->endRect = sf::IntRect(frames_x * width, frames_y * height, width, height);
		
			this->sprite.setTexture(this->textureSheet, true);
			this->sprite.setTextureRect(this->startRect);
		}

		//functions
		const void play(const float& dt) {
			//Update Timer
			this->timer += 90.0f * dt;
			if (this->timer >= this->animationTimer) {
				//reset timer
				this->timer = 0.f;

				//Animate
				if (this->currentRect != this->endRect)
					this->currentRect.left += this->width;
				else
					this->currentRect.left = this->startRect.left;

				this->sprite.setTextureRect(this->currentRect);
			}
		}

		void reset() {
			this->timer = 0.f;
			this->currentRect = this->startRect;
		}
	};

	sf::Sprite& sprite;
	sf::Texture& textureSheet;
	map<std::string, Animation*> animations;
	Animation* lastAnimation;

public:
	AnimationComponent(sf::Sprite& sprite, sf::Texture& texture_sheet);
	virtual ~AnimationComponent();

	//functions
	void addAnimation(const string key, float animation_timer,
		int start_x, int start_y, int frames_x, int frames_y, int width, int height);

	void play(const string key, const float& dt);
};

