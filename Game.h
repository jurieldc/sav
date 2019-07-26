#pragma once

#include "MainMenuState.h"

class Game{
private:
	//variables
	sf::RenderWindow *window;
	sf::Event sfEvent;
	sf::Event* sfEventCopy;

	sf::Clock dtClock;
	float dt;//keep track on  how long for game to do 1 update and render call

	stack<State*> states;
	map<string, int> supportedKeys;

	//initializer
	void initWindow();
	void initStates();
	void initKeys();

public:
	
	//Constructor/Destructor
	Game();
	virtual ~Game();

	//functions
	void endApplication();

	//Update
	void updateDt();
	void updateSFMLEvents();
	void update();

	//Render
	void render();

	//Run
	void run();
};

