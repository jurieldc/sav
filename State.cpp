#include "pch.h"
#include "State.h"

State::State(sf::RenderWindow* window, map<string, int>* supportedKeys, stack<State*>* states){
	this->window = window;
	this->supportedKeys = supportedKeys;
	this->states = states;
	this->exit = false;
}

State::~State(){

}

const bool & State::getExit() const{
	return this->exit;
}

void State::endState(){
	this->exit = true;
}

void State::updateMousePos(){
	this->mousePosScreen = sf::Mouse::getPosition();
	this->mousePosWindow = sf::Mouse::getPosition(*this->window);
	this->mousePosView = this->window->mapPixelToCoords(sf::Mouse::getPosition(*this->window));
}
