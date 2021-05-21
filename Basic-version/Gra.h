#pragma once

#include<iostream>
#include<vector>
#include<ctime>
#include<sstream>

#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<SFML/Window.hpp>
#include<SFML/Audio.hpp>
#include<SFML/Network.hpp>

using namespace sf;

//Klasa która jest tak jakby silnikiem gry

class Game
{
private:
	//Zmienne
	//Okno
	RenderWindow* window;
	VideoMode videoMode;
	Event ev;

	//Pozycja myszy
	Vector2i mousePosWindow;
	Vector2f mousePosView;

	//Zasoby
	Font font;

	//Tekst
	Text uiText;

	//Logika gry
	bool endGame;
	unsigned points;
	int health;
	float enemySpawnTimer;
	float enemySpawnTimerMax;
	int maxEnemies;
	bool mouseHeld;

	//obiekty
	std::vector<RectangleShape> enemies;
	RectangleShape enemy;


	//Funkcje prywatne
	void initVariables();
	void initWindow();
	void initFonts();
	void initText();
	void initEnemies();

public:
	//Konstruktory i destruktory
	Game();
	virtual ~Game();

	//Accessors
	const bool running() const;
	const bool getEndGame() const;

	//Funkcje
	void spawnEnemy();
	void pollEvents();
	void updateEnemies();
	void updateMousePositions();
	void updateText();
	void update();
	void renderText(RenderTarget& target);
	void renderEnemies(RenderTarget& target);
	void render();
};

