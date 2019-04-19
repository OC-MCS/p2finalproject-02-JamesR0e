#include <iostream>
using namespace std;
#include <SFML/Graphics.hpp>
using namespace sf;
#include "Bomb.h"

//====================================================== 
// bomb constructor: sets the bombposition to the alien's position; also sets the bomb's texture
// parameters:  alienposition and bombtexture (by reference)
// return type: n/a
//======================================================
Bomb::Bomb(Vector2f Alienpos, Texture & bombtexture)
{
	bomb.setTexture(bombtexture);
	bomb.setPosition(Alienpos);
	used = false;
}

//====================================================== 
// draw: draws and moves the bomb;
// parameters:  window
// return type: n/a
//======================================================
void Bomb::draw(RenderWindow & win)
{
	win.draw(bomb);
	bomb.move(0, 3);
}

//====================================================== 
// getpos: returns the position of the bomb
// parameters:  n/a
// return type: Vector2f
//======================================================
Vector2f Bomb::getpos()
{
	return bomb.getPosition();
}
