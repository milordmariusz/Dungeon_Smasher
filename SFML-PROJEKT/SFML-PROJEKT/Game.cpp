#include "Game.h"

void Game::initVariables() //Initialize variables
{
	this->window = nullptr;

	this->endGame = false;
	this->points = 0;
	this->health = 20;
	this->enemySpawnTimerMax = 100.f;
	this->enemySpawnTimer = this->enemySpawnTimerMax;
	this->maxEnemies = 8;
	this->mouseHeld = false;
}

void Game::initWindow() //Initialize window
{
	this->videoMode.height = 720;
	this->videoMode.width = 1280;
	this->window = new RenderWindow(this->videoMode, "Programowanie 2 - Arkadiusz Stencel, Mariusz Wróbel", Style::Titlebar | Style::Close | Style::Resize);
	this->window->setFramerateLimit(60);
}

void Game::initFonts() //Initialize fonts
{
	if (this->font.loadFromFile("fonts/ThaleahFat.ttf") == false)
	{
		cout << "ERROR::GAME::INITFONTS::Cannot load font ThaleahFat.ttf" << std::endl;
	}
}

void Game::initText() //Initialize text
{
	this->uiText1.setFont(this->font);
	this->uiText1.setCharacterSize(64);
	this->uiText1.setFillColor(Color::White);
	this->uiText1.setString("ERROR");
	this->uiText1.setPosition(88.0f, 128.0f);

	this->uiText2.setFont(this->font);
	this->uiText2.setCharacterSize(64);
	this->uiText2.setFillColor(Color::White);
	this->uiText2.setString("ERROR");
	this->uiText2.setPosition(1018.0f, 128.0f);
}

void Game::initBackground() //Initialize background
{
	if (this->wallsTexture.loadFromFile("background/walls.png") == false) //Init walls
	{
		cout << "ERROR::GAME::INITBACKGROUND::Cannot load walls.png" << std::endl;
	}
	else
	{
		this->walls.setSize(sf::Vector2f(608.0f, 608.0f));
		this->walls.setPosition(336.0f, 64.0f);
		this->walls.setTexture(&wallsTexture);
	}

	if (this->groundTexture.loadFromFile("background/ground.png") == false) //Init static ground
	{
		cout << "ERROR::GAME::INITBACKGROUND::Cannot load ground.png" << std::endl;
	}
	else
	{
		this->ground.setSize(sf::Vector2f(608.0f, 608.0f));
		this->ground.setPosition(336.0f, 64.0f);
		this->ground.setTexture(&groundTexture);
	}

	if (this->tileTexture.loadFromFile("background/tiles.png") == false) //Init random ground pattern
	{
		cout << "ERROR::GAME::INITBACKGROUND::Cannot load plates.png" << std::endl;
	}
	else //Generate random ground pattern
	{
		for (int i = 0; i < 17; i++)
		{
			for (int j = 0; j < 16; j++)
			{
				int r1 = rand() % 100;
				if (r1 > 80)
				{
					this->tile.setSize(sf::Vector2f(32.0f, 32.0f));
					this->tile.setTexture(&tileTexture);
					this->tile.setPosition(Vector2f(368.0f + i * 32.0f, 128.0f + j * 32.0f));
					this->tile.setTextureRect(IntRect(32 * (rand() % 6), 32 * (rand() % 1), 32, 32));
				}
				this->tiles.push_back(this->tile);
			}
		}
	}
}

void Game::initEnemies() //Initialize enemies
{
	if (this->zombieTexture.loadFromFile("enemies/zombie.png") == false) //Init walls
	{
		cout << "ERROR::GAME::INITBACKGROUND::Cannot load texture zombie.png" << std::endl;
	}
}

void Game::spawnEnemy() //Spawn enemy
{
	int r0 = (rand() % 4); // Generate spawn side
	if (r0 == 0)
	{
		Enemy zombie(&zombieTexture, sf::Vector2u(4, 4), 0.35f, 50.0f, sf::Vector2f((rand() % 544) + 368, 96.f));
		this->enemies.push_back(zombie);
	}
	else if (r0 == 1)
	{
		Enemy zombie(&zombieTexture, sf::Vector2u(4, 4), 0.35f, 50.0f, sf::Vector2f((rand() % 544) + 368, 636.f));
		this->enemies.push_back(zombie);
	}
	else if (r0 == 2)
	{
		Enemy zombie(&zombieTexture, sf::Vector2u(4, 4), 0.35f, 50.0f, sf::Vector2f(368.0f, (rand() % 448) + 160));
		this->enemies.push_back(zombie);
	}
	else
	{
		Enemy zombie(&zombieTexture, sf::Vector2u(4, 4), 0.35f, 50.0f, sf::Vector2f(912.0f, (rand() % 448) + 128));
		this->enemies.push_back(zombie);
	}
}


