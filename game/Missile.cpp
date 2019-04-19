#include <iostream>
using namespace std;
#include <SFML/Graphics.hpp>
using namespace sf;
#include "Missile.h"

//====================================================== 
// missile constructor: sets the missileposition to the players coordinates; gives a missiletexture
// parameters:  player coordinates and missiletexture
// return type: n/a
//======================================================
Missile::Missile(Vector2f coord,const Texture & missiletext)
{
	missile.setPosition(coord);
	missile.setTexture(missiletext);
	used = false;
}

//====================================================== 
// move: moves the missile
// parameters:  n/a
// return type: n/a
//======================================================
void Missile::move()
{
	missile.move(0, -8);
}

//====================================================== 
// draw: draws the missile to the frame
// parameters:  window
// return type: n/a
//======================================================
void Missile::draw(RenderWindow & win)
{
	win.draw(missile);
}

//====================================================== 
// getposition: returns the position of the missile
// parameters:  n/a
// return type: Vector2f
//======================================================
Vector2f Missile::getposition()
{
	return missile.getPosition();
}

//====================================================== 
// getUsed: returns the used status of the missile
// parameters:  n/a
// return type: bool
//======================================================
bool Missile::getUsed()
{
	return used;
}

//====================================================== 
// settrue: sets the used status to true
// parameters:  n/a
// return type: n/a
//======================================================
void Missile::settrue()
{
	used = true;
}