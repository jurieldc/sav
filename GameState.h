#pragma once

#include "State.h"
#include "MapTiles.h"
#include "MainMenuState.h"

class GameState : public State{
private:
	MapTiles* map_tiles;
	Player1* player1;
	Player2* player2;
	bool isFiring = false;

	//functions
	void initkeybinds();
	void initTextures();
	void initMapTiles();
	void initPlayers();

protected:

public:
	GameState(sf::RenderWindow* window, map<string, int>* supportedKeys, stack<State*>* states);
	virtual ~GameState();

	//Variable
	sf::Texture demoBg_Texture;
	sf::Sprite demoBg_Sprite;

	void updateKeybinds(const float& dt);
	void update(const float& dt);
	void render(sf::RenderTarget* target = nullptr);
};

