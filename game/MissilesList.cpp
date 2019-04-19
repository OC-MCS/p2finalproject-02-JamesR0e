#include <iostream>
using namespace std;
#include <SFML/Graphics.hpp>
using namespace sf;
#include "MissilesList.h"
#include "Missile.h"
#include <list>

//====================================================== 
// addMissile: adds a missile to the missile list
// parameters:  missile
// return type: n/a
//======================================================
void Missiles::addMissile(Missile m)
{
	missiles.push_back(m);
}

//====================================================== 
// drawMissile: draws all the missiles in the list to the frame
// parameters:  window
// return type: n/a
//======================================================
void Missiles::drawMissiles(RenderWindow & win)
{
	list<Missile>::iterator iter;
	for (iter = missiles.begin(); iter != missiles.end(); iter++)
	{
		iter->draw(win);
		iter->move();
	}
}

//====================================================== 
// removemissile: removes a missile if it is used or out of bounds
// parameters:  background
// return type: n/a
//======================================================
void Missiles::removemissile(Sprite background)
{
	list<Missile>::iterator iter;
	for (iter = missiles.begin(); iter != missiles.end(); )
	{
		if (!background.getGlobalBounds().contains(iter->getposition()) || iter->getUsed() == true)
		{
			iter = missiles.erase(iter);
		}
		else
		iter++;
	}

}

//====================================================== 
// getmissileList: returns the list of missiles by reference
// parameters:  n/a
// return type: list<Missile>& (by reference)
//======================================================
list<Missile>& Missiles::getmissileList()
{
	return missiles;
}