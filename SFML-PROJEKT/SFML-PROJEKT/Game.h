#pragma once
#include<iostream>
#include <fstream>
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
	Text healthInfo;
	Text pointsInfo;
	Text centaurInfo;
	Text goblinInfo;
	Text zombieInfo;
	Text orcInfo;
	Text vanillaLevel;
	Text iceLevel;
	Text hellLevel;
	Text highscoreKillscreen;
	Text highscoreInfo;

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

	//Levels
	RectangleShape wallBackground;
	Texture wallBackgroundTexture;
	RectangleShape buttonLevelsVanilla;
	Texture buttonLevelsVanillaTexture;
	Texture buttonLevelsVanillaActiveTexture;
	RectangleShape buttonLevelsIce;
	Texture buttonLevelsIceTexture;
	Texture buttonLevelsIceActiveTexture;
	RectangleShape buttonLevelsHell;
	Texture buttonLevelsHellTexture;
	Texture buttonLevelsHellActiveTexture;

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

	//Highscore
	RectangleShape highscoreBook;
	Texture highscoreBookTexture;
	RectangleShape buttonHighscoreExit;
	Texture buttonHighscoreExitTexture;
	Texture buttonHighscoreExitActiveTexture;

	//Credits
	RectangleShape CreditsBook;
	Texture CreditsBookTexture;
	RectangleShape buttonCreditsExit;
	Texture buttonCreditsExitTexture;
	Texture buttonCreditsExitActiveTexture;

	//Killscreen
	RectangleShape killscreenBackground;
	Texture killscreenBackgroundTexture;
	RectangleShape buttonKillscreenExit;
	Texture buttonKillscreenExitTexture;
	Texture buttonKillscreenExitActiveTexture;
	RectangleShape buttonKillscreenSave;
	Texture buttonKillscreenSaveTexture;
	Texture buttonKillscreenSaveActiveTexture;
	
	//Background
	RectangleShape walls;
	Texture wallsTexture;
	Texture wallsHellTexture;
	Texture wallsIceTexture;
	RectangleShape ground;
	Texture groundTexture;
	Texture groundHellTexture;
	Texture groundIceTexture;
	std::vector<RectangleShape> tiles;
	RectangleShape tile;
	Texture tileTexture;
	Texture tileIceTexture;
	Texture tileHellTexture;
	Texture centerTexture;

	//Game logic
	string difficulty = "easy";
	string gameState = "menu";
	int pageCount = 1;
	bool endGame;
	unsigned long long points;
	unsigned specialEnemyRespCap;
	int health;
	float enemySpawnTimer;
	float enemySpawnTimerMax;
	int maxEnemies;
	bool mouseHeld;

	//center
	RectangleShape center;

	//enemies
	std::vector<Enemy> enemies;
	//zombie
	Texture zombieWalkTexture;
	Texture zombieAttackTexture;
	Texture zombieHellWalkTexture;
	Texture zombieHellAttackTexture;
	float zombieBaseSpeed;
	float zombieAnimationSpeed;
	float zombieValue;
	int zombieAttackValue;
	//centaur
	Texture centaurWalkTexture;
	Texture centaurAttackTexture;
	Texture centaurHellWalkTexture;
	Texture centaurHellAttackTexture;
	float centaurBaseSpeed;
	float centaurValue;
	float centaurAnimationSpeed;
	int centaurAttackValue;
	//orc
	Texture orcWalkTexture;
	Texture orcAttackTexture;
	Texture orcHellWalkTexture;
	Texture orcHellAttackTexture;
	float orcBaseSpeed;
	float orcAnimationSpeed;
	float orcValue;
	int orcAttackValue;
	//goblin
	Texture goblinWalkTexture;
	Texture goblinAttackTexture;
	Texture goblinHellWalkTexture;
	Texture goblinHellAttackTexture;
	float goblinBaseSpeed;
	float goblinAnimationSpeed;
	float goblinValue;
	int goblinAttackValue;
	//yeti
	Texture yetiWalkTexture;
	Texture yetiAttackTexture;
	float yetiBaseSpeed;
	float yetiAnimationSpeed;
	float yetiValue;
	int yetiAttackValue;
	//wargo
	Texture wargoWalkTexture;
	Texture wargoAttackTexture;
	float wargoBaseSpeed;
	float wargoAnimationSpeed;
	float wargoValue;
	int wargoAttackValue;

	//Private functions
	void initMenu();
	void initLevels();
	void initBestiary();
	void initHighscore();
	void initCredits();
	void initKillscreen();
	void initCenter();
	void initVariables();
	void initWindow();
	void initFonts();
	void initSounds();
	void initText();
	void initBackground();
	void initEnemies();
	void generateTiles(Texture& tiles);

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
	void saveScore();
	void spawnEnemy();
	void pollEvents();
	void updateMousePositions();
	void updateText();
	void updateEnemies();
	void updateMenu();
	void updateLevels();
	void updateBestiary();
	void updateCredits();
	void updateKillscreen();
	void updateHighscore();
	void update();
	void renderText(RenderTarget& target);
	void renderTiles(RenderTarget& target);
	void renderEnemies(RenderTarget& target);
	void render();
};