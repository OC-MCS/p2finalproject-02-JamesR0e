#pragma once
#include <iostream>
using namespace std;
#include <SFML/Graphics.hpp>
using namespace sf;
#include <list>
#include "Bomb.h"

class Bombslist
{
private:
	list<Bomb> bombs;
	list<Bomb>::iterator it;
public:
	void addbomb(Bomb);
	Bombslist()
	{
		bombs = {};
	}
	void removebomb(Sprite background);
	void draw(RenderWindow & win);
	list<Bomb>& getlist();
};

