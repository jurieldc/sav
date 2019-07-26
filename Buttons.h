#pragma once

using namespace std;

enum button_states { BTN_IDLE = 0, BTN_HOVER, BTN_ACTIVE };

class Buttons{
private:
	short unsigned button_states;

	bool pressed;
	bool hover;

	//test
	sf::Texture btn_texture;
	sf::Texture btnTexture_hover;
	sf::Sprite btn_sprite;
	sf::Sprite btnSprite_hover;

	sf::Texture btnHover_Texture;
	sf::Texture btnIdle_Texture;
public:
	Buttons(sf::Texture btnTexture, sf::Texture btnTextureHover, float x, float y);
	~Buttons();

	//assesors
	const bool isPressed() const;

	//functions
	void update(const sf::Vector2f mousePos);
	void render(sf::RenderTarget& target);
};

