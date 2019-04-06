#include <iostream>
using namespace std;
#include <SFML/Graphics.hpp>
using namespace sf;
#include "Missile.h"

Missile::Missile(Texture texture, Vector2f coord)
{
	missile.setTexture(texture);
	missile.setPosition(coord);
	used = false;
}
void Missile::move()
{
	missile.move(0, -10);
}
void Missile::draw(RenderWindow & win)
{
	win.draw(missile);
}
Vector2f Missile::getposition()
{
	return missile.getPosition();
}

bool Missile::getUsed()
{
	return used;
}

void Missile::setUsed(bool a)
{
	used = a;
}