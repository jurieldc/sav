#include "pch.h"
#include "AboutState.h"

void AboutState::initkeybinds() {

	ifstream ifs("config/mainmenu_control.ini");

	if (ifs.is_open()) {
		string key = "";
		string key2 = "";

		while (ifs >> key >> key2)
			this->keybinds[key] = this->supportedKeys->at(key2);
	}

	ifs.close();

}

AboutState::AboutState(sf::RenderWindow* window, map<string, int>* supportedKeys, stack<State*>* states) : State(window, supportedKeys, states) {
	this->initkeybinds();

	if (!(this->backgroundTexture.loadFromFile("asset/bg/about.png")))
		cout << "Fail to load background" << endl;
	this->backgroundSprite.setTexture(backgroundTexture);

}

AboutState::~AboutState() {

}

void AboutState::updateKeybinds(const float & dt) {
	//back to main menu
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		this->endState();
}

void AboutState::updateButtons() {

}

void AboutState::update(const float& dt) {
	this->updateMousePos();
	this->updateKeybinds(dt);
}

void AboutState::renderButtons(sf::RenderTarget& target) {

}

void AboutState::render(sf::RenderTarget* target) {
	if (!target)
		target = this->window;

	target->draw(this->backgroundSprite);

}
