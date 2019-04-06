#pragma once
#include <iostream>
using namespace std;
#include <SFML/Graphics.hpp>
using namespace sf;
#include "Alien.h"
#include <list>

class AliensList
{
private:
	list<Alien> alienslist;
	list<Alien>::iterator it;
	void addAlien(Texture, Vector2f);
public:
	AliensList(Texture);
	void removeAlien();
	void dropbomb();
	void draw(RenderWindow & win);
};