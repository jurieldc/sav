#pragma once

#include "GameState.h"
#include "AboutState.h"
#include "CreditState.h"
#include "Buttons.h"

class MainMenuState : public State{
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
	void initFonts();
	void initkeybinds();
	void initButtons();
public:
	MainMenuState(sf::RenderWindow* window, map<string, int>* supportedKeys, stack<State*>* states);
	virtual ~MainMenuState();

	//Functions
	void updateKeybinds(const float& dt);
	void updateButtons();
	void update(const float& dt);
	void renderButtons(sf::RenderTarget& target);
	void render(sf::RenderTarget* target = nullptr);
};

