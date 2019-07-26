#include "pch.h"
#include "MainMenuState.h"

void MainMenuState::initFonts() {
	if (!this->font.loadFromFile("font/gomarice_rocks.ttf"))
		throw("ERROR::MAINMENUSTATE::COULD NOT LOAD FONT");
}

void MainMenuState::initkeybinds() {

	ifstream ifs("config/mainmenu_control.ini");

	if (ifs.is_open()) {
		string key = "";
		string key2 = "";

		while (ifs >> key >> key2)
			this->keybinds[key] = this->supportedKeys->at(key2);
	}

	ifs.close();

}

void MainMenuState::initButtons() {

	/**LOADS ALL THE BUTTON IN THE MAIN MENU**/
	if (!(this->img_btn.loadFromFile("asset/bg/start_norm.png")))
		cout << "Fail to load button" << endl;

	if (!(this->imgHover_btn.loadFromFile("asset/bg/start_hover.png")))
		cout << "Fail to load button" << endl;

	this->buttons["GAME_STATE"] = new Buttons(img_btn, imgHover_btn, window->getSize().x, 300);

	if (!(this->img_btn.loadFromFile("asset/bg/credits_norm.png")))
		cout << "Fail to load button" << endl;

	if (!(this->imgHover_btn.loadFromFile("asset/bg/credits_hover.png")))
		cout << "Fail to load button" << endl;

	this->buttons["CREDIT_STATE"] = new Buttons(img_btn, imgHover_btn, window->getSize().x, 400);

	if (!(this->img_btn.loadFromFile("asset/bg/abt_norm.png")))
		cout << "Fail to load button" << endl;

	if (!(this->imgHover_btn.loadFromFile("asset/bg/abt_hover.png")))
		cout << "Fail to load button" << endl;

	this->buttons["ABOUT_STATE"] = new Buttons(img_btn, imgHover_btn, window->getSize().x, 500);

	if (!(this->img_btn.loadFromFile("asset/bg/exit_norm.png")))
		cout << "Fail to load button" << endl;

	if (!(this->imgHover_btn.loadFromFile("asset/bg/exit_hover.png")))
		cout << "Fail to load button" << endl;

	this->buttons["EXIT_STATE"] = new Buttons(img_btn, imgHover_btn, window->getSize().x, 600);
}

MainMenuState::MainMenuState(sf::RenderWindow* window, map<string, int>* supportedKeys, stack<State*>* states) : State(window, supportedKeys, states) {
	this->initFonts();
	this->initkeybinds();
	this->initButtons();
	/**BACKGROUND FOR MAIN MENU**/
	if (!(this->backgroundTexture.loadFromFile("asset/bg/bg.png")))
		cout << "Fail to load background" << endl;
	this->backgroundSprite.setTexture(backgroundTexture);

	if (!(this->titleTexture.loadFromFile("asset/bg/title.png")))
		cout << "Fail to load Title" << endl;
	this->titleSprite.setTexture(titleTexture);
	this->titleSprite.setPosition((window->getSize().x / 2) -(titleSprite.getGlobalBounds().width / 2), 60);
}

MainMenuState::~MainMenuState() {
	auto it = this->buttons.begin();
	for (it = this->buttons.begin(); it != this->buttons.end(); ++it){
		delete it->second;
	}
}

void MainMenuState::updateKeybinds(const float & dt) {

}

void MainMenuState::updateButtons(){
	for (auto &it : this->buttons)
		it.second->update(this->mousePosView);

	//start game
	if (this->buttons["GAME_STATE"]->isPressed()) {
		this->states->push(new GameState(this->window, this->supportedKeys, this->states));
	}

	if (this->buttons["CREDIT_STATE"]->isPressed()) {
		this->states->push(new CreditState(this->window, this->supportedKeys, this->states));
	}

	//about game
	if (this->buttons["ABOUT_STATE"]->isPressed()) {
		this->states->push(new AboutState(this->window, this->supportedKeys, this->states));
	}

	//quit game
	if (this->buttons["EXIT_STATE"]->isPressed())
		this->endState();
}

void MainMenuState::update(const float& dt) {
	this->updateMousePos();
	this->updateKeybinds(dt);

	this->updateButtons();
}

void MainMenuState::renderButtons(sf::RenderTarget& target){
	for (auto &it : this->buttons)
		it.second->render(target);
}

void MainMenuState::render(sf::RenderTarget* target) {
	if (!target)
		target = this->window;

	target->draw(this->backgroundSprite);
	target->draw(this->titleSprite);

	this->renderButtons(*target);
}
