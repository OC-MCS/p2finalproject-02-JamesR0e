#pragma once
#include <iostream>
using namespace std;
#include <SFML/Graphics.hpp>
using namespace sf;
class Missile
{
private:
	Sprite missile;
	bool used;
public:
	Missile(Vector2f,const Texture&);
	void move();
	void draw(RenderWindow & win);
	Vector2f getposition();
	bool getUsed();
	void settrue();
};
