#pragma once
#include <iostream>
#include <list>
using namespace std;
#include <SFML/Graphics.hpp>
using namespace sf;
#include "Alien.h"
#include "AliensList.h"
#include "MissilesList.h"
#include "BombsList.h"
#include "UI.h"
#include <ctime>
#include <cstdlib>

//====================================================== 
// addAlien: adds a dynamically allocated Alien to the list
// parameters:  Texture, position, speed
// return type: n/a
//======================================================
void AliensList::addAlien(const Texture & text, Vector2f pos, float speed)
{
	Alien* ptr;
	ptr = new Alien(text, pos, speed);
	alienslist.push_back(*ptr);
}

//====================================================== 
// constructor: constructs all 10 aliens using the private add alien function
// parameters:  Texture and speed
// return type: n/a
//======================================================
AliensList::AliensList(const Texture & text, float speed)
{
	Vector2f pos;
	pos.y = 20;
	pos.x = 0;
	for (int i = 0; i < 10; i++)
	{
		pos.x += 65;
		addAlien(text, pos, speed);
	}
}

//====================================================== 
// removeAlien: removes aliens if they are hit or leave the background: updates the UI
// parameters:  background and UI
// return type: n/a
//======================================================
void AliensList::removeAlien(Sprite background, UI & obj)
{

	list<Alien>::iterator iter;
	for (iter = alienslist.begin(); iter != alienslist.end(); )
	{
		if (iter->gethit() == true)
		{
			obj.setkills(obj.getkills() + 1);
			iter = alienslist.erase(iter);
		}
		else if (!background.getGlobalBounds().contains(iter->getpos()))
		{
			iter = alienslist.erase(iter);
			obj.setlives(0);
			//obj.setlevel(5) //use this level for resetting the level
		}
		else
		iter++;
	}
}

//====================================================== 
// draw: draws all of the aliens on the list
// parameters:  window
// return type: n/a
//======================================================
void AliensList::draw(RenderWindow & win)
{
	list<Alien>::iterator iter;
	for (iter = alienslist.begin(); iter != alienslist.end(); iter++)
	{
		iter->draw(win);
		iter->move();
	}
}

void AliensList::sethits(Missiles & obj)
{
	list<Alien>::iterator iter;
	list<Missile>::iterator it;
	list<Missile>& missilelist = obj.getmissileList();
	
	for (iter = alienslist.begin(); iter != alienslist.end(); iter++)
	{
		for (it = missilelist.begin(); it != missilelist.end(); it++)
		{
			iter->sethit(it->getposition(), *it);
		}
	}
}

//====================================================== 
// dropbombs: drops bombs randomly at an aliens position when called
// parameters: bombtexture and bombslist
// return type: n/a
//======================================================
void AliensList::dropbombs(Texture & bombstext, Bombslist & bombslist)
{
	int r;
	list<Alien>::iterator iter;
	srand(time(0));
	bool shoot = true;
	for (iter = alienslist.begin(); iter != alienslist.end() && shoot == true; iter++)
	{
		r = (rand() % 10);
		if (r == 1)
		{
			iter->dropbomb(bombstext, bombslist);
			shoot = false;
		}
	}

}

//====================================================== 
// aliensleft: gets the number of aliens that are left to update the UI
// parameters:  n/a
// return type: integer
//======================================================
int AliensList::aliensleft()
{
	return alienslist.size();
}