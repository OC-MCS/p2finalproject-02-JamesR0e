#include <iostream>
using namespace std;
#include <SFML/Graphics.hpp>
using namespace sf;
#include "UI.h"

void die(string msg)
{
	cout << msg << endl;
	exit(-1);
}

UI::UI()
{
	level = 0;
	lives = 3;
	killed = 0;
	Vector2f size;
	size.x = 67;
	size.y = 30;
	strtbttn.setSize(size);
	strtbttn.setPosition(366, 300);
	strtbttn.setFillColor(Color::White);
}


void UI::drawSTART(RenderWindow & win)
{
	
	Font font;
	if (!font.loadFromFile("C://Windows//Fonts//Impact.ttf"))
	{
		die("couldn't load font");
	}
	Text start("START", font, 25);
	start.setPosition(strtbttn.getPosition());
	start.setFillColor(Color::Green);
	win.draw(strtbttn);
	win.draw(start);
}

void UI::startinput(Vector2f mousepos)
{
	if (strtbttn.getGlobalBounds().contains(mousepos))
	{
		level = 1;
	}
}

void UI::drawNUMKILLED(RenderWindow & win)
{
	Font font;
	if (!font.loadFromFile("C://Windows//Fonts//Impact.ttf"))
	{
		die("couldn't load font");
	}
	string displaykilled = "ALIENS DEFEATED: " + to_string(killed);
	Text numkilled(displaykilled, font, 25);
	numkilled.setPosition(0,0);
	numkilled.setFillColor(Color::Green);
	win.draw(numkilled);
}
void UI::drawNUMLEVEL(RenderWindow & win)
{
	Font font;
	if (!font.loadFromFile("C://Windows//Fonts//Impact.ttf"))
	{
		die("couldn't load font");
	}
	string displaylevel = "LEVEL:  " + to_string(level);
	Text levelnum(displaylevel, font, 25);
	levelnum.setPosition(275, 0);
	levelnum.setFillColor(Color::Green);
	win.draw(levelnum);
}
void UI::drawGAMEOVER(RenderWindow & win)
{
	Font font;
	if (!font.loadFromFile("C://Windows//Fonts//Impact.ttf"))
	{
		die("couldn't load font");
	}
	string gameoverstring = "GAME OVER: THE ALIENS ARE VICTORIOUS!";
	Text gameoverdisplay(gameoverstring, font, 40);
	gameoverdisplay.setPosition(300, 400);
	gameoverdisplay.setFillColor(Color::Green);
	win.draw(gameoverdisplay);
}
void UI::drawYOUWIN(RenderWindow & win)
{
	Font font;
	if (!font.loadFromFile("C://Windows//Fonts//Impact.ttf"))
	{
		die("couldn't load font");
	}
	string youWinString = "YOU WIN: THE ALIENS HAVE BEEN DEFEATED!";
	Text windisplay(youWinString, font, 40);
	windisplay.setPosition(300, 400);
	windisplay.setFillColor(Color::Green);
	win.draw(windisplay);
}
void UI::drawNUMLIVES(RenderWindow & win)
{
	Font font;
	if (!font.loadFromFile("C://Windows//Fonts//Impact.ttf"))
	{
		die("couldn't load font");
	}
	string displaylives = "LIVES:  " + to_string(lives);
	Text livesnum(displaylives, font, 25);
	livesnum.setPosition(400, 0);
	livesnum.setFillColor(Color::Green);
	win.draw(livesnum);
}

int UI::getlevel()
{
	return level;
}
int UI::getlives()
{
	return lives;
}
int UI::getkills()
{
	return killed;
}
void UI::setlevel(int l)
{
	level = l;
}
void UI::setlives(int l)
{
	lives = l;
}
void UI::setkills(int k)
{
	killed = k;
}