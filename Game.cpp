#include "pch.h"
#include "Game.h"

//static functions

//init function
void Game::initWindow() {
	/**INITIALIZES THE WINDOW**/
	ifstream ifs("config/window.ini");

	string title = "None";
	sf::VideoMode windowSize(1200, 900);
	unsigned framerateLimit = 60;
	bool vse = false;

	if (ifs.is_open()) {
		getline(ifs, title);
		ifs >> windowSize.width >> windowSize.height;
		ifs >> framerateLimit;
		ifs >> vse;
	}
	ifs.close();

	this->window = new sf::RenderWindow(windowSize, title);
	this->window->setFramerateLimit(framerateLimit);
	this->window->setVerticalSyncEnabled(vse);
}

void Game::initKeys() {
	/**INITIALIZES THE KEYS THAT ARE AVAILABLE TO USE IN THE GAME, CAN BE UPDATED IN config folder**/
	ifstream ifs("config/control.ini");

	if (ifs.is_open()) {
		string key = "";
		int keyVal = 0;

		while (ifs >> key >> keyVal)
			this->supportedKeys[key] = keyVal;
	}
	ifs.close();

	//SHOWS IN THE CONSOLE THE GAME CONTROL, CAN BE EDITED IN config folder
	for (auto i : this->supportedKeys)
		cout << i.first << " " << i.second << endl;
}

void Game::initStates(){
	//initializes the state to the Main Menu
	this->states.push(new MainMenuState(this->window, &this->supportedKeys, &this->states));
}

//constructors/destructors

Game::Game(){
	this->initWindow();
	this->initKeys();
	this->initStates();
}


Game::~Game(){
	delete this->window;

	while(!this->states.empty()) {
		delete this->states.top();
		this->states.pop();
	}
}

//functions
void Game::endApplication(){
	cout << "Ending Game";
}

void Game::updateDt(){
	//update dt the time it take to update and render 1 frame
	this->dt = this->dtClock.restart().asSeconds();
	
}

void Game::updateSFMLEvents(){
	sfEventCopy = &sfEvent;
	while (this->window->pollEvent(this->sfEvent)) {
		if (this->sfEvent.type == sf::Event::Closed)
			this->window->close();
	}
}

void Game::update(){
	this->updateSFMLEvents();

	if (!this->states.empty()) {
		this->states.top()->update(this->dt);
		if (this->states.top()->getExit()) {
			this->states.top()->endState();
			delete this->states.top();
			this->states.pop();
		}
	}
	//Application end
	else {
		this->endApplication();
		this->window->close();
	}
}

void Game::render(){
	this->window->clear();

	//render items
	if (!this->states.empty())
		this->states.top()->render();

	this->window->display();
}

void Game::run(){
	while (this->window->isOpen()) {
		this->updateDt();
		this->update();
		this->render();
	}
}
