#include <iostream>
using namespace std;
#include <SFML/Graphics.hpp>
using namespace sf;
#include "Player.h"
#include "BombsList.h"
#include "Bomb.h"
#include <list>
#include "UI.h"

//====================================================== 
// Player constructor: sets the player's ship texture, starting coordingates, and starting lives;
// parameters: ship Texture, coordinates, int lives
// return type: n/a
//======================================================
Player::Player(Texture & texture, Vector2f coord, int lives)
{
	ship.setTexture(texture);
	ship.setPosition(coord);
	numlives = lives;

}

//====================================================== 
// move: moves the player
// parameters:  x and y incriments
// return type: n/a
//======================================================
void Player::move(int x, int y)
{
	ship.move(x, y);
}

//====================================================== 
// getlives: returns the players number of lives;
// parameters:  n/a
// return type: int
//======================================================
int Player::getlives()
{
	return numlives;
}

//====================================================== 
// setlives: sets the players number of lives
// parameters:  int
// return type: n/a
//======================================================
void Player::setlives(int Num)
{
	numlives = Num;
}

//====================================================== 
// draw: draws the player's ship on the frame
// parameters:  window
// return type: n/a
//======================================================
void Player::draw(RenderWindow & win)
{
	win.draw(ship);
}

//====================================================== 
// setposition: sets the players position
// parameters:  Vector2f coordinates
// return type: n/a
//======================================================
void Player::setposition(Vector2f coord)
{
	ship.setPosition(coord);
}

//====================================================== 
// getposition: gets the players position
// parameters:  n/a
// return type: Vector2f
//======================================================
Vector2f Player::getposition()
{
	return ship.getPosition();
}

//====================================================== 
// detecthit: detects a bomb hit on player
// parameters: bombslist
// return type: n/a
//======================================================
void Player::detecthit(Bombslist & bombs)
{
	list<Bomb>& bomblist = bombs.getlist();
	list<Bomb>::iterator it;
	for (it = bomblist.begin(); it != bomblist.end(); )
	{
		if (ship.getGlobalBounds().contains(it->getpos()))
		{
			numlives = numlives - 1;
			it = bomblist.erase(it);
			
		}
		else
			it++;
	}
}

