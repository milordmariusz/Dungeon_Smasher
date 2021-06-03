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
#include "Enemy.h"
using namespace sf;
using namespace std;


class Game //Main class - game engine
{
private:
	//Window
	RenderWindow* window;
	VideoMode videoMode;
	Event ev;

	//Mouse pos
	Vector2i mousePosWindow;
	Vector2f mousePosView;

	//Resources
	Font font;
	Font font2;

	//Sound
	SoundBuffer buffer;
	Sound sound;

	//Text
	Text uiText1;
	Text uiText2;
	Text centaurInfo;
	Text goblinInfo;
	Text zombieInfo;
	Text orcInfo;

	//Menu
	RectangleShape menuBackground;
	Texture menuBackgroundTexture;
	RectangleShape buttonMenu1;
	Texture buttonMenu1Texture;
	Texture buttonMenu1ActiveTexture;
	RectangleShape buttonMenu2;
	Texture buttonMenu2Texture;
	Texture buttonMenu2ActiveTexture;
	RectangleShape buttonMenu3;
	Texture buttonMenu3Texture;
	Texture buttonMenu3ActiveTexture;
	RectangleShape buttonMenu4;
	Texture buttonMenu4Texture;
	Texture buttonMenu4ActiveTexture;

	//Bestiary
	RectangleShape BestiaryBook;
	Texture BestiaryBookTexture;
	RectangleShape buttonBestiaryNext;
	Texture buttonBestiaryNextTexture;
	Texture buttonBestiaryNextActiveTexture;
	RectangleShape buttonBestiaryBack;
	Texture buttonBestiaryBackTexture;
	Texture buttonBestiaryBackActiveTexture;
	RectangleShape buttonBestiaryExit;
	Texture buttonBestiaryExitTexture;
	Texture buttonBestiaryExitActiveTexture;
	

	//Background
	RectangleShape walls;
	Texture wallsTexture;
	RectangleShape ground;
	Texture groundTexture;
	std::vector<RectangleShape> tiles;
	RectangleShape tile;
	Texture tileTexture;
	Texture centerTexture;

	//Game logic
	string gameState = "game";
	int pageCount = 1;
	bool endGame;
	unsigned points;
	int health;
	float enemySpawnTimer;
	float enemySpawnTimerMax;
	int maxEnemies;
	bool mouseHeld;

	//center
	RectangleShape center;

	//enemies
	std::vector<Enemy> enemies;
	float animationSpeedMultiplier;
	float speedMultiplier;
	//zombie
	Texture zombieWalkTexture;
	Texture zombieAttackTexture;
	Texture zombieHitTexture;
	float zombieBaseSpeed;
	float zombieAnimationSpeed;
	float zombieValue;
	int zombieAttackValue;
	//centaur
	Texture centaurWalkTexture;
	Texture centaurAttackTexture;
	Texture centaurHitTexture;
	float centaurBaseSpeed;
	float centaurValue;
	float centaurAnimationSpeed;
	int centaurAttackValue;
	//orc
	Texture orcWalkTexture;
	Texture orcAttackTexture;
	Texture orcHitTexture;
	float orcBaseSpeed;
	float orcAnimationSpeed;
	float orcValue;
	int orcAttackValue;
	//goblin
	Texture goblinWalkTexture;
	Texture goblinAttackTexture;
	Texture goblinHitTexture;
	float goblinBaseSpeed;
	float goblinAnimationSpeed;
	float goblinValue;
	int goblinAttackValue;


	//Private functions
	void initMenu();
	void initBestiary();
	void initHighscore();
	void initCredits();
	void initCenter();
	void initVariables();
	void initWindow();
	void initFonts();
	void initSounds();
	void initText();
	void initBackground();
	void initEnemies();

public:
	//Variables
	float deltaTime = 0.0f;
	Clock clock;

	//Constructor and destructor
	Game();
	virtual ~Game();

	//Accessors
	const bool running() const;
	const bool getEndGame() const;

	//Public functions
	void spawnEnemy();
	void pollEvents();
	void updateMousePositions();
	void updateText();
	void updateEnemies();
	void updateMenu();
	void updateBestiary();
	void update();
	void renderText(RenderTarget& target);
	void renderWalls(RenderTarget& target);
	void renderGround(RenderTarget& target);
	void renderTiles(RenderTarget& target);
	void renderEnemies(RenderTarget& target);
	void render();
};