#include <iostream>
using namespace std;
#include <SFML/Graphics.hpp>
using namespace sf;
#include "Alien.h"



Alien::Alien(Texture texture, Vector2f coord, int lvl)
{
	alien.setTexture(texture);
	alien.setPosition(coord);
	alienlevel = lvl;
}
void Alien::move()
{
	alien.move(0, 1);
}

void Alien::draw(RenderWindow & win)
{
	win.draw(alien);
}
void dropbomb();