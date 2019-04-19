#include <iostream>
using namespace std;
#include <SFML/Graphics.hpp>
using namespace sf;
#include "Alien.h"
#include "Missile.h"
#include "Bomb.h"
#include "BombsList.h"


//====================================================== 
// constructor: constructs an alien
// parameters:  n/a
// return type: n/a
//======================================================
Alien::Alien(const Texture & texture, Vector2f coord, float Speed)
{
	alien.setPosition(coord);
	alien.setTexture(texture);
	speed = Speed;
	hit = false;
}

//====================================================== 
// move: moves the alien
// parameters:  n/a
// return type: n/a
//======================================================
void Alien::move()
{
	alien.move(0, speed);
}

//====================================================== 
// draw: draws the alien to the window
// parameters:  window
// return type: n/a
//======================================================
void Alien::draw(RenderWindow & win)
{
	win.draw(alien);
}

//====================================================== 
// gethit: returns true or false depending of whether the alien is hit or not
// parameters:  n/a
// return type: boolean
//======================================================
bool Alien::gethit()
{
	return hit;
}

//====================================================== 
// sethit: sets the aliens hit bool to true
// parameters:  missilposition; missile
// return type: n/a
//======================================================
void Alien::sethit(Vector2f missilepos, Missile & obj)
{
	if (alien.getGlobalBounds().contains(missilepos))
	{
		obj.settrue();
		hit = true;
	}
	
}

//====================================================== 
// dropbomb: drops a new bomb
// parameters:  bomb texture; bomblist
// return type: n/a
//======================================================
void Alien::dropbomb(Texture & bombtext, Bombslist & list)
{
	Bomb* ptr;
	ptr = new Bomb(alien.getPosition(), bombtext);
	list.addbomb(*ptr);
}

//====================================================== 
//getpos: gets the position of the alien
// parameters:  n/a
// return type: Vector2f
//======================================================
Vector2f Alien::getpos()
{
	return alien.getPosition();
}
