#pragma once
#include <iostream>
using namespace std;
#include <SFML/Graphics.hpp>
using namespace sf;
#include "Alien.h"
#include "MissilesList.h"
#include <list>
#include "BombsList.h"
#include "UI.h"

class AliensList
{
private:
	list<Alien> alienslist;
	void addAlien(const Texture&, Vector2f, float);
public:
	AliensList(const Texture&, float speed);
	void removeAlien(Sprite background, UI & obj);
	void dropbombs(Texture &, Bombslist &);
	void draw(RenderWindow & win);
	void sethits(Missiles & obj);
	int aliensleft();
};