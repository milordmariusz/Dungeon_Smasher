#include "Gra.h"

//Prywatne funkcje
void Game::initVariables()
{
	this->window = nullptr;

	//Logika gry
	this->endGame = false;
	this->points = 0;
	this->health = 20;
	this->enemySpawnTimerMax = 20.f;
	this->enemySpawnTimer = this->enemySpawnTimerMax;
	this->maxEnemies = 5;
	this->mouseHeld = false;
}

void Game::initWindow()
{
	this->videoMode.height = 600;
	this->videoMode.width = 800;

	this->window = new RenderWindow(this->videoMode, "Kwadraciki", Style::Titlebar | Style::Close);

	this->window->setFramerateLimit(60);
}

void Game::initFonts()
{
	if (this->font.loadFromFile("fonts/Montserrat-Black.otf")==false)
	{
		std::cout << "ERROR::GAME::INITFONTS::Nie zaladowano czcionki :(" << std::endl;
	}
}

void Game::initText()
{
	this->uiText.setFont(this->font);
	this->uiText.setCharacterSize(24);
	this->uiText.setFillColor(Color::White);
	this->uiText.setString("NONE");
}

void Game::initEnemies()
{
	this->enemy.setPosition(10.f, 10.f);
	this->enemy.setSize(Vector2f(100.f,100.f));
	this->enemy.setFillColor(Color::Cyan);
	//this->enemy.setOutlineColor(Color::Green);
	//this->enemy.setOutlineThickness(1.f);
}

//Konstruktory i destruktory
Game::Game()
{
	this->initVariables();
	this->initWindow();
	this->initFonts();
	this->initText();
	this->initEnemies();
}

Game::~Game()
{
	delete this->window;
}

//Accessors
const bool Game::running() const
{
	return this->window->isOpen();
}

const bool Game::getEndGame() const
{
	return this->endGame;
}

//Funkcje
void Game::spawnEnemy()
{
	this->enemy.setPosition(
		static_cast<float>(rand() % static_cast<int>(this->window->getSize().x - this->enemy.getSize().x)),
		0.f);

	//losowanie przeciwnika
	int type = rand() % 5;

	switch (type)
	{
	case 0:
		this->enemy.setSize(Vector2f(20.f, 20.f));
		this->enemy.setFillColor(Color::Magenta);
		break;
	case 1:
		this->enemy.setSize(Vector2f(30.f, 30.f));
		this->enemy.setFillColor(Color::Blue);
		break;
	case 2:
		this->enemy.setSize(Vector2f(50.f, 50.f));
		this->enemy.setFillColor(Color::Cyan);
		break;
	case 3:
		this->enemy.setSize(Vector2f(70.f, 70.f));
		this->enemy.setFillColor(Color::Red);
		break;
	case 4:
		this->enemy.setSize(Vector2f(100.f, 100.f));
		this->enemy.setFillColor(Color::Green);
		break;
	default:
		this->enemy.setSize(Vector2f(100.f, 100.f));
		this->enemy.setFillColor(Color::Yellow);
		break;
	}

	//spawn przeciwnika
	this->enemies.push_back(this->enemy);


}

void Game::pollEvents()
{
	//Przeci¹ganie okna
	while (this->window->pollEvent(this->ev))
	{
		switch (this->ev.type)
		{
		case Event::Closed:
			this->window->close();
			break;
		case Event::KeyPressed:
			if (this->ev.key.code == Keyboard::Escape)
				this->window->close();
			break;

		}
	}
}

void Game::updateMousePositions()
{
	this->mousePosWindow = Mouse::getPosition(*this->window);
	this->mousePosView = this->window->mapPixelToCoords(this->mousePosWindow);
}

void Game::updateText()
{
	std::stringstream ss;
	ss << "Punkty: " << this->points<<std::endl;
	ss << "Zdrowie: " << this->health << std::endl;
	this->uiText.setString(ss.str());
}

void Game::updateEnemies()
{
	//aktualizowanie czasu do spawnu
	if (this->enemies.size() < this->maxEnemies)
	{
		if (this->enemySpawnTimer >= this->enemySpawnTimerMax)
		{
			//spawnowanie przeciwnika i resetowanie zaegara
			this->spawnEnemy();
			this->enemySpawnTimer = 0.f;
		}
		else
			this->enemySpawnTimer += 1.f;
	}

	//Poruszanie siê przeciwników
	for (int i = 0; i<this->enemies.size();i++)
	{
		bool deleted = false;
		this->enemies[i].move(0.f, 3.f);

		//Je¿eli przeciwnik dojdzie na dó³
		if (this->enemies[i].getPosition().y > this->window->getSize().y)
		{
			this->enemies.erase(this->enemies.begin() + i);
			this->health -= 1;
			std::cout << "Zdrowie: " << this->health << std::endl;
		}
	}

	//Sprawdzamy czy kliknêliœmy
	if (Mouse::isButtonPressed(Mouse::Left))
	{
		if (this->mouseHeld == false)
		{
			this->mouseHeld = true;
			bool deleted = false;
			for (size_t i = 0; i < this->enemies.size() && deleted == false; i++)
			{
				if (this->enemies[i].getGlobalBounds().contains(this->mousePosView))
				{
					//Zdobywanie punktów
					if (this->enemies[i].getFillColor() == Color::Magenta)
						this->points += 10;
					else if (this->enemies[i].getFillColor() == Color::Blue)
						this->points += 7;
					else if (this->enemies[i].getFillColor() == Color::Cyan)
						this->points += 5;
					else if (this->enemies[i].getFillColor() == Color::Red)
						this->points += 3;
					else if (this->enemies[i].getFillColor() == Color::Green)
						this->points += 1;

					std::cout << "Punkty: " << this->points << std::endl;

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

void Game::update()
{
	this->pollEvents();

	if (this->endGame == false)
	{
		this->updateMousePositions();

		this->updateText();

		this->updateEnemies();
	}

	//Zakonczenie gry
	if (this->health <= 0)
	{
		this->endGame = true;
	}
}

void Game::renderText(RenderTarget& target)
{
	target.draw(this->uiText);
}

void Game::renderEnemies(RenderTarget& target)
{
	//rysowanie przeciwników
	for (auto &e : this->enemies)
	{
		target.draw(e);
	}
}

void Game::render()
{
	/*
	-wyczyœæ
	-wyrenderuj
	-wyœwietl
	Renderowanie elementów gry
	*/

	this->window->clear();

	//Rysowanie elementów gry
	this->renderEnemies(*this->window);

	this->renderText(*this->window);

	this->window->display();
}
