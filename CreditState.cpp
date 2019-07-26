#include "pch.h"
#include "CreditState.h"

void CreditState::initkeybinds() {

	ifstream ifs("config/mainmenu_control.ini");

	if (ifs.is_open()) {
		string key = "";
		string key2 = "";

		while (ifs >> key >> key2)
			this->keybinds[key] = this->supportedKeys->at(key2);
	}

	ifs.close();

}

CreditState::CreditState(sf::RenderWindow* window, map<string, int>* supportedKeys, stack<State*>* states) : State(window, supportedKeys, states) {
	this->initkeybinds();

	if (!(this->backgroundTexture.loadFromFile("asset/bg/credits.png")))
		cout << "Fail to load background" << endl;
	this->backgroundSprite.setTexture(backgroundTexture);

}

CreditState::~CreditState() {

}

void CreditState::updateKeybinds(const float & dt) {
	//back to main menu
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		this->endState();
}

void CreditState::updateButtons() {

}

void CreditState::update(const float& dt) {
	this->updateMousePos();
	this->updateKeybinds(dt);
}

void CreditState::renderButtons(sf::RenderTarget& target) {

}

void CreditState::render(sf::RenderTarget* target) {
	if (!target)
		target = this->window;

	target->draw(this->backgroundSprite);

}
