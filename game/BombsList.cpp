#include <iostream>
using namespace std;
#include <SFML/Graphics.hpp>
using namespace sf;
#include <list>
#include "BombsList.h"
#include "Bomb.h"

void Bombslist::addbomb(Bomb bomb)
{
	bombs.push_back(bomb);
}
void Bombslist::draw(RenderWindow & win)
{
	list<Bomb>::iterator iter;
	for (iter = bombs.begin(); iter != bombs.end(); iter++)
	{
		iter->draw(win);
	}
}
void Bombslist::removebomb(Sprite background)
{
	list<Bomb>::iterator iter;
	for (iter = bombs.begin(); iter != bombs.end(); )
	{
		if (!background.getGlobalBounds().contains(iter->getpos()))
		{
			iter = bombs.erase(iter);
			cout << "bombdeleted";
		}
		else
			iter++;
	}
}

