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

	//Text
	Text uiText1;
	Text uiText2;

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
	void initCenter();
	void initVariables();
	void initWindow();
	void initFonts();
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
	void update();
	void updateEnemies();
	void renderText(RenderTarget& target);
	void renderWalls(RenderTarget& target);
	void renderGround(RenderTarget& target);
	void renderTiles(RenderTarget& target);
	void renderEnemies(RenderTarget& target);
	void render();
};