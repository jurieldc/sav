#include "pch.h"
#include "GameState.h"

//initializer
void GameState::initkeybinds() {
	ifstream ifs("config/gamestate_control.ini");

	if (ifs.is_open()) {
		string key = "";
		string key2 = "";

		while (ifs >> key >> key2)
			this->keybinds[key] = this->supportedKeys->at(key2);
	}

	ifs.close();
}

void GameState::initTextures(){
	/**LOADS THEE TEXTURE FOR PLAYER 1 and PLAYER2 **/
	this->texture_player1.loadFromFile("asset/character/dragon2.png");
	this->texture_player2.loadFromFile("asset/character/wizard.png");
}
void GameState::initMapTiles(){
	/**LOAD THE TILE MAP**/
	this->map_tiles = new MapTiles(this->player1, this->player2);
}
void GameState::initPlayers(){
	/**CREATE A NEW INSTANCE OF PLAYER **/
	this->player1 = new Player1(200, 750, this->texture_player1);
	this->player2 = new Player2(100, 100, this->texture_player2);
}

//constructors/destructor
GameState::GameState(sf::RenderWindow* window, map<string, int>* supportedKeys, stack<State*>* states) : State(window, supportedKeys, states){
	this->initkeybinds();
	this->initTextures();
	this->initPlayers();
	this->initMapTiles();

	if (!(this->demoBg_Texture.loadFromFile("asset/tile/tile-look2.png")))
		cout << "Failed to load Background" << endl;
	
	this->demoBg_Sprite.setTexture(demoBg_Texture);
}

GameState::~GameState(){
	delete this->player1;
	delete this->player2;
	delete this->map_tiles;
}

//functions

void GameState::updateKeybinds(const float & dt){
	//player 1 move
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_LEFT1"))))
		this->player1->move(-1.f, 0.f, dt);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_RIGHT1"))))
		this->player1->move(1.f, 0.f, dt);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_UP1"))))
		this->player1->move(0.f, -10.f, dt);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_UP1"))))
		this->player1->move(0.f, -10.f, dt);
	//player 2 move
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_LEFT2"))))
		this->player2->move(-1.f, 0.f, dt);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_RIGHT2"))))
		this->player2->move(1.f, 0.f, dt);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_UP2")))) {
		this->player2->move(0.f, -13.f, dt);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("CLOSE"))))
		this->endState();

}

void GameState::update(const float& dt){
	this->updateMousePos();
	this->updateKeybinds(dt);
	
	this->map_tiles->update(dt);

	this->player1->update(dt);
	this->player2->update(dt);
}

void GameState::render(sf::RenderTarget* target){
	if (!target) 
		target = this->window;

	target->draw(this->demoBg_Sprite);
	this->map_tiles->render(*target);
	this->player1->render(*target);
	this->player2->render(*target);
}
