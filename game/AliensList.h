#pragma once
#include <iostream>
using namespace std;
#include <SFML/Graphics.hpp>
using namespace sf;
#include "Alien.h"
#include "MissilesList.h"
#include <list>
#include "BombsList.h"

class AliensList
{
private:
	list<Alien> alienslist;
	list<Alien>::iterator it;
	void addAlien(const Texture&, Vector2f);
public:
	AliensList(const Texture&);
	void removeAlien();
	void dropbombs(Texture, Bombslist);
	void draw(RenderWindow & win);
	void sethits(Missiles obj);
};