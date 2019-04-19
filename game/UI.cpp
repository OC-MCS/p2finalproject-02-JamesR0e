#include <iostream>
using namespace std;
#include <SFML/Graphics.hpp>
using namespace sf;
#include "UI.h"

//====================================================== 
// die: utility function to catch fonts not loading
// parameters:  message
// return type: n/a
//======================================================
void die(string msg)
{
	cout << msg << endl;
	exit(-1);
}

//====================================================== 
// default constructor: sets all the data
// parameters:  n/a
// return type: n/a
//======================================================
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

//====================================================== 
// drawSTART: draws the start screen to the frame
// parameters:  window
// return type: n/a
//======================================================
void UI::drawSTART(RenderWindow & win)
{
	
	Font font;
	if (!font.loadFromFile("C://Windows//Fonts//Impact.ttf"))
	{
		die("couldn't load font");
	}
	Text start("START", font, 25);
	start.setPosition(strtbttn.getPosition());
	start.setFillColor(Color::Blue);
	win.draw(strtbttn);
	win.draw(start);

	Text title("SPACE INVADERS", font, 30);
	title.setPosition(300, 200);
	title.setFillColor(Color::White);
	win.draw(title);
}

//====================================================== 
// startinput: sets the level after the start button pressed
// parameters:  mouseposition
// return type: n/a
//======================================================
void UI::startinput(Vector2f mousepos)
{
	if (strtbttn.getGlobalBounds().contains(mousepos))
	{
		level = 1;
	}
}

//====================================================== 
// drawNUMKILLED: draws the numkilled stat on the top left of the frame
// parameters:  window
// return type: n/a
//======================================================
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

//====================================================== 
// drawNUMLEVEL: draws the numlevel stat on the top of the frame
// parameters: window
// return type: n/a
//======================================================
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

//====================================================== 
// drawGAMEOVER: draws the gameover screen to the frame
// parameters:  window
// return type: n/a
//======================================================
void UI::drawGAMEOVER(RenderWindow & win)
{
	Font font;
	if (!font.loadFromFile("C://Windows//Fonts//Impact.ttf"))
	{
		die("couldn't load font");
	}
	string gameoverstring = "GAME OVER: THE ALIENS ARE VICTORIOUS!";
	Text gameoverdisplay(gameoverstring, font, 40);
	gameoverdisplay.setPosition(50, 300);
	gameoverdisplay.setFillColor(Color::Green);
	win.draw(gameoverdisplay);

	string displaylives = "LIVES REMAINING:  " + to_string(lives);
	Text livesnum(displaylives, font, 25);
	livesnum.setPosition(300, 400);
	livesnum.setFillColor(Color::Green);
	win.draw(livesnum);

	string displaykilled = "TOTAL ALIENS DEFEATED: " + to_string(killed);
	Text numkilled(displaykilled, font, 25);
	numkilled.setPosition(300, 475);
	numkilled.setFillColor(Color::Green);
	win.draw(numkilled);
}

//====================================================== 
// drawYOUWIN: draws the victory screen to the frame
// parameters: window
// return type: n/a
//======================================================
void UI::drawYOUWIN(RenderWindow & win)
{
	Font font;
	if (!font.loadFromFile("C://Windows//Fonts//Impact.ttf"))
	{
		die("couldn't load font");
	}
	string youWinString = "YOU WIN: THE ALIENS HAVE BEEN DEFEATED!";
	Text windisplay(youWinString, font, 40);
	windisplay.setPosition(50, 300);
	windisplay.setFillColor(Color::Green);
	win.draw(windisplay);

	string displaylives = "LIVES REMAINING:  " + to_string(lives);
	Text livesnum(displaylives, font, 25);
	livesnum.setPosition(300, 400);
	livesnum.setFillColor(Color::Green);
	win.draw(livesnum);

	string displaykilled = "TOTAL ALIENS DEFEATED: " + to_string(killed);
	Text numkilled(displaykilled, font, 25);
	numkilled.setPosition(300, 475);
	numkilled.setFillColor(Color::Green);
	win.draw(numkilled);
}

//====================================================== 
// drawNUMLIVES: draws the numlives stat to the top of the screen
// parameters:  window
// return type: n/a
//======================================================
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

//====================================================== 
// getlevel: returns the level
// parameters:  n/a
// return type: int
//======================================================
int UI::getlevel()
{
	return level;
}

//====================================================== 
// getlives: returns the number of lives
// parameters:  n/a
// return type: int
//======================================================
int UI::getlives()
{
	return lives;
}

//====================================================== 
// getkills: returns the number of aliens killed
// parameters:  n/a
// return type: int
//======================================================
int UI::getkills()
{
	return killed;
}

//====================================================== 
// setlevel: sets the level
// parameters:  int
// return type: n/a
//======================================================
void UI::setlevel(int l)
{
	level = l;
}

//====================================================== 
//setlives: sets the number of lives
// parameters:  int
// return type: n/a
//======================================================
void UI::setlives(int l)
{
	lives = l;
}

//====================================================== 
// setkills: sets the number of aliens killed 
// parameters:  int
// return type: n/a
//======================================================
void UI::setkills(int k)
{
	killed = k;
}