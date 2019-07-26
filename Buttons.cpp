#include "pch.h"
#include "Buttons.h"

Buttons::Buttons(sf::Texture btnTexture, sf::Texture btnTextureHover, float x, float y) {

	this->button_states = BTN_IDLE;

	this->btn_texture = btnTexture;
	this->btnHover_Texture = btnTextureHover;
	this->btn_sprite.setTexture(btn_texture);
	this->btn_sprite.setPosition(x / 2 - (btn_sprite.getGlobalBounds().width / 2), y);
}

Buttons::~Buttons(){
}

//assesor
const bool Buttons::isPressed() const{
	if (this->button_states == BTN_ACTIVE)
		return true;
	return false;
}

//functions
void Buttons::update(const sf::Vector2f mousePos){
	/**update the booleans for hover and pressed**/
	
	//idle
	this->button_states = BTN_IDLE;
	
	//hover
	if (this->btn_sprite.getGlobalBounds().contains(mousePos)) {
		this->button_states = BTN_HOVER;

		//pressed
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			this->button_states = BTN_ACTIVE;
		}
	}

	/**uses the suitable texture for hover, active, idle buttons**/
	switch (this->button_states) {
	case BTN_IDLE:
		this->btn_sprite.setTexture(btn_texture);
		break;
	case BTN_HOVER:
		this->btn_sprite.setTexture(btnHover_Texture);
		break;
	case BTN_ACTIVE:
		this->btn_sprite.setTexture(btnHover_Texture);
		break;
	default:
		this->btn_sprite.setColor(sf::Color::Red);
		break;
	}
	
}

void Buttons::render(sf::RenderTarget& target){
	target.draw(this->btn_sprite);
}
