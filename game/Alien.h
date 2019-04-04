#pragma once
#include <iostream>
using namespace std;
#include <SFML/Graphics.hpp>
using namespace sf;

class Alien
{
private:
	Sprite alien;
	int alienlevel;
public:
	Alien(Texture, Vector2f, int);
	void move();
	void draw(RenderWindow & win);
	void dropbomb();
};