#pragma once

#include "Player1.h"
#include "Player2.h"
#include "HitBoxComponent.h"


class MapTiles{
private:
	void initVariable();

	vector<vector<sf::Vector2i>> map;
	vector<vector<int>> colMap;

protected:

	HitBoxComponent* tileBoxComponent;
	Player1* p1;
	Player2* p2;

	Entity magic;

	sf::Texture player1_texture;
	sf::Texture player2_texture;

public:
	MapTiles(Player1* player1, Player2* player2);
	virtual ~MapTiles();


	//variable
	sf::Texture tileTexture;
	sf::Sprite tileSprite;


	int flag = 0;

	//functions
	void loadMap(const char* filename);
	void loadColMap(const char* filename);
	void CreateHitboxComponent(sf::Sprite& sprite, float offset_x, float offset_y, float width, float height);
	const bool checkCollision();

	void update(const float& dt);
	void render(sf::RenderTarget& target);
};