const bool Game::running() const //Is game running or not
{
	return this->window->isOpen();
}

const bool Game::getEndGame() const
{
	return this->endGame;
}

Game::Game() //Game constructor - initialize all things on startup
{
	this->initVariables();
	this->initWindow();
	this->initFonts();
	this->initText();
	this->initBackground();
	this->initEnemies();
}

Game::~Game() //Game destructor - turn off game
{
	delete this->window;
}

void Game::pollEvents() //Events
{
	while (this->window->pollEvent(this->ev))
	{
		switch (this->ev.type)
		{
		case Event::Closed: //Closing the game
			this->window->close();
			break;
		case Event::KeyPressed: //Closing game with escape key
			if (this->ev.key.code == Keyboard::Escape)
				this->window->close();
			break;
		}
	}
}

void Game::updateMousePositions()//Update mouse position
{
	this->mousePosWindow = Mouse::getPosition(*this->window);
	this->mousePosView = this->window->mapPixelToCoords(this->mousePosWindow);
}

void Game::updateText()//Update text values
{
	stringstream ss1;
	stringstream ss2;
	ss1 << "POINTS"  << std::endl;
	ss2 << "HEALTH " << std::endl;
	this->uiText1.setString(ss1.str());
	this->uiText2.setString(ss2.str());
}

void Game::updateEnemies()
{
	if (this->enemies.size() < this->maxEnemies)
	{
		if (this->enemySpawnTimer >= this->enemySpawnTimerMax) //spawn enemy and restart spawnclock
		{
			this->spawnEnemy();
			this->enemySpawnTimer = 0.f;
		}
		else
			this->enemySpawnTimer += 1.f;
}

	for (auto& e : this->enemies) // add enemy object to enemies vector
	{
		e.Update(deltaTime);
	}

	////aktualizowanie czasu do spawnu
	//if (this->enemies.size() < this->maxEnemies)
	//{
	//	if (this->enemySpawnTimer >= this->enemySpawnTimerMax)
	//	{
	//		//spawnowanie przeciwnika i resetowanie zaegara
	//		this->spawnEnemy();
	//		this->enemySpawnTimer = 0.f;
	//	}
	//	else
	//		this->enemySpawnTimer += 1.f;
	//}


	//	////Je¿eli przeciwnik dojdzie na dó³
	//	//if (this->enemies[i].getPosition().y > this->window->getSize().y)
	//	//{
	//	//	this->enemies.erase(this->enemies.begin() + i);
	//	//	this->health -= 1;
	//	//	std::cout << "Zdrowie: " << this->health << std::endl;
	//	//}
	//}

	if (Mouse::isButtonPressed(Mouse::Left))	//Mouse collision with enemy object and delete this objects
	{
		if (this->mouseHeld == false)
		{
			this->mouseHeld = true;
			bool deleted = false;
			for (size_t i = 0; i < this->enemies.size() && deleted == false; i++)
			{
				if (this->enemies[i].getEnemyBounds().contains(this->mousePosView))
				{
					deleted = true;
					this->enemies.erase(this->enemies.begin() + i);
				}
			}
		}
	}
	else
	{
		this->mouseHeld = false;
	}
}

void Game::update() //Update all elements to update + events + update deltaTime
{
	this->pollEvents();

	deltaTime = clock.restart().asSeconds();
	if (deltaTime > 1.0f / 60.0f)
		deltaTime = 1.0f / 60.0f;

	if (this->endGame == false)
	{
		this->updateMousePositions();

		this->updateText();

		this->updateEnemies();
	}
}

void Game::renderText(RenderTarget& target)//Render text
{
	target.draw(this->uiText1);
	target.draw(this->uiText2);
}

void Game::renderWalls(RenderTarget& target)//Render walls
{
	target.draw(this->walls);
}

void Game::renderGround(RenderTarget& target)//Render static ground
{
	target.draw(this->ground);
}

void Game::renderTiles(RenderTarget& target)//Render pattern of ground
{
	for (auto& e : this->tiles)
	{
		target.draw(e);
	}
}

void Game::renderEnemies(RenderTarget& target) // Render all enemies
{
	for (auto& e : this->enemies)
	{
		e.Draw(*this->window);
	}
}

void Game::render()//Render all elements to render
{
	this->window->clear(Color(11,11,11));

	this->renderGround(*this->window);
	this->renderTiles(*this->window);
	this->renderEnemies(*this->window);
	this->renderWalls(*this->window);
	this->renderText(*this->window);
	this->window->display();
}