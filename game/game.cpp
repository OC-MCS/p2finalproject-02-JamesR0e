

//=========================================================
// This is just the starting point for your final project.
// You are expected to modify and add classes/files as needed.
// The code below is the original code for our first graphics
// project (moving the little green ship). 
//========================================================
#include <iostream>
#include "Missile.h"
#include "MissilesList.h"
#include "Player.h"
#include "Alien.h"
#include "AliensList.h"
using namespace std;
#include <SFML/Graphics.hpp>
using namespace sf; 

//============================================================
// James Roe
// 4/19/19
// Final Project: Space Invaders
//============================================================

// note: a Sprite represents an image on screen. A sprite knows and remembers its own position
// ship.move(offsetX, offsetY) adds offsetX, offsetY to 
// the current position of the ship. 
// x is horizontal, y is vertical. 
// 0,0 is in the UPPER LEFT of the screen, y increases DOWN the screen
void moveShip(Sprite& ship)

{
	const float DISTANCE = 5.0;

	if (Keyboard::isKeyPressed(Keyboard::Left))
	{
		// left arrow is pressed: move our ship left 5 pixels
		// 2nd parm is y direction. We don't want to move up/down, so it's zero.
		ship.move(-DISTANCE, 0);
	}
	else if (Keyboard::isKeyPressed(Keyboard::Right))
	{
		// right arrow is pressed: move our ship right 5 pixels
		ship.move(DISTANCE, 0);
	}
}



int main()
{
	const int WINDOW_WIDTH = 800;
	const int WINDOW_HEIGHT = 600;

	RenderWindow window(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "aliens!");
	// Limit the framerate to 60 frames per second
	window.setFramerateLimit(60);

	// load textures from file into memory. This doesn't display anything yet.
	// Notice we do this *before* going into animation loop.
	Texture shipTexture;
	if (!shipTexture.loadFromFile("ship.png"))
	{
		cout << "Unable to load ship texture!" << endl;
		exit(EXIT_FAILURE);
	}
	Texture starsTexture;
	if (!starsTexture.loadFromFile("stars.jpg"))
	{
		cout << "Unable to load stars texture!" << endl;
		exit(EXIT_FAILURE);
	}
	Texture missiletexture;
	if (!missiletexture.loadFromFile("missile.png"))
	{
		cout << "Unable to load missile texture" << endl;
		exit(EXIT_FAILURE);
	}
	Texture AlienTexture;
	if (!AlienTexture.loadFromFile("enemy.png"))
	{
		cout << "unable to load alien texture" << endl;
		exit(EXIT_FAILURE);
	}

	// A sprite is a thing we can draw and manipulate on the screen.
	// We have to give it a "texture" to specify what it looks like

	Sprite background;
	background.setTexture(starsTexture);
	// The texture file is 640x480, so scale it up a little to cover 800x600 window
	background.setScale(1.5, 1.5);

	// create sprite and texture it
	Sprite ship;
	ship.setTexture(shipTexture);


	// initial position of the ship will be approx middle of screen
	float shipX = window.getSize().x / 2.0f;
	float shipY = window.getSize().y / 1.2f;
	ship.setPosition(shipX, shipY);

	AliensList aliens(AlienTexture);

	Missiles list;
	Missile* ptr;
	int framecount = 0; //counts the frames for timing
	bool canshoot = true;

	while (window.isOpen())
	{
		framecount++;
		if ((framecount % 15) == 14)
		{
			canshoot = true;
		}
		// check all the window's events that were triggered since the last iteration of the loop
		// For now, we just need this so we can click on the window and close it
		Event event;

		while (window.pollEvent(event))
		{
			// "close requested" event: we close the window
			if (event.type == Event::Closed)
				window.close();
			else if (event.type == Event::KeyPressed)
			{
				if (event.key.code == Keyboard::Space && canshoot == true)
				{
					// handle space bar
					ptr = new Missile(missiletexture, ship.getPosition());
					list.addMissile(*ptr);
					canshoot = false;
				}
				
			}
		}

		//===========================================================
		// Everything from here to the end of the loop is where you put your
		// code to produce ONE frame of the animation. The next iteration of the loop will
		// render the next frame, and so on. All this happens ~ 60 times/second.
		//===========================================================

	
		// draw background first, so everything that's drawn later 
		// will appear on top of background
		window.draw(background);

		moveShip(ship);
		window.draw(ship);

		aliens.sethits(list);
		aliens.removeAlien();
		aliens.draw(window);
		// draw the ship on top of background 
		// (the ship from previous frame was erased when we drew background)
		

		list.removemissile(background);
		list.drawMissiles(window);
		// end the current frame; this makes everything that we have 
		// already "drawn" actually show up on the screen
		window.display();

		// At this point the frame we have built is now visible on screen.
		// Now control will go back to the top of the animation loop
		// to build the next frame. Since we begin by drawing the
		// background, each frame is rebuilt from scratch.

	} // end body of animation loop

	return 0;
}

