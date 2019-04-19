#pragma once
#include <iostream>
using namespace std;
#include <SFML/Graphics.hpp>
using namespace sf;

class Bomb
{
private:
	Sprite bomb;
	bool used;
public:
	Bomb(Vector2f Alienpos, Texture & bombtexture);
	void draw(RenderWindow & win);
	Vector2f getpos();
};