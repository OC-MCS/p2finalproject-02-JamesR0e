#pragma once
#include <iostream>
using namespace std;
#include <SFML/Graphics.hpp>
using namespace sf;
#include "Missile.h"

class Alien
{
private:
	Sprite alien;
	bool hit;
	
public:
	Alien(Texture, Vector2f);
	void move();
	void draw(RenderWindow & win);
	void dropbomb();
	bool gethit();
	void sethit(Vector2f missilepos, Missile obj);
};