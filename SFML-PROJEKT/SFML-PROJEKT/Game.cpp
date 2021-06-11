#include "Game.h"

//////////////////// Initialize things ////////////////////

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
	this->specialEnemyRespCap = 2500;
	//zombie
	this->zombieBaseSpeed = 55.0f;
	this->zombieAnimationSpeed = 1 / zombieBaseSpeed * 16;
	this->zombieValue = 5.0f;
	this->zombieAttackValue = 1;
	//centaur
	this->centaurBaseSpeed = 100.0f;
	this->centaurAnimationSpeed = 1 / centaurBaseSpeed * 16;
	this->centaurValue = 25.0f;
	this->centaurAttackValue = 2;
	//orc
	this->orcBaseSpeed = 75.0f;
	this->orcAnimationSpeed = 1 / orcBaseSpeed * 16;
	this->orcValue = 15.0f;
	this->orcAttackValue = 3;
	//goblin
	this->goblinBaseSpeed = 120.0f;
	this->goblinAnimationSpeed = 1 / goblinBaseSpeed * 16;
	this->goblinValue = 20.0f;
	this->goblinAttackValue = 1;
	//yeti
	this->yetiBaseSpeed = 85.0f;
	this->yetiAnimationSpeed = 1 / yetiBaseSpeed * 16;
	this->yetiValue = 25.0f;
	this->yetiAttackValue = 3;
	//wargo
	this->wargoBaseSpeed = 90.0f;
	this->wargoAnimationSpeed = 1 / wargoBaseSpeed * 16;
	this->wargoValue = 30.0f;
	this->wargoAttackValue = 3;
}

void Game::initMenu() //initialize menu
{
	if (this->buttonMenu1ActiveTexture.loadFromFile("buttons/startActive.png") == false) //Init start button 1 active
	{
		cout << "ERROR::GAME::INITBACKGROUND::Cannot load startActive.png" << std::endl;
	}
	if (this->buttonMenu1Texture.loadFromFile("buttons/startDefault.png") == false) //Init start button 1
	{
		cout << "ERROR::GAME::INITBACKGROUND::Cannot load startDefault.png" << std::endl;
	}
	else
	{
		this->buttonMenu1.setSize(sf::Vector2f(190.0f, 89.0f));
		this->buttonMenu1.setPosition(sf::Vector2f(50.0f, 490.0f));
		this->buttonMenu1.setTexture(&buttonMenu1Texture);
	}

	if (this->buttonMenu2ActiveTexture.loadFromFile("buttons/highscoreActive.png") == false) //Init start button 1 active
	{
		cout << "ERROR::GAME::INITBACKGROUND::Cannot load highscoreActive.png" << std::endl;
	}
	if (this->buttonMenu2Texture.loadFromFile("buttons/highscoreDefault.png") == false) //Init start button 1
	{
		cout << "ERROR::GAME::INITBACKGROUND::Cannot load highscoreDefault.png" << std::endl;
	}
	else
	{
		this->buttonMenu2.setSize(sf::Vector2f(354.0f, 103.0f));
		this->buttonMenu2.setPosition(sf::Vector2f(290.0f, 490.0f));
		this->buttonMenu2.setTexture(&buttonMenu2Texture);
	}

	if (this->buttonMenu3ActiveTexture.loadFromFile("buttons/bestiaryActive.png") == false) //Init start button 1 active
	{
		cout << "ERROR::GAME::INITBACKGROUND::Cannot load bestiaryActive.png" << std::endl;
	}
	if (this->buttonMenu3Texture.loadFromFile("buttons/bestiaryDefault.png") == false) //Init start button 1
	{
		cout << "ERROR::GAME::INITBACKGROUND::Cannot load bestiaryDefault.png" << std::endl;
	}
	else
	{
		this->buttonMenu3.setSize(sf::Vector2f(307.0f, 111.0f));
		this->buttonMenu3.setPosition(sf::Vector2f(660.0f, 480.0f));
		this->buttonMenu3.setTexture(&buttonMenu3Texture);
	}

	if (this->buttonMenu4ActiveTexture.loadFromFile("buttons/creditsActive.png") == false) //Init start button 1 active
	{
		cout << "ERROR::GAME::INITBACKGROUND::Cannot load creditsActive.png" << std::endl;
	}
	if (this->buttonMenu4Texture.loadFromFile("buttons/creditsDefault.png") == false) //Init start button 1
	{
		cout << "ERROR::GAME::INITBACKGROUND::Cannot load creditsDefault.png" << std::endl;
	}
	else
	{
		this->buttonMenu4.setSize(sf::Vector2f(253.0f, 88.0f));
		this->buttonMenu4.setPosition(sf::Vector2f(980.0f, 490.0f));
		this->buttonMenu4.setTexture(&buttonMenu4Texture);
	}
}

