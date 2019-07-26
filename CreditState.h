#pragma once

#include "GameState.h"
#include "Buttons.h"

class CreditState : public State {
private:
	sf::RectangleShape background;
	sf::Font font;

	sf::Texture backgroundTexture;
	sf::Sprite backgroundSprite;

	sf::Texture titleTexture;
	sf::Sprite titleSprite;

	sf::Texture img_btn;
	sf::Texture imgHover_btn;

	map<string, Buttons*> buttons;

	//functions
	void initkeybinds();
public:
	CreditState(sf::RenderWindow* window, map<string, int>* supportedKeys, stack<State*>* states);
	virtual ~CreditState();

	//Functions
	void updateKeybinds(const float& dt);
	void updateButtons();
	void update(const float& dt);
	void renderButtons(sf::RenderTarget& target);
	void render(sf::RenderTarget* target = nullptr);
};
