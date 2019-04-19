#pragma once

#include <iostream>
using namespace std;
#include <SFML/Graphics.hpp>
using namespace sf;
#include "BombsList.h"
#include "Bomb.h"
#include <list>
#include "UI.h"
class Player
{
private:
	int numlives;
	Sprite ship;
public:
	Player(Texture &, Vector2f, int);
	void move(int, int);
	int getlives();
	void setlives(int);
	void draw(RenderWindow & win);
	void setposition(Vector2f);
	Vector2f getposition();
	void detecthit(Bombslist &);
	
};