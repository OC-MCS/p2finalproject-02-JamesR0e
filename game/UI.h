#pragma once
#include <iostream>
using namespace std;
#include <SFML/Graphics.hpp>
using namespace sf;

class UI
{
private:
	int level;
	int lives;
	int killed;
	RectangleShape strtbttn;
public:
	UI();
	int getlevel();
	int getlives();
	int getkills();
	void setlevel(int);
	void setlives(int);
	void setkills(int);
	void drawSTART(RenderWindow & win);
	void startinput(Vector2f mousepos);
	void drawNUMKILLED(RenderWindow & win);
	void drawNUMLEVEL(RenderWindow & win);
	void drawGAMEOVER(RenderWindow & win);
	void drawYOUWIN(RenderWindow & win);
	void drawNUMLIVES(RenderWindow & win);
};