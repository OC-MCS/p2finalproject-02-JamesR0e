#include <iostream>
using namespace std;
#include <SFML/Graphics.hpp>
using namespace sf;
#include "Bomb.h"


Bomb::Bomb(Vector2f Alienpos, Texture bombtexture)
{
	bomb.setTexture(bombtexture);
	bomb.setPosition(Alienpos);
	used = false;
}
void Bomb::draw(RenderWindow & win)
{
	win.draw(bomb);
	bomb.move(0, 3);
}

Vector2f Bomb::getpos()
{
	return bomb.getPosition();
}
