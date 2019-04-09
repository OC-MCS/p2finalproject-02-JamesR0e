#include <iostream>
using namespace std;
#include <SFML/Graphics.hpp>
using namespace sf;
#include "Alien.h"
#include "Missile.h"
#include "Bomb.h"
#include "BombsList.h"



Alien::Alien(const Texture & texture, Vector2f coord)
{
	alien.setPosition(coord);
	alien.setTexture(texture);

	hit = false;
}
void Alien::move()
{
	alien.move(0, .3);
}

void Alien::draw(RenderWindow & win)
{
	win.draw(alien);
}

bool Alien::gethit()
{
	return hit;
}
void Alien::sethit(Vector2f missilepos, Missile obj)
{
	if (alien.getGlobalBounds().contains(missilepos))
	{
		hit = true;
		obj.setUsed(true);
	}
	
}
void Alien::dropbomb(Texture bombtext, Bombslist list)
{
	Bomb* ptr;
	ptr = new Bomb(alien.getPosition(), bombtext);
	list.addbomb(*ptr);
}