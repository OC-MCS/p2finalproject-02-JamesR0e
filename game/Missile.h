#pragma once
#include <iostream>
using namespace std;
#include <SFML/Graphics.hpp>
using namespace sf;
//this class is sort of redundant but it helps me think of something as an instance of a missile instead of a sprite
class Missile
{
private:
	Sprite missile;
	bool used;
public:
	Missile(Texture, Vector2f);
	void move();
	void draw(RenderWindow & win);
	Vector2f getposition();
	bool getUsed();
	void setUsed(bool);
};
