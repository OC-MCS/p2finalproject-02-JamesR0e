#pragma once
#include <iostream>
using namespace std;
#include <SFML/Graphics.hpp>
using namespace sf;
#include "Missile.h"
#include <list>
class Missiles
{
private:
	//list of missile objects
	list<Missile> missiles;
	list<Missile>::iterator it;
	
public:
	Missiles()
	{
		missiles = {};
	}
	void removemissile(Sprite background);
	void addMissile(Missile m); // (timing logic in main)
	void drawMissiles(RenderWindow & win);
	list<Missile>& getmissileList();
};
