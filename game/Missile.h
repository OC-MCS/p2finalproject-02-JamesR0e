#pragma once

//this class is sort of redundant but it helps me think of something as an instance of a missile instead of a sprite
class Missile
{
private:
	Sprite missile;
public:
	Missile(Texture, Vector2f);
	void move();
	void draw(RenderWindow & win);
	Vector2f getposition();
};
