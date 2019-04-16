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
#include <ctime>
#include <cstdlib>

//add destructor
void AliensList::addAlien(const Texture & text, Vector2f pos) //change this to use the alien() constructor
{
	Alien* ptr;
	ptr = new Alien(text, pos);
	alienslist.push_back(*ptr);
}
AliensList::AliensList(const Texture & text)
{
	Vector2f pos;
	pos.y = 20;
	pos.x = 0;
	for (int i = 0; i < 10; i++)
	{
		pos.x += 65;
		addAlien(text, pos);
	}
}
void AliensList::removeAlien(Sprite background)
{
	list<Alien>::iterator iter;
	for (iter = alienslist.begin(); iter != alienslist.end(); )
	{
		if (iter->gethit() == true || !background.getGlobalBounds().contains(iter->getpos()))
		{
			iter = alienslist.erase(iter);
			cout << "yay";
		}
		else
		iter++;
	}
}

void AliensList::draw(RenderWindow & win)
{
	list<Alien>::iterator iter;
	for (iter = alienslist.begin(); iter != alienslist.end(); iter++)
	{
		iter->draw(win);
		iter->move();
	}
}

void AliensList::sethits(Missiles obj)
{
	list<Alien>::iterator iter;
	list<Missile>::iterator it;
	list<Missile> missilelist = obj.getmissileList();
	
	for (iter = alienslist.begin(); iter != alienslist.end(); iter++)
	{
		for (it = missilelist.begin(); it != missilelist.end(); it++)
		{
			iter->sethit(it->getposition(), *it);
		}
	}
}


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

int AliensList::aliensleft()
{
	return alienslist.size();
}