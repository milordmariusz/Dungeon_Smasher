#include "Game.h"

void Game::initVariables() //Initialize variables
{
	this->window = nullptr;
	this->endGame = false;
	this->points = 100;
	this->health = 20;
	this->enemySpawnTimerMax = 35.f;
	this->enemySpawnTimer = this->enemySpawnTimerMax;
	this->maxEnemies = 10;
	this->mouseHeld = false;
	//zombie
	this->zombieBaseSpeed = 50.0f;
	this->zombieAnimationSpeed = 1 / zombieBaseSpeed * 16;
	this->zombieValue = 5.0f;
	this->zombieAttackValue = 1;
	//centaur
	this->centaurBaseSpeed = 110.0f;
	this->centaurAnimationSpeed = 1 / centaurBaseSpeed * 16;
	this->centaurValue = 20.0f;
	this->centaurAttackValue = 1;
	//orc
	this->orcBaseSpeed = 80.0f;
	this->orcAnimationSpeed = 1 / orcBaseSpeed * 16;
	this->orcValue = 15.0f;
	this->orcAttackValue = 2;
	//goblin
	this->goblinBaseSpeed = 150.0f;
	this->goblinAnimationSpeed = 1 / goblinBaseSpeed * 16;
	this->goblinValue = 25.0f;
	this->goblinAttackValue = 1;
}

void Game::initCenter() //Initialize center
{
	if (this->centerTexture.loadFromFile("background/center.png") == false) //Init walls
	{
		cout << "ERROR::GAME::INITBACKGROUND::Cannot load center.png" << std::endl;
		this->center.setFillColor(Color(222, 33, 33));
	}
	else
	{
		center.setTexture(&centerTexture);
	}
	this->center.setSize(sf::Vector2f(36.0f, 36.0f));
	this->center.setPosition(sf::Vector2f(622.0f, 350.0f));
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

void Game::initSounds()
{
	if (this->buffer.loadFromFile("sounds/kill.wav") == false)
	{
		cout << "ERROR::GAME::INITSOUNDS::Cannot load sound kill.wav" << std::endl;
	}
	this->sound.setBuffer(this->buffer);
	this->sound.setVolume(10);

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
	if (this->wallsTexture.loadFromFile("background/wallsIce.png") == false) //Init walls
	{
		cout << "ERROR::GAME::INITBACKGROUND::Cannot load walls.png" << std::endl;
	}
	else
	{
		this->walls.setSize(sf::Vector2f(608.0f, 608.0f));
		this->walls.setPosition(336.0f, 64.0f);
		this->walls.setTexture(&wallsTexture);
	}

	if (this->groundTexture.loadFromFile("background/groundIce.png") == false) //Init static ground
	{
		cout << "ERROR::GAME::INITBACKGROUND::Cannot load ground.png" << std::endl;
	}
	else
	{
		this->ground.setSize(sf::Vector2f(608.0f, 608.0f));
		this->ground.setPosition(336.0f, 64.0f);
		this->ground.setTexture(&groundTexture);
	}

	if (this->tileTexture.loadFromFile("background/tilesIce.png") == false) //Init random ground pattern
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

void Game::initEnemies() //Initialize enemies - load all textures
{
	if (this->zombieWalkTexture.loadFromFile("enemies/zombieWalk.png") == false) //Init zombieWalk
	{
		cout << "ERROR::GAME::INITBACKGROUND::Cannot load texture zombieWalk.png" << std::endl;
	}
	if (this->zombieAttackTexture.loadFromFile("enemies/zombieAttack.png") == false) //Init zombieAttack
	{
		cout << "ERROR::GAME::INITBACKGROUND::Cannot load texture zombieAttack.png" << std::endl;
	}
	if (this->zombieHitTexture.loadFromFile("enemies/zombieHit.png") == false) //Init zombieHit
	{
		cout << "ERROR::GAME::INITBACKGROUND::Cannot load texture zombieHit.png" << std::endl;
	}
	if (this->centaurWalkTexture.loadFromFile("enemies/centaurWalk.png") == false) //Init centaurWalk
	{
		cout << "ERROR::GAME::INITBACKGROUND::Cannot load texture centaurWalk.png" << std::endl;
	}
	if (this->centaurAttackTexture.loadFromFile("enemies/centaurAttack.png") == false) //Init centaurAttack
	{
		cout << "ERROR::GAME::INITBACKGROUND::Cannot load texture centaurAttack.png" << std::endl;
	}
	if (this->centaurHitTexture.loadFromFile("enemies/centaurHit.png") == false) //Init centaurHit
	{
		cout << "ERROR::GAME::INITBACKGROUND::Cannot load texture centaurHit.png" << std::endl;
	}
	if (this->orcWalkTexture.loadFromFile("enemies/orcWalk.png") == false) //Init orcWalk
	{
		cout << "ERROR::GAME::INITBACKGROUND::Cannot load texture orcWalk.png" << std::endl;
	}
	if (this->orcAttackTexture.loadFromFile("enemies/orcAttack.png") == false) //Init orcAttack
	{
		cout << "ERROR::GAME::INITBACKGROUND::Cannot load texture orcAttack.png" << std::endl;
	}
	if (this->orcHitTexture.loadFromFile("enemies/orcHit.png") == false) //Init orcHit
	{
		cout << "ERROR::GAME::INITBACKGROUND::Cannot load texture orcrHit.png" << std::endl;
	}
	if (this->goblinWalkTexture.loadFromFile("enemies/goblinWalk.png") == false) //Init goblinWalk
	{
		cout << "ERROR::GAME::INITBACKGROUND::Cannot load texture goblinWalk.png" << std::endl;
	}
	if (this->goblinAttackTexture.loadFromFile("enemies/goblinAttack.png") == false) //Init goblinWalk
	{
		cout << "ERROR::GAME::INITBACKGROUND::Cannot load texture goblinAttack.png" << std::endl;
	}
	if (this->goblinHitTexture.loadFromFile("enemies/goblinHit.png") == false) //Init goblinHit
	{
		cout << "ERROR::GAME::INITBACKGROUND::Cannot load texture goblinHit.png" << std::endl;
	}
}

void Game::spawnEnemy() //Spawn enemy  
/*
Enemy name(walktexture, (number of walk frames x,number of walk frames y), attack texture, (number of attack frames x,number of attack frames y),hit texture, (number of hit frames x,number of hit frames y),
 animation speed, speed of enemy, starting position, point value, attack value)
*/
{
	int type = (rand() % 4); // Generate type of enemy 0-zombie 1-centaur 2-goblin 3-orc
	int side = (rand() % 4); // Generate spawn side  0-top 1-bottom 2-left 3-right

	switch (type)
	{
	case 0:
		if (side == 0) // Top side zombie
		{
			Enemy zombie(&zombieWalkTexture, sf::Vector2u(4, 4), &zombieAttackTexture, sf::Vector2u(5, 4), &zombieHitTexture, sf::Vector2u(4, 4), zombieAnimationSpeed*animationSpeedMultiplier, zombieBaseSpeed*speedMultiplier, sf::Vector2f((rand() % 544) + 368, 96.f), zombieValue, zombieAttackValue);
			this->enemies.push_back(zombie);
		}
		else if (side == 1) //Bottom side zombie
		{
			Enemy zombie(&zombieWalkTexture, sf::Vector2u(4, 4), &zombieAttackTexture, sf::Vector2u(5, 4), &zombieHitTexture, sf::Vector2u(4, 4), zombieAnimationSpeed * animationSpeedMultiplier, zombieBaseSpeed * speedMultiplier, sf::Vector2f((rand() % 544) + 368, 636.f), zombieValue, zombieAttackValue);
			this->enemies.push_back(zombie);
		}
		else if (side == 2) //Left side zombie
		{
			Enemy zombie(&zombieWalkTexture, sf::Vector2u(4, 4), &zombieAttackTexture, sf::Vector2u(5, 4), &zombieHitTexture, sf::Vector2u(4, 4), zombieAnimationSpeed * animationSpeedMultiplier, zombieBaseSpeed * speedMultiplier, sf::Vector2f(368.0f, (rand() % 448) + 160), zombieValue, zombieAttackValue);
			this->enemies.push_back(zombie);
		}
		else //Right side zombie
		{
			Enemy zombie(&zombieWalkTexture, sf::Vector2u(4, 4), &zombieAttackTexture, sf::Vector2u(5, 4), &zombieHitTexture, sf::Vector2u(4, 4), zombieAnimationSpeed * animationSpeedMultiplier, zombieBaseSpeed * speedMultiplier, sf::Vector2f(912.0f, (rand() % 448) + 128), zombieValue, zombieAttackValue);
			this->enemies.push_back(zombie);
		}
		break;
	case 1:

		if (side == 0)// Top side centaur
		{
			Enemy centaur(&centaurWalkTexture, sf::Vector2u(4, 4), &centaurAttackTexture, sf::Vector2u(4, 4), &centaurHitTexture, sf::Vector2u(4, 4), centaurAnimationSpeed * animationSpeedMultiplier, centaurBaseSpeed * speedMultiplier, sf::Vector2f((rand() % 544) + 368, 96.f), centaurValue, centaurAttackValue);
			this->enemies.push_back(centaur);
		}
		else if (side == 1)//Bottom side centaur
		{
			Enemy centaur(&centaurWalkTexture, sf::Vector2u(4, 4), &centaurAttackTexture, sf::Vector2u(4, 4), &centaurHitTexture, sf::Vector2u(4, 4), centaurAnimationSpeed * animationSpeedMultiplier, centaurBaseSpeed * speedMultiplier, sf::Vector2f((rand() % 544) + 368, 636.f), centaurValue, centaurAttackValue);
			this->enemies.push_back(centaur);
		}
		else if (side == 2)//Left side centaur
		{
			Enemy centaur(&centaurWalkTexture, sf::Vector2u(4, 4), &centaurAttackTexture, sf::Vector2u(4, 4), &centaurHitTexture, sf::Vector2u(4, 4), centaurAnimationSpeed * animationSpeedMultiplier, centaurBaseSpeed * speedMultiplier, sf::Vector2f(368.0f, (rand() % 448) + 160), centaurValue, centaurAttackValue);
			this->enemies.push_back(centaur);
		}
		else//Right side centaur
		{
			Enemy centaur(&centaurWalkTexture, sf::Vector2u(4, 4), &centaurAttackTexture, sf::Vector2u(4, 4), &centaurHitTexture, sf::Vector2u(4, 4), centaurAnimationSpeed * animationSpeedMultiplier, centaurBaseSpeed * speedMultiplier, sf::Vector2f(912.0f, (rand() % 448) + 128), centaurValue, centaurAttackValue);
			this->enemies.push_back(centaur);
		}
		break;
	case 2:
		if (side == 0)// Top side goblin
		{
			Enemy goblin(&goblinWalkTexture, sf::Vector2u(4, 4), &goblinAttackTexture, sf::Vector2u(4, 4), &goblinHitTexture, sf::Vector2u(4, 4), goblinAnimationSpeed * animationSpeedMultiplier, goblinBaseSpeed * speedMultiplier, sf::Vector2f((rand() % 544) + 368, 96.f), goblinValue, goblinAttackValue);
			this->enemies.push_back(goblin);
		}
		else if (side == 1)//Bottom side goblin
		{
			Enemy goblin(&goblinWalkTexture, sf::Vector2u(4, 4), &goblinAttackTexture, sf::Vector2u(4, 4), &goblinHitTexture, sf::Vector2u(4, 4), goblinAnimationSpeed * animationSpeedMultiplier, goblinBaseSpeed * speedMultiplier, sf::Vector2f((rand() % 544) + 368, 636.f), goblinValue, goblinAttackValue);
			this->enemies.push_back(goblin);
		}
		else if (side == 2)//Left side goblin
		{
			Enemy goblin(&goblinWalkTexture, sf::Vector2u(4, 4), &goblinAttackTexture, sf::Vector2u(4, 4), &goblinHitTexture, sf::Vector2u(4, 4), goblinAnimationSpeed * animationSpeedMultiplier, goblinBaseSpeed * speedMultiplier, sf::Vector2f(368.0f, (rand() % 448) + 160), goblinValue, goblinAttackValue);
			this->enemies.push_back(goblin);
		}
		else//Right side goblin
		{
			Enemy goblin(&goblinWalkTexture, sf::Vector2u(4, 4), &goblinAttackTexture, sf::Vector2u(4, 4), &goblinHitTexture, sf::Vector2u(4, 4), goblinAnimationSpeed * animationSpeedMultiplier, goblinBaseSpeed * speedMultiplier, sf::Vector2f(912.0f, (rand() % 448) + 128), goblinValue, goblinAttackValue);
			this->enemies.push_back(goblin);
		}
		break;
	case 3:

		if (side == 0)// Top side orc
		{
			Enemy orc(&orcWalkTexture, sf::Vector2u(4, 4), &orcAttackTexture, sf::Vector2u(4, 4), &orcHitTexture, sf::Vector2u(4, 4), orcAnimationSpeed * animationSpeedMultiplier, orcBaseSpeed * speedMultiplier, sf::Vector2f((rand() % 544) + 368, 96.f), orcValue, orcAttackValue);
			this->enemies.push_back(orc);
		}
		else if (side == 1)//Bottom side orc
		{
			Enemy centaur(&orcWalkTexture, sf::Vector2u(4, 4), &orcAttackTexture, sf::Vector2u(4, 4), &orcHitTexture, sf::Vector2u(4, 4), orcAnimationSpeed * animationSpeedMultiplier, orcBaseSpeed * speedMultiplier, sf::Vector2f((rand() % 544) + 368, 636.f), orcValue, orcAttackValue);
			this->enemies.push_back(centaur);
		}
		else if (side == 2)//Left side orc
		{
			Enemy centaur(&orcWalkTexture, sf::Vector2u(4, 4), &orcAttackTexture, sf::Vector2u(4, 4), &orcHitTexture, sf::Vector2u(4, 4), orcAnimationSpeed * animationSpeedMultiplier, orcBaseSpeed * speedMultiplier, sf::Vector2f(368.0f, (rand() % 448) + 160), orcValue, orcAttackValue);
			this->enemies.push_back(centaur);
		}
		else//Right side orc
		{
			Enemy centaur(&orcWalkTexture, sf::Vector2u(4, 4), &orcAttackTexture, sf::Vector2u(4, 4), &orcHitTexture, sf::Vector2u(4, 4), orcAnimationSpeed * animationSpeedMultiplier, orcBaseSpeed * speedMultiplier, sf::Vector2f(912.0f, (rand() % 448) + 128), orcValue, orcAttackValue);
			this->enemies.push_back(centaur);
		}
		break;
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
	this->initSounds();
	this->initText();
	this->initBackground();
	this->initEnemies();
	this->initCenter();
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
	ss1 << "POINTS"  << endl << this->points;
	ss2 << "HEALTH" << endl << this->health;
	this->uiText1.setString(ss1.str());
	this->uiText2.setString(ss2.str());
}

void Game::updateEnemies()
{
	this->animationSpeedMultiplier = float(5 / log(this->points)); //increasing speed over time
	this->speedMultiplier = float(log(this->points) / 5);

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

	for (size_t i = 0; i < this->enemies.size(); i++) //Check if enemy is able to attack and delete enemy after attack
	{
		if (enemies[i].attackFinished)
		{
			this->enemies.erase(this->enemies.begin() + i);
			this->health -= enemies[i].attackPower;
		}
		if (this->enemies[i].getEnemyBounds().contains(Vector2f(622.0f, 354.0f)) || this->enemies[i].getEnemyBounds().contains(Vector2f(658.0f, 354.0f)) || this->enemies[i].getEnemyBounds().contains(Vector2f(622.0f, 382.0f)) || this->enemies[i].getEnemyBounds().contains(Vector2f(658.0f, 382.0f)))
		{
			this->enemies[i].state = 1;
		}
	}

	if (Mouse::isButtonPressed(Mouse::Left))//Mouse collision with enemy object and delete this objects
	{
		if (this->mouseHeld == false)
		{
			this->mouseHeld = true;
			bool deleted = false;
			for (size_t i = 0; i < this->enemies.size() && deleted == false; i++)
			{
				if (this->enemies[i].getEnemyBounds().contains(this->mousePosView))
				{
					this->points += this->enemies[i].value;
					deleted = true;
					this->sound.play();
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
	window->draw(center);
	this->window->clear(Color(11,11,11));
	this->renderGround(*this->window);
	this->renderTiles(*this->window);
	window->draw(center);
	this->renderEnemies(*this->window);
	this->renderWalls(*this->window);
	this->renderText(*this->window);
	this->window->display();
}