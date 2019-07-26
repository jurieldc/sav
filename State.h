#pragma once

#include "Player1.h"
#include "Player2.h"

class State{
private:

protected:
	stack<State*>* states;
	sf::RenderWindow* window;
	map<string, int>* supportedKeys;
	map<string, int> keybinds;
	bool exit;

	sf::Vector2i mousePosScreen;
	sf::Vector2i mousePosWindow;
	sf::Vector2f mousePosView;

	//resources
	sf::Texture texture_player1;
	sf::Texture texture_player2;

	//functions
	virtual void initkeybinds() = 0;
public:
	State(sf::RenderWindow* window, map<string,int>* supportedKeys, stack<State*>* states);
	virtual ~State();

	const bool& getExit() const;
	void endState();

	virtual void updateMousePos();
	virtual void updateKeybinds(const float& dt) = 0;
	virtual void update(const float& dt) = 0;
	virtual void render(sf::RenderTarget* target = nullptr) = 0;
};

