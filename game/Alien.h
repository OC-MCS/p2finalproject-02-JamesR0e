#pragma once
#include <iostream>
using namespace std;
#include <SFML/Graphics.hpp>
using namespace sf;
#include "Missile.h"
#include "Bomb.h"
#include "BombsList.h"

class Alien
{
private:
	Sprite alien;
	bool hit;
	float speed;
public:
	Alien(const Texture&, Vector2f, float Speed);
	void move();
	void draw(RenderWindow & win);
	void dropbomb(Texture & bombtext, Bombslist & list);
	bool gethit();
	void sethit(Vector2f missilepos, Missile & obj);
	Vector2f getpos();
};