#include <iostream>
using namespace std;
#include <SFML/Graphics.hpp>
using namespace sf;
#include "MissilesList.h"
#include "Missile.h"
#include <list>

//add destructor
void Missiles::addMissile(Missile m)
{
	missiles.push_back(m);
}

void Missiles::drawMissiles(RenderWindow & win)
{
	list<Missile>::iterator iter;
	for (iter = missiles.begin(); iter != missiles.end(); iter++)
	{
		iter->draw(win);
		iter->move();
	}
}

void Missiles::removemissile(Sprite background)
{
	list<Missile>::iterator iter;
	for (iter = missiles.begin(); iter != missiles.end(); )
	{
		if (!background.getGlobalBounds().contains(iter->getposition()) || iter->getUsed() == true)
		{
			iter = missiles.erase(iter);
			cout << "worked";
		}
		else
		iter++;
	}

}

list<Missile> Missiles::getmissileList()
{
	return missiles;
}