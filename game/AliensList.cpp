#pragma once
#include <iostream>
#include <list>
using namespace std;
#include <SFML/Graphics.hpp>
using namespace sf;
#include "Alien.h"
#include "AliensList.h"

void AliensList::addAlien(Texture text, Vector2f pos)
{
	Alien* ptr;
	ptr = new Alien(text, pos);
	alienslist.push_back(*ptr);
}
AliensList::AliensList(Texture text)
{
	Vector2f pos;
	pos.y = 20;
	pos.x = 0;
	for (int i = 0; i < 10; i++)
	{
		pos.x += (i * 15);
		addAlien(text, pos);
	}
}
void AliensList::removeAlien()
{
	list<Alien>::iterator iter;
	for (iter = alienslist.begin(); iter != alienslist.end(); )
	{
		if (iter->gethit() == true)
		{
			iter = alienslist.erase(iter);
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


void dropbomb();