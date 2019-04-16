#include <iostream>
using namespace std;
#include <SFML/Graphics.hpp>
using namespace sf;
#include "Player.h"

Player::Player(Texture texture, Vector2f coord, int lives)
{
	player.setTexture(texture);
	player.setPosition(coord);
	numlives = lives;
}
void Player::move(int x, int y)
{
	player.move(x, y);
}
int Player::getlives()
{
	return numlives;
}
void Player::setlives(int Num)
{
	numlives = Num;
}
void Player::draw(RenderWindow & win)
{
	win.draw(player);
}
void Player::setposition(Vector2f coord)
{
	player.setPosition(coord);
}
Vector2f Player::getposition()
{
	return player.getPosition();
}

