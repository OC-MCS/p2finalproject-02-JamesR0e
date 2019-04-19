#include <iostream>
using namespace std;
#include <SFML/Graphics.hpp>
using namespace sf;
#include <list>
#include "BombsList.h"
#include "Bomb.h"

//====================================================== 
// addbomb: adds a bomb to the list of bombs
// parameters:  bomb
// return type: n/a
//======================================================
void Bombslist::addbomb(Bomb bomb)
{
	bombs.push_back(bomb);
}

//====================================================== 
//draw: draws all of the bombs in the list
// parameters:  window
// return type: n/a
//======================================================
void Bombslist::draw(RenderWindow & win)
{
	list<Bomb>::iterator iter;
	for (iter = bombs.begin(); iter != bombs.end(); iter++)
	{
		iter->draw(win);
	}
}

//====================================================== 
// removebomb: deletes bombs that go off screen
// parameters:  background
// return type: n/a
//======================================================
void Bombslist::removebomb(Sprite background)
{
	list<Bomb>::iterator iter;
	for (iter = bombs.begin(); iter != bombs.end(); )
	{
		if (!background.getGlobalBounds().contains(iter->getpos()))
		{
			iter = bombs.erase(iter);
		}
		else
			iter++;
	}
}

//====================================================== 
// getlist: returns the list of bombs by reference
// parameters:  n/a
// return type: list<bomb>& (refence)
//======================================================
list<Bomb>& Bombslist::getlist()
{
	return bombs;
}


