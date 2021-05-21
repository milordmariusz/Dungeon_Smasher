#include<iostream>
#include"Gra.h"

using namespace sf;
using namespace std;

int main()
{
	//srand
	srand(static_cast<unsigned>(time(NULL)));

	//W³¹czenie silnika gry
	Game game;

	//petla gry
	while (game.running()&&!game.getEndGame())
	{
		//Aktualizowanie stanu gry
		game.update();

		//Wyswietlanie
		game.render();
	}
	return 0;
}
