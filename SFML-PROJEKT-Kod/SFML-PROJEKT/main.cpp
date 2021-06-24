#include"Game.h"

int main()
{
	//srand
	srand(static_cast<unsigned>(time(NULL)));

	//Turning on game engine
	Game game;

	//game loop
	while (game.running() && !game.getEndGame())
	{
		//Updating gamestate
		game.update();

		//Rendering game
		game.render();
	}
	return 0;
}