void Game::initLevels()
{
	if (this->wallBackgroundTexture.loadFromFile("background/wall.png") == false) //Init book
	{
		cout << "ERROR::GAME::INITLEVELS::Cannot load wall.png" << std::endl;
	}
	else
	{
		this->wallBackground.setSize(sf::Vector2f(1280.0f, 509.0f));
		this->wallBackground.setPosition(sf::Vector2f(0.0f, 0.0f));
		this->wallBackground.setTexture(&wallBackgroundTexture);
	}
	if (this->buttonLevelsVanillaTexture.loadFromFile("buttons/vanillaGateDefault.png") == false) //Init book
	{
		cout << "ERROR::GAME::INITLEVELS::Cannot load vanillaGateDefault.png" << std::endl;
	}
	if (this->buttonLevelsVanillaActiveTexture.loadFromFile("buttons/vanillaGateActive.png") == false) //Init book
	{
		cout << "ERROR::GAME::INITLEVELS::Cannot load vanillaGateActive.png" << std::endl;
	}
	else
	{
		this->buttonLevelsVanilla.setSize(sf::Vector2f(350.0f, 500.0f));
		this->buttonLevelsVanilla.setPosition(sf::Vector2f(57.0f, -80.0f));
		this->buttonLevelsVanilla.setTexture(&buttonLevelsVanillaTexture);
	}

	if (this->buttonLevelsIceTexture.loadFromFile("buttons/IceGateDefault.png") == false) //Init book
	{
		cout << "ERROR::GAME::INITLEVELS::Cannot load IceGateDefault.png" << std::endl;
	}
	if (this->buttonLevelsIceActiveTexture.loadFromFile("buttons/IceGateActive.png") == false) //Init book
	{
		cout << "ERROR::GAME::INITLEVELS::Cannot load IceGateActive.png" << std::endl;
	}
	else
	{
		this->buttonLevelsIce.setSize(sf::Vector2f(350.0f, 500.0f));
		this->buttonLevelsIce.setPosition(sf::Vector2f(465.0f, -80.0f));
		this->buttonLevelsIce.setTexture(&buttonLevelsIceTexture);
	}

	if (this->buttonLevelsHellTexture.loadFromFile("buttons/HellGateDefault.png") == false) //Init book
	{
		cout << "ERROR::GAME::INITLEVELS::Cannot load HellGateDefault.png" << std::endl;
	}
	if (this->buttonLevelsHellActiveTexture.loadFromFile("buttons/HellGateActive.png") == false) //Init book
	{
		cout << "ERROR::GAME::INITLEVELS::Cannot load HellGateActive.png" << std::endl;
	}
	else
	{
		this->buttonLevelsHell.setSize(sf::Vector2f(350.0f, 500.0f));
		this->buttonLevelsHell.setPosition(sf::Vector2f(872.0f, -80.0f));
		this->buttonLevelsHell.setTexture(&buttonLevelsHellTexture);
	}

	stringstream vl;
	vl << "Dungeon" << endl << "     Easy";
	this->vanillaLevel.setString(vl.str());

	stringstream il;
	il << "Ice Cave" << endl << " Normal";
	this->iceLevel.setString(il.str());

	stringstream hl;
	hl << " Hell" << endl << "Hard";
	this->hellLevel.setString(hl.str());
}

void Game::initBestiary() //initialize bestiary
{
	if (this->BestiaryBookTexture.loadFromFile("background/Book.png") == false) //Init book
	{
		cout << "ERROR::GAME::INITBESTIARY::Cannot load menuBackground.png" << std::endl;
	}
	else
	{
		this->BestiaryBook.setSize(sf::Vector2f(1234.0f, 700.0f));
		this->BestiaryBook.setPosition(sf::Vector2f(20.0f, 10.0f));
		this->BestiaryBook.setTexture(&BestiaryBookTexture);
	}
	if (this->buttonBestiaryBackActiveTexture.loadFromFile("buttons/backActive.png") == false)//init back
	{
		cout<< "ERROR::GAME::INITBESTIARY::Cannot load backActive.png" << std::endl;
	}
	if (this->buttonBestiaryBackTexture.loadFromFile("buttons/backDefault.png") == false)//init back
	{
		cout << "ERROR::GAME::INITBESTIARY::Cannot load backDefault.png" << std::endl;
	}
	else
	{
		this->buttonBestiaryBack.setSize(sf::Vector2f(150.0f, 150.0f));
		this->buttonBestiaryBack.setPosition(sf::Vector2f(650.0f, 500.0f));
		this->buttonBestiaryBack.setTexture(&buttonBestiaryBackTexture);
	}

	if (this->buttonBestiaryExitActiveTexture.loadFromFile("buttons/exitActive.png") == false)//init back
	{
		cout << "ERROR::GAME::INITBESTIARY::Cannot load exitActive.png" << std::endl;
	}
	if (this->buttonBestiaryExitTexture.loadFromFile("buttons/exitDefault.png") == false)//init back
	{
		cout << "ERROR::GAME::INITBESTIARY::Cannot load exitDefault.png" << std::endl;
	}
	else
	{
		this->buttonBestiaryExit.setSize(sf::Vector2f(150.0f, 150.0f));
		this->buttonBestiaryExit.setPosition(sf::Vector2f(825.0f, 500.0f));
		this->buttonBestiaryExit.setTexture(&buttonBestiaryExitTexture);
	}

	if (this->buttonBestiaryNextActiveTexture.loadFromFile("buttons/nextActive.png") == false)//init back
	{
		cout << "ERROR::GAME::INITBESTIARY::Cannot load nextActive.png" << std::endl;
	}
	if (this->buttonBestiaryNextTexture.loadFromFile("buttons/nextDefault.png") == false)//init back
	{
		cout << "ERROR::GAME::INITBESTIARY::Cannot load nextDefault.png" << std::endl;
	}
	else
	{
		this->buttonBestiaryNext.setSize(sf::Vector2f(150.0f, 150.0f));
		this->buttonBestiaryNext.setPosition(sf::Vector2f(1000.0f, 500.0f));
		this->buttonBestiaryNext.setTexture(&buttonBestiaryNextTexture);
	}
	//centaur info
	stringstream ci;
	ci << "        Centaur" << endl << "Speed: " << this->centaurBaseSpeed << endl << "Damage: " << this->centaurAttackValue << endl << "Value: " << this->centaurValue;
	this->centaurInfo.setString(ci.str());

	stringstream gi;
	gi << "         Goblin" << endl << "Speed: " << this->goblinBaseSpeed << endl << "Damage: " << this->goblinAttackValue << endl << "Value: " << this->goblinValue;
	this->goblinInfo.setString(gi.str());

	stringstream zi;
	zi << "         Zombie" << endl << "Speed: " << this->zombieBaseSpeed << endl << "Damage: " << this->zombieAttackValue << endl << "Value: " << this->zombieValue;
	this->zombieInfo.setString(zi.str());

	stringstream oi;
	oi << "           Orc " << endl << "Speed: " << this->orcBaseSpeed << endl << "Damage: " << this->orcAttackValue << endl << "Value: " << this->orcValue;
	this->orcInfo.setString(oi.str());
}

void Game::initHighscore() //initialize menu
{
	if (this->highscoreBookTexture.loadFromFile("background/Book.png") == false) //Init book
	{
		cout << "ERROR::GAME::INITHIGHSCORE::Cannot load menuBackground.png" << std::endl;
	}
	else
	{
		this->highscoreBook.setSize(sf::Vector2f(1234.0f, 700.0f));
		this->highscoreBook.setPosition(sf::Vector2f(20.0f, 10.0f));
		this->highscoreBook.setTexture(&highscoreBookTexture);
	}

	if (this->buttonHighscoreExitActiveTexture.loadFromFile("buttons/exitActive.png") == false)//init back
	{
		cout << "ERROR::GAME::INITHIGHSCORE::Cannot load exitActive.png" << std::endl;
	}
	if (this->buttonHighscoreExitTexture.loadFromFile("buttons/exitDefault.png") == false)//init back
	{
		cout << "ERROR::GAME::INITHIGHSCORE::Cannot load exitDefault.png" << std::endl;
	}
	else
	{
		this->buttonHighscoreExit.setSize(sf::Vector2f(150.0f, 150.0f));
		this->buttonHighscoreExit.setPosition(sf::Vector2f(825.0f, 500.0f));
		this->buttonHighscoreExit.setTexture(&buttonHighscoreExitTexture);
	}
	
	stringstream hsi;
}

void Game::initCredits() //initialize menu
{
	if (this->CreditsBookTexture.loadFromFile("background/creditsBook.png") == false) //Init book
	{
		cout << "ERROR::GAME::INITCREDITS::Cannot load creditsBook.png" << std::endl;
	}
	else
	{
		this->CreditsBook.setSize(sf::Vector2f(1234.0f, 700.0f));
		this->CreditsBook.setPosition(sf::Vector2f(20.0f, 10.0f));
		this->CreditsBook.setTexture(&CreditsBookTexture);
	}
	if (this->buttonCreditsExitTexture.loadFromFile("buttons/exitDefault.png") == false)//init back
	{
		cout << "ERROR::GAME::INITCREDITS::Cannot load exitDefault.png" << std::endl;
	}
	if (this->buttonCreditsExitActiveTexture.loadFromFile("buttons/exitActive.png") == false)//init back
	{
		cout << "ERROR::GAME::INITCREDITS::Cannot load exitActive.png" << std::endl;
	}
	else
	{
		this->buttonCreditsExit.setSize(sf::Vector2f(150.0f, 150.0f));
		this->buttonCreditsExit.setPosition(sf::Vector2f(275.0f, 500.0f));
		this->buttonCreditsExit.setTexture(&buttonCreditsExitTexture);
	}

}

void Game::initKillscreen()
{
	if (this->killscreenBackgroundTexture.loadFromFile("background/killscreen.png") == false) //Init book
	{
		cout << "ERROR::GAME::INITKILLSCREEN::Cannot load killscren.png" << std::endl;
	}
	else
	{
		this->killscreenBackground.setSize(sf::Vector2f(1280.0f, 720.0f));
		this->killscreenBackground.setPosition(sf::Vector2f(0.0f, 0.0f));
		this->killscreenBackground.setTexture(&killscreenBackgroundTexture);
	}
	if (this->buttonKillscreenExitTexture.loadFromFile("buttons/exitDefault.png") == false)//init back
	{
		cout << "ERROR::GAME::INITKILLSCREEN::Cannot load exitDefault.png" << std::endl;
	}
	if (this->buttonKillscreenExitActiveTexture.loadFromFile("buttons/exitActive.png") == false)//init back
	{
		cout << "ERROR::GAME::INITKILLSCREEN::Cannot load exitActive.png" << std::endl;
	}
	else
	{
		this->buttonKillscreenExit.setSize(sf::Vector2f(188.0f, 148.0f));
		this->buttonKillscreenExit.setPosition(sf::Vector2f(825.0f, 550.0f));
		this->buttonKillscreenExit.setTexture(&buttonKillscreenExitTexture);
	}
	if (this->buttonKillscreenSaveTexture.loadFromFile("buttons/saveScoreDefault.png") == false)
	{
		cout<< "ERROR::GAME::INITKILLSCREEN::Cannot load saveScoreDefault.png" << std::endl;
	}
	if (this->buttonKillscreenSaveActiveTexture.loadFromFile("buttons/saveScoreActive.png") == false)
	{
		cout << "ERROR::GAME::INITKILLSCREEN::Cannot load saveScoreActive.png" << std::endl;
	}
	else
	{
		this->buttonKillscreenSave.setSize(sf::Vector2f(433.0f, 148.0f));
		this->buttonKillscreenSave.setPosition(sf::Vector2f(225.0f, 550.0f));
		this->buttonKillscreenSave.setTexture(&buttonKillscreenSaveTexture);
	}
}

void Game::initCenter() //Initialize center heart
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
	if (this->font2.loadFromFile("fonts/Enchanted Land.otf") == false)
	{
		cout << "ERROR::GAME::INITFONTS::Cannot load font Enchanted Land.otf" << std::endl;
	}
}

void Game::initSounds() //Initialize sound
{
	if (this->buffer.loadFromFile("sounds/kill.wav") == false)
	{
		cout << "ERROR::GAME::INITSOUNDS::Cannot load sound kill.wav" << std::endl;
	}
	else
	{
		this->sound.setBuffer(this->buffer);
		this->sound.setVolume(20);
	}
}

void Game::initText() //Initialize text
{
	this->uiText1.setFont(this->font);
	this->uiText1.setCharacterSize(64);
	this->uiText1.setFillColor(Color::White);
	this->uiText1.setString("ERROR");
	this->uiText1.setPosition(168.0f, 128.0f);

	this->uiText2.setFont(this->font);
	this->uiText2.setCharacterSize(64);
	this->uiText2.setFillColor(Color::White);
	this->uiText2.setString("ERROR");
	this->uiText2.setPosition(1112.0f, 128.0f);

	this->pointsInfo.setFont(this->font);
	this->pointsInfo.setCharacterSize(64);
	this->pointsInfo.setFillColor(Color::White);
	this->pointsInfo.setString("ERROR");
	this->pointsInfo.setPosition(168.0f, 196.0f);

	this->healthInfo.setFont(this->font);
	this->healthInfo.setCharacterSize(64);
	this->healthInfo.setFillColor(Color::White);
	this->healthInfo.setString("ERROR");
	this->healthInfo.setPosition(1112.0f, 196.0f);

	this->centaurInfo.setFont(this->font2);
	this->centaurInfo.setCharacterSize(110);
	this->centaurInfo.setFillColor(Color::Black);
	this->centaurInfo.setString("ERROR");
	this->centaurInfo.setPosition(700.0f, 0.0f);

	this->goblinInfo.setFont(this->font2);
	this->goblinInfo.setCharacterSize(110);
	this->goblinInfo.setFillColor(Color::Black);
	this->goblinInfo.setString("ERROR");
	this->goblinInfo.setPosition(700.0f, 0.0f);

	this->zombieInfo.setFont(this->font2);
	this->zombieInfo.setCharacterSize(110);
	this->zombieInfo.setFillColor(Color::Black);
	this->zombieInfo.setString("ERROR");
	this->zombieInfo.setPosition(700.0f, 0.0f);

	this->orcInfo.setFont(this->font2);
	this->orcInfo.setCharacterSize(110);
	this->orcInfo.setFillColor(Color::Black);
	this->orcInfo.setString("ERROR");
	this->orcInfo.setPosition(700.0f, 0.0f);

	this->vanillaLevel.setFont(this->font2);
	this->vanillaLevel.setCharacterSize(110);
	this->vanillaLevel.setFillColor(Color::White);
	this->vanillaLevel.setString("ERROR");
	this->vanillaLevel.setPosition(90.0f, 400.0f);

	this->iceLevel.setFont(this->font2);
	this->iceLevel.setCharacterSize(110);
	this->iceLevel.setFillColor(Color::White);
	this->iceLevel.setString("ERROR");
	this->iceLevel.setPosition(520.0f, 400.0f);

	this->hellLevel.setFont(this->font2);
	this->hellLevel.setCharacterSize(110);
	this->hellLevel.setFillColor(Color::White);
	this->hellLevel.setString("ERROR");
	this->hellLevel.setPosition(970.0f, 400.0f);

	this->highscoreKillscreen.setFont(this->font2);
	this->highscoreKillscreen.setCharacterSize(110);
	this->highscoreKillscreen.setFillColor(Color::White);
	this->highscoreKillscreen.setString("ERROR");
	this->highscoreKillscreen.setPosition(640.0f, 300.0f);

	this->highscoreInfo.setFont(this->font2);
	this->highscoreInfo.setCharacterSize(110);
	this->highscoreInfo.setFillColor(Color::White);
	this->highscoreInfo.setString("ERROR");
	this->highscoreInfo.setPosition(150.0f, 10.0f);
}

void Game::initBackground() //Initialize background
{
	//DEFAULT MAP
	if (this->menuBackgroundTexture.loadFromFile("background/menuBackground.png") == false) //Init background menu
	{
		cout << "ERROR::GAME::INITBACKGROUND::Cannot load menuBackground.png" << std::endl;
	}
	else
	{
		this->menuBackground.setSize(sf::Vector2f(1280.0f, 720.0f));
		this->menuBackground.setTexture(&menuBackgroundTexture);
	}

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


	///ICE MAP
	if (this->wallsIceTexture.loadFromFile("background/wallsIce.png") == false) //Init walls
	{
		cout << "ERROR::GAME::INITBACKGROUND::Cannot load wallsIce.png" << std::endl;
	}

	if (this->groundIceTexture.loadFromFile("background/groundIce.png") == false) //Init static ground
	{
		cout << "ERROR::GAME::INITBACKGROUND::Cannot load groundIce.png" << std::endl;
	}

	if (this->tileIceTexture.loadFromFile("background/tilesIce.png") == false) //Init random ground pattern
	{
		cout << "ERROR::GAME::INITBACKGROUND::Cannot load platesIce.png" << std::endl;
	}

	///HELL MAP
	if (this->wallsHellTexture.loadFromFile("background/wallsHell.png") == false) //Init walls
	{
		cout << "ERROR::GAME::INITBACKGROUND::Cannot load wallsHell.png" << std::endl;
	}

	if (this->groundHellTexture.loadFromFile("background/groundHell.png") == false) //Init static ground
	{
		cout << "ERROR::GAME::INITBACKGROUND::Cannot load groundHell.png" << std::endl;
	}

	if (this->tileHellTexture.loadFromFile("background/tilesHell.png") == false) //Init random ground pattern
	{
		cout << "ERROR::GAME::INITBACKGROUND::Cannot load platesHell.png" << std::endl;
	}
}

void Game::initEnemies() //Initialize enemies - load all textures
{
	// ZOMBIE
	if (this->zombieWalkTexture.loadFromFile("enemies/zombieWalk.png") == false) //Init zombieWalk
	{
		cout << "ERROR::GAME::INITBACKGROUND::Cannot load texture zombieWalk.png" << std::endl;
	}
	if (this->zombieAttackTexture.loadFromFile("enemies/zombieAttack.png") == false) //Init zombieAttack
	{
		cout << "ERROR::GAME::INITBACKGROUND::Cannot load texture zombieAttack.png" << std::endl;
	}

	if (this->zombieHellWalkTexture.loadFromFile("enemies/zombieWalkHell.png") == false) //Init zombieWalk
	{
		cout << "ERROR::GAME::INITBACKGROUND::Cannot load texture zombieWalkHell.png" << std::endl;
	}
	if (this->zombieHellAttackTexture.loadFromFile("enemies/zombieAttackHell.png") == false) //Init zombieAttack
	{
		cout << "ERROR::GAME::INITBACKGROUND::Cannot load texture zombieAttackHell.png" << std::endl;
	}
	
	// CENTAUR
	if (this->centaurWalkTexture.loadFromFile("enemies/centaurWalk.png") == false) //Init centaurWalk
	{
		cout << "ERROR::GAME::INITBACKGROUND::Cannot load texture centaurWalk.png" << std::endl;
	}
	if (this->centaurAttackTexture.loadFromFile("enemies/centaurAttack.png") == false) //Init centaurAttack
	{
		cout << "ERROR::GAME::INITBACKGROUND::Cannot load texture centaurAttack.png" << std::endl;
	}

	if (this->centaurHellWalkTexture.loadFromFile("enemies/centaurWalkHell.png") == false) //Init centaurWalk
	{
		cout << "ERROR::GAME::INITBACKGROUND::Cannot load texture centaurWalkHell.png" << std::endl;
	}
	if (this->centaurHellAttackTexture.loadFromFile("enemies/centaurAttackHell.png") == false) //Init centaurAttack
	{
		cout << "ERROR::GAME::INITBACKGROUND::Cannot load texture centaurAttackHell.png" << std::endl;
	}
	
	// ORC
	if (this->orcWalkTexture.loadFromFile("enemies/orcWalk.png") == false) //Init orcWalk
	{
		cout << "ERROR::GAME::INITBACKGROUND::Cannot load texture orcWalk.png" << std::endl;
	}
	if (this->orcAttackTexture.loadFromFile("enemies/orcAttack.png") == false) //Init orcAttack
	{
		cout << "ERROR::GAME::INITBACKGROUND::Cannot load texture orcAttack.png" << std::endl;
	}

	if (this->orcHellWalkTexture.loadFromFile("enemies/orcWalkHell.png") == false) //Init orcWalk
	{
		cout << "ERROR::GAME::INITBACKGROUND::Cannot load texture orcWalkHell.png" << std::endl;
	}
	if (this->orcHellAttackTexture.loadFromFile("enemies/orcAttackHell.png") == false) //Init orcAttack
	{
		cout << "ERROR::GAME::INITBACKGROUND::Cannot load texture orcAttackHell.png" << std::endl;
	}
	
	// GOBLIN
	if (this->goblinWalkTexture.loadFromFile("enemies/goblinWalk.png") == false) //Init goblinWalk
	{
		cout << "ERROR::GAME::INITBACKGROUND::Cannot load texture goblinWalk.png" << std::endl;
	}
	if (this->goblinAttackTexture.loadFromFile("enemies/goblinAttack.png") == false) //Init goblinWalk
	{
		cout << "ERROR::GAME::INITBACKGROUND::Cannot load texture goblinAttack.png" << std::endl;
	}

	if (this->goblinHellWalkTexture.loadFromFile("enemies/goblinWalkHell.png") == false) //Init goblinWalk
	{
		cout << "ERROR::GAME::INITBACKGROUND::Cannot load texture goblinWalkHell.png" << std::endl;
	}
	if (this->goblinHellAttackTexture.loadFromFile("enemies/goblinAttackHell.png") == false) //Init goblinWalk
	{
		cout << "ERROR::GAME::INITBACKGROUND::Cannot load texture goblinAttackHell.png" << std::endl;
	}

	// YETI
	if (this->yetiWalkTexture.loadFromFile("enemies/yetiWalk.png") == false) //Init goblinWalk
	{
		cout << "ERROR::GAME::INITBACKGROUND::Cannot load texture yetiWalk.png" << std::endl;
	}
	if (this->yetiAttackTexture.loadFromFile("enemies/yetiAttack.png") == false) //Init goblinWalk
	{
		cout << "ERROR::GAME::INITBACKGROUND::Cannot load texture yetiAttack.png" << std::endl;
	}

	// WARGO
	if (this->wargoWalkTexture.loadFromFile("enemies/wargoWalk.png") == false) //Init goblinWalk
	{
		cout << "ERROR::GAME::INITBACKGROUND::Cannot load texture wargoWalk.png" << std::endl;
	}
	if (this->wargoAttackTexture.loadFromFile("enemies/wargoAttack.png") == false) //Init goblinWalk
	{
		cout << "ERROR::GAME::INITBACKGROUND::Cannot load texture wargoAttack.png" << std::endl;
	}

}

///////////////////////////////////////////////////////////


//////////////////// Custom functions /////////////////////

void Game::generateTiles(Texture& tiles)
{
	for (int i = 0; i < 17; i++)
	{
		for (int j = 0; j < 16; j++)
		{
			int r1 = rand() % 100;
			if (r1 > 80)
			{
				this->tile.setSize(sf::Vector2f(32.0f, 32.0f));
				this->tile.setTexture(&tiles);
				this->tile.setPosition(Vector2f(368.0f + i * 32.0f, 128.0f + j * 32.0f));
				this->tile.setTextureRect(IntRect(32 * (rand() % 6), 32 * (rand() % 1), 32, 32));
			}
			this->tiles.push_back(this->tile);
		}
	}
}

void Game::spawnEnemy() //Spawn enemy  
/*
Enemy name(walktexture, (number of walk frames x,number of walk frames y), attack texture, (number of attack frames x,number of attack frames y),animation speed, speed of enemy, starting position, point value, attack value)
*/
{
	Texture* zombieTexW = &zombieWalkTexture;
	Texture* zombieTexA = &zombieAttackTexture;
	Texture* centaurTexW = &centaurWalkTexture;
	Texture* centaurTexA = &centaurAttackTexture;
	Texture* orcTexW = &orcWalkTexture;
	Texture* orcTexA = &orcAttackTexture;
	Texture* goblinTexW = &goblinWalkTexture;
	Texture* goblinTexA = &goblinAttackTexture;

	Vector2f resp = Vector2f(912.0f, (rand() % 448) + 128);
	float animationSpeedMultiplier = float(5 / log(this->points)); //increasing speed over time
	float speedMultiplier = float(log(this->points) / 5);
	float animSpeed = zombieBaseSpeed * speedMultiplier;
	float moveSpeed = zombieAnimationSpeed * animationSpeedMultiplier;
	float value = zombieValue;
	int type;
	int side = (rand() % 4); // Generate spawn side  0-top 1-bottom 2-left 3-right
	if (this->points >= specialEnemyRespCap && (difficulty == "medium" || difficulty == "hard"))
		type = (rand() % 5); // Generate type of enemy 0-zombie 1-centaur 2-goblin 3-orc 4-special
	else
		type = (rand() % 4); // Generate type of enemy 0-zombie 1-centaur 2-goblin 3-orc
	

	if (type == 0)
	{
		moveSpeed = zombieBaseSpeed * speedMultiplier;
		animSpeed = zombieAnimationSpeed * animationSpeedMultiplier;
		value = zombieValue;
	}
	else if (type == 1)
	{
		moveSpeed = centaurBaseSpeed * speedMultiplier;
		animSpeed = centaurAnimationSpeed * animationSpeedMultiplier;
		value = centaurValue;
	}
	else if (type == 2)
	{
		moveSpeed = goblinBaseSpeed * speedMultiplier;
		animSpeed = goblinAnimationSpeed * animationSpeedMultiplier;
		value = goblinValue;
	}
	else if (type == 3)
	{
		moveSpeed = orcBaseSpeed * speedMultiplier;
		animSpeed = orcAnimationSpeed * animationSpeedMultiplier;
		value = orcValue;
	}
	else if (type == 4)
	{
		if (this->difficulty == "medium")
		{
			moveSpeed = yetiBaseSpeed * speedMultiplier;
			animSpeed = yetiAnimationSpeed * animationSpeedMultiplier;
			value = yetiValue;
		}
		else if (this->difficulty == "hard")
		{
			moveSpeed = wargoBaseSpeed * speedMultiplier;
			animSpeed = wargoAnimationSpeed * animationSpeedMultiplier;
			value = wargoValue;
		}
	}

	/// Difficulty modifiers
	 if (this->difficulty == "medium")
	{
		animSpeed = animSpeed * 1.5;
		moveSpeed = moveSpeed * 1.5;
		value = value * 2;
	}
	else if (this->difficulty == "hard")
	{
		zombieTexW = &zombieHellWalkTexture;
		zombieTexA = &zombieHellAttackTexture;
		centaurTexW = &centaurHellWalkTexture;
		centaurTexA = &centaurHellAttackTexture;
		orcTexW = &orcHellWalkTexture;
		orcTexA = &orcHellAttackTexture;
		goblinTexW = &goblinHellWalkTexture;
		goblinTexA = &goblinHellAttackTexture;
		animSpeed = animSpeed / 2;
		moveSpeed = moveSpeed * 2;
		value = value * 3;
	}

	// Setting respawn position
	if (side == 0)
	{
		int door = (rand() % 4);
		if (door == 1)
			resp = Vector2f((rand() % 96) + 368, 96.f);
		else if (door == 2)
			resp = Vector2f((rand() % 64) + 544, 96.f);
		else if (door == 3)
			resp = Vector2f((rand() % 64) + 672, 96.f);
		else if (door == 4)
			resp = Vector2f((rand() % 96) + 800, 96.f);
	}
	else if (side == 1)
	{
		resp = Vector2f((rand() % 544) + 368, 636.f);
	}
	else if (side == 2)
	{
		resp = Vector2f(368.0f, (rand() % 448) + 160);
	}
	else if (side == 3)
	{
		resp = Vector2f(912.0f, (rand() % 448) + 128);
	}

	// Proper spawn enemy
	if (type == 0)
	{
		Enemy zombie(zombieTexW, sf::Vector2u(4, 4), zombieTexA, sf::Vector2u(5, 4), animSpeed, moveSpeed, resp, value, zombieAttackValue);
		this->enemies.push_back(zombie);
	}
	else if (type == 1)
	{
		Enemy centaur(centaurTexW, sf::Vector2u(4, 4), centaurTexA, sf::Vector2u(4, 4), animSpeed, moveSpeed, resp, value, centaurAttackValue);
		this->enemies.push_back(centaur);
	}
	else if (type == 2)
	{
		Enemy goblin(goblinTexW, sf::Vector2u(4, 4), goblinTexA, sf::Vector2u(4, 4), animSpeed, moveSpeed, resp, value, goblinAttackValue);
		this->enemies.push_back(goblin);
	}
	else if (type == 3)
	{
		Enemy orc(orcTexW, sf::Vector2u(4, 4), orcTexA, sf::Vector2u(4, 4), animSpeed, moveSpeed, resp, value, orcAttackValue);
		this->enemies.push_back(orc);
	}
	else if (type == 4)
	{
		if (this->difficulty == "medium")
		{
			Enemy yeti(&yetiWalkTexture, sf::Vector2u(6, 4), &yetiAttackTexture, sf::Vector2u(4, 4), animSpeed, moveSpeed, resp, value, yetiAttackValue);
			this->enemies.push_back(yeti);
		}
		else if (this->difficulty == "hard")
		{
			Enemy wargo(&wargoWalkTexture, sf::Vector2u(4, 4), &wargoAttackTexture, sf::Vector2u(4, 4), animSpeed, moveSpeed, resp, value, wargoAttackValue);
			this->enemies.push_back(wargo);
		}
	}
}

void Game::updateMousePositions()//Update mouse position
{
	this->mousePosWindow = Mouse::getPosition(*this->window);
	this->mousePosView = this->window->mapPixelToCoords(this->mousePosWindow);
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

void Game::saveScore()
{

}

///////////////////////////////////////////////////////////


//////////////////////// Game logic ///////////////////////

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
	this->initCredits();
	this->initKillscreen();
	this->initHighscore();
	this->initBestiary();
	this->initMenu();
	this->initLevels();
}

Game::~Game() //Game destructor - turn off game
{
	delete this->window;
}

///////////////////////////////////////////////////////////


//////////////////// Update functions /////////////////////

void Game::updateText()//Update text values
{
	stringstream ss1;
	stringstream ss2;
	ss1 << this->points;
	ss2 << this->health;
	this->uiText1.setString("POINTS");
	this->uiText2.setString("HEALTH");
	this->pointsInfo.setString(ss1.str());
	this->healthInfo.setString(ss2.str());
	uiText1.setOrigin(uiText1.getLocalBounds().width / 2.0f, 0.0f);
	uiText2.setOrigin(uiText2.getLocalBounds().width / 2.0f, 0.0f);
	pointsInfo.setOrigin(pointsInfo.getLocalBounds().width / 2.0f, 0.0f);
	healthInfo.setOrigin(healthInfo.getLocalBounds().width / 2.0f, 0.0f);
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

	for (size_t i = 0; i < this->enemies.size(); i++) //Check if enemy is able to attack and delete enemy after attack
	{
		if (enemies[i].attackFinished)
		{
			this->health -= enemies[i].attackPower;
			if (health <= 0)
			{
				gameState = "killscreen";
			}
			this->enemies.erase(this->enemies.begin() + i);
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

void Game::updateMenu()
{
	if (this->buttonMenu1.getGlobalBounds().contains(this->mousePosView))
	{
		this->buttonMenu1.setTexture(&buttonMenu1ActiveTexture);
		if (Mouse::isButtonPressed(Mouse::Left))
		{
			if (this->mouseHeld == false)
			{
				gameState = "levels";
			}
		}
	}
	else
	{
		this->buttonMenu1.setTexture(&buttonMenu1Texture);
	}

	if (this->buttonMenu2.getGlobalBounds().contains(this->mousePosView))
	{
		this->buttonMenu2.setTexture(&buttonMenu2ActiveTexture);
		if (Mouse::isButtonPressed(Mouse::Left))
		{
			if (this->mouseHeld == false)
			{
				gameState = "highscore";
			}
		}
	}
	else
	{
		this->buttonMenu2.setTexture(&buttonMenu2Texture);
	}

	if (this->buttonMenu3.getGlobalBounds().contains(this->mousePosView))
	{
		this->buttonMenu3.setTexture(&buttonMenu3ActiveTexture);
		if (Mouse::isButtonPressed(Mouse::Left)&&this->mouseHeld==false)
		{
			if (this->mouseHeld == false)
			{
				gameState = "bestiary";
			}
		}
	}
	else
	{
		this->buttonMenu3.setTexture(&buttonMenu3Texture);
	}

	if (this->buttonMenu4.getGlobalBounds().contains(this->mousePosView))
	{
		this->buttonMenu4.setTexture(&buttonMenu4ActiveTexture);
		if (Mouse::isButtonPressed(Mouse::Left))
		{
			if (this->mouseHeld == false)
			{
				gameState = "credits";
			}
		}
	}
	else
	{
		this->buttonMenu4.setTexture(&buttonMenu4Texture);
	}
}

void Game::updateLevels()
{
	if (this->buttonLevelsVanilla.getGlobalBounds().contains(this->mousePosView))
	{
		this->buttonLevelsVanilla.setTexture(&buttonLevelsVanillaActiveTexture);
		if (Mouse::isButtonPressed(Mouse::Left))
		{
			if (this->mouseHeld == false)
			{
				this->walls.setTexture(&wallsTexture);
				this->ground.setTexture(&groundTexture);
				this->tile.setTexture(&tileTexture);
				this->tiles.clear();
				generateTiles(tileTexture);
				this->enemies.clear();
				difficulty = "easy";
				gameState = "game";

			}
		}
	}
	else
	{
		this->buttonLevelsVanilla.setTexture(&buttonLevelsVanillaTexture);
	}

	if (this->buttonLevelsIce.getGlobalBounds().contains(this->mousePosView))
	{
		this->buttonLevelsIce.setTexture(&buttonLevelsIceActiveTexture);
		if (Mouse::isButtonPressed(Mouse::Left))
		{
			if (this->mouseHeld == false)
			{
				this->walls.setTexture(&wallsIceTexture);
				this->ground.setTexture(&groundIceTexture);
				this->tile.setTexture(&tileIceTexture);
				this->tiles.clear();
				generateTiles(tileIceTexture);
				this->enemies.clear();
				difficulty = "medium";
				gameState = "game";
			}
		}
	}
	else
	{
		this->buttonLevelsIce.setTexture(&buttonLevelsIceTexture);
	}

	if (this->buttonLevelsHell.getGlobalBounds().contains(this->mousePosView))
	{
		this->buttonLevelsHell.setTexture(&buttonLevelsHellActiveTexture);
		if (Mouse::isButtonPressed(Mouse::Left))
		{
			if (this->mouseHeld == false)
			{
				this->walls.setTexture(&wallsHellTexture);
				this->ground.setTexture(&groundHellTexture);
				this->tile.setTexture(&tileHellTexture);
				this->tiles.clear();
				generateTiles(tileHellTexture);
				this->enemies.clear();
				difficulty = "hard";
				gameState = "game";
			}
		}
	}
	else
	{
		this->buttonLevelsHell.setTexture(&buttonLevelsHellTexture);
	}
}

void Game::updateBestiary()
{
	if (this->buttonBestiaryBack.getGlobalBounds().contains(this->mousePosView))
	{
		this->buttonBestiaryBack.setTexture(&buttonBestiaryBackActiveTexture);
		if (Mouse::isButtonPressed(Mouse::Left) && this->pageCount > 1)
		{
			if (this->mouseHeld == false)
			{
				this->pageCount -= 1;
			}
		}
	}
	else
	{
		this->buttonBestiaryBack.setTexture(&buttonBestiaryBackTexture);
	}

	if (this->buttonBestiaryExit.getGlobalBounds().contains(this->mousePosView))
	{
		this->buttonBestiaryExit.setTexture(&buttonBestiaryExitActiveTexture);
		if (Mouse::isButtonPressed(Mouse::Left))
		{
			if (this->mouseHeld == false)
			{
				gameState = "menu";
			}
		}
	}
	else
	{
		this->buttonBestiaryExit.setTexture(&buttonBestiaryExitTexture);
	}

	if (this->buttonBestiaryNext.getGlobalBounds().contains(this->mousePosView))
	{
		this->buttonBestiaryNext.setTexture(&buttonBestiaryNextActiveTexture);
		if (Mouse::isButtonPressed(Mouse::Left) && this->pageCount < 4)
		{
			if (this->mouseHeld == false)
			{
				this->pageCount += 1;
			}
		}
	}
	else
	{
		this->buttonBestiaryNext.setTexture(&buttonBestiaryNextTexture);
	}
}

void Game::updateHighscore()
{
	if (this->buttonHighscoreExit.getGlobalBounds().contains(this->mousePosView))
	{
		this->buttonHighscoreExit.setTexture(&buttonHighscoreExitActiveTexture);
		if (Mouse::isButtonPressed(Mouse::Left))
		{
			if (this->mouseHeld == false)
			{
				gameState = "menu";
			}
		}
	}
	else
	{
		this->buttonHighscoreExit.setTexture(&buttonHighscoreExitTexture);
	}

	stringstream hsi;
	hsi << "1. 10000000000" << endl << "2. " << endl << "3. " << endl << "4. " << endl << "5. " << endl;
	this->highscoreInfo.setString(hsi.str());
}

void Game::updateCredits()
{
	if (this->buttonCreditsExit.getGlobalBounds().contains(this->mousePosView))
	{
		this->buttonCreditsExit.setTexture(&buttonCreditsExitActiveTexture);
		if (Mouse::isButtonPressed(Mouse::Left))
		{
			if (this->mouseHeld == false)
			{
				gameState = "menu";
			}
		}
	}
	else
	{
		this->buttonCreditsExit.setTexture(&buttonCreditsExitTexture);
	}
}

void Game::updateKillscreen()
{
	if (this->buttonKillscreenExit.getGlobalBounds().contains(this->mousePosView))
	{
		this->buttonKillscreenExit.setTexture(&buttonKillscreenExitActiveTexture);
		if (Mouse::isButtonPressed(Mouse::Left))
		{
			if (this->mouseHeld == false)
			{
				gameState = "menu";
				this->health = 20;
				this->points = 100;
				this->enemies.clear();
			}
		}
	}
	else
	{
		this->buttonKillscreenExit.setTexture(&buttonKillscreenExitTexture);
	}

	if (this->buttonKillscreenSave.getGlobalBounds().contains(this->mousePosView))
	{
		this->buttonKillscreenSave.setTexture(&buttonKillscreenSaveActiveTexture);
		if (Mouse::isButtonPressed(Mouse::Left))
		{
			if (this->mouseHeld == false)
			{
				saveScore();
				gameState = "menu";
				this->health = 20;
				this->points = 100;
				this->enemies.clear();
			}
		}
	}
	else
	{
		this->buttonKillscreenSave.setTexture(&buttonKillscreenSaveTexture);
	}
}

void Game::update() //Update all elements to update + events + update deltaTime
{
	if (gameState == "levels")
	{
		this->updateLevels();
	}
	if (gameState == "game")
	{
		deltaTime = clock.restart().asSeconds();
		if (deltaTime > 1.0f / 60.0f)
			deltaTime = 1.0f / 60.0f;
		this->updateText();
		this->updateEnemies();
	}
	else if (gameState == "menu")
	{
		this->updateMenu();
	}
	else if (gameState == "bestiary")
	{
		this->updateBestiary();
		this->updateText();
	}
	else if (gameState == "credits")
	{
		this->updateCredits();
	}
	else if (gameState == "highscore")
	{
		this->updateHighscore();
	}
	else if (gameState == "killscreen")
	{
		this->updateKillscreen();

		stringstream hsks;
		hsks << "Your Score: " << this->points;
		this->highscoreKillscreen.setString(hsks.str());
		highscoreKillscreen.setOrigin(highscoreKillscreen.getLocalBounds().width / 2.0f, 0.0f);
	}

	this->pollEvents();
	this->updateMousePositions();

	if (Mouse::isButtonPressed(Mouse::Left))
	{
		this->mouseHeld = true;
	}
	else
	{
		this->mouseHeld = false;
	}
}

///////////////////////////////////////////////////////////


//////////////////// Render functions /////////////////////

void Game::renderText(RenderTarget& target)//Render text
{
	target.draw(this->uiText1);
	target.draw(this->uiText2);
	target.draw(this->pointsInfo);
	target.draw(this->healthInfo);
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
	if (gameState=="game")
	{
		this->window->clear(Color(11, 11, 11));
		window->draw(ground);
		this->renderTiles(*this->window);
		window->draw(center);
		this->renderEnemies(*this->window);
		window->draw(walls);
		this->renderText(*this->window);
	}
	else if (gameState == "levels")
	{
		this->window->clear(Color(11, 11, 11));
		window->draw(wallBackground);
		window->draw(buttonLevelsVanilla);
		window->draw(buttonLevelsIce);
		window->draw(buttonLevelsHell);
		window->draw(this->vanillaLevel);
		window->draw(this->iceLevel);
		window->draw(this->hellLevel);
	}
	else if (gameState == "menu")
	{
		window->draw(menuBackground);
		window->draw(buttonMenu1);
		window->draw(buttonMenu2);
		window->draw(buttonMenu3);
		window->draw(buttonMenu4);
	}
	else if (gameState == "bestiary")
	{
		this->window->clear(Color(11, 11, 11));
		window->draw(menuBackground);
		window->draw(BestiaryBook);
		window->draw(buttonBestiaryBack);
		window->draw(buttonBestiaryExit);
		window->draw(buttonBestiaryNext);
		if (this->pageCount==1)
			window->draw(this->centaurInfo);
		if (this->pageCount == 2)
			window->draw(this->goblinInfo);
		if (this->pageCount == 3)
			window->draw(this->zombieInfo);
		if (this->pageCount == 4)
			window->draw(this->orcInfo);
	}
	else if (gameState == "credits")
	{
		this->window->clear(Color(11, 11, 11));
		window->draw(menuBackground);
		window->draw(CreditsBook);
		window->draw(buttonCreditsExit);
	}
	else if (gameState == "highscore")
	{
		this->window->clear(Color(11, 11, 11));
		window->draw(menuBackground);
		window->draw(highscoreBook);
		window->draw(buttonHighscoreExit);
		window->draw(highscoreInfo);
	}
	else if (gameState == "killscreen")
	{
		this->window->clear(Color(11, 11, 11));
		window->draw(killscreenBackground);
		window->draw(buttonKillscreenExit);
		window->draw(buttonKillscreenSave);
		window->draw(highscoreKillscreen);
	}
	this->window->display();
}

///////////////////////////////////////////////////////////