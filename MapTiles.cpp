#include "pch.h"
#include "MapTiles.h"

void MapTiles::initVariable(){
	this->tileBoxComponent = NULL;
}

MapTiles::MapTiles(Player1* player1, Player2* player2) : p1(player1), p2(player2) {
	this->initVariable();

	loadMap("config/map.ini");
	loadColMap("config/colmap.ini");
}

MapTiles::~MapTiles(){
	delete this->tileBoxComponent;
}

void MapTiles::loadMap(const char * filename){

	/**DRAW ALL THE TILEMAP**/
	ifstream openfile(filename);
	vector<sf::Vector2i> tempMap;
	map.clear();

	if (openfile.is_open()) {
		string tileLocation;
		openfile >> tileLocation;
		this->tileTexture.loadFromFile(tileLocation);
		this->tileSprite.setTexture(this->tileTexture);

		while (!openfile.eof()) {
			string str, value;
			getline(openfile, str);
			stringstream Stream(str);

			while (getline(Stream, value, ' ')) {
				if (value.length() > 0) {
					string xComa = value.substr(0, value.find(','));
					string yComa = value.substr(value.find(',') + 1);

					int x, y, i, j;

					for (i = 0; i < xComa.length(); i++) {
						if (!isdigit(xComa[i]))
							break;
					}
					for (j = 0; j < yComa.length(); j++) {
						if (!isdigit(yComa[j]))
							break;
					}

					x = (i == xComa.length()) ? atoi(xComa.c_str()) : -1;
					y = (j == yComa.length()) ? atoi(yComa.c_str()) : -1;

					tempMap.push_back(sf::Vector2i(x, y));

				}
			}
			if (tempMap.size() > 0) {
				map.push_back(tempMap);
				tempMap.clear();
			}
		}
	}
	openfile.close();
	/**END**/
}

void MapTiles::loadColMap(const char * filename){
	/**COLLISION MAP**/
	ifstream openfile(filename);
	vector<int> tempMap;
	colMap.clear();

	if (openfile.is_open()) {
		while (!openfile.eof()) {
			string str, value;
			getline(openfile, str);
			stringstream Stream(str);

			while (getline(Stream, value, ' ')) {
				if (value.length() > 0) {
					int a = atoi(value.c_str());
					tempMap.push_back(a);

				}
			}
			colMap.push_back(tempMap);
			tempMap.clear();
		}
	}
	openfile.close();
	/**END**/
}

void MapTiles::CreateHitboxComponent(sf::Sprite & sprite, float offset_x, float offset_y, float width, float height){
	this->tileBoxComponent = new HitBoxComponent(sprite, offset_x, offset_y, width, height); //creates a rectangle to the tiles
}

const bool MapTiles::checkCollision(){
	if (flag == 1)
		return true;
	return false;
}

void MapTiles::update(const float& dt) {
	/**CHECKS IF THEIR IS A COLLISION**/
	for (int i = 1; i < p1->tiles.size(); i++) {
		if (colMap[p1->tiles[i].y][p1->tiles[i].x] == 1) {
			p1->setPosition(p1->getPosition().x, tileSprite.getPosition().y - 75);
			break;
		}
		else {
		}
	}
	this->tileBoxComponent->update();
}

void MapTiles::render(sf::RenderTarget & target) {
	for (int i = 0; i < map.size(); i++) {
		for (int j = 0; j < map[i].size(); j++)
			if (map[i][j].x != -1 && map[i][j].y != -1) {
				this->tileSprite.setPosition(j * 75, i * 75);
				this->tileSprite.setTextureRect(sf::IntRect(map[i][j].x * 75, map[i][j].y * 75, 75, 75));
				target.draw(this->tileSprite);
				this->CreateHitboxComponent(this->tileSprite, 1.f, 2.f, 75.f, 75.f);

			}
	}
	if (this->tileBoxComponent)
		this->tileBoxComponent->render(target);
}
