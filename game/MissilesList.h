#pragma once
class Missiles
{
private:
	//list of missile objects
	list<Missile> missiles;
	list<Missile>::iterator it;
	
public:
	Missiles()
	{
		missiles = {};
	}
	void removemissile(Sprite background);
	void addMissile(Missile m); // (timing logic in main)
	void drawMissiles(RenderWindow & win);
};
