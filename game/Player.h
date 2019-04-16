#pragma once
class Player
{
private:
	int numlives;
	Sprite player;
public:
	Player(Texture, Vector2f, int);
	void move(int, int);
	int getlives();
	void setlives(int);
	void draw(RenderWindow & win);
	void setposition(Vector2f);
	Vector2f getposition();
};