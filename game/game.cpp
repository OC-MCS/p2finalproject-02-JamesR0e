//===========================================================
// James Roe
// 4/19/19
// Final Project: Space Invaders
//===========================================================

#include <iostream>
#include <ctime>
#include <cstdlib>
#include "Missile.h"
#include "MissilesList.h"
#include "Player.h"
#include "Alien.h"
#include "AliensList.h"
#include "UI.h"
using namespace std;
#include <SFML/Graphics.hpp>
using namespace sf; 


//====================================================== 
// moveship: handles keypress input
// parameters:  Player
// return type: n/a
//======================================================
void moveShip(Player & ship)

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

//====================================================== 
// main: handles input, draws frame, animation loop etc; 
// parameters:  n/a
// return type: n/a
//======================================================

int main()
{
	const int WINDOW_WIDTH = 800;
	const int WINDOW_HEIGHT = 600;

	RenderWindow window(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "aliens!");
	
	window.setFramerateLimit(60); // 60 fps


	//TEXTURE LOADING
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
	if (!AlienTexture.loadFromFile("enemy1.png"))
	{
		cout << "unable to load alien texture" << endl;
		exit(EXIT_FAILURE);
	}
	Texture Alien2Texture;
	if (!Alien2Texture.loadFromFile("enemy2.png"))
	{
		cout << "unavle to load alien2 texture" << endl;
		exit(EXIT_FAILURE);
	}
	Texture bombtexture;
	if (!bombtexture.loadFromFile("bomb.png")) //temp
	{
		cout << "unable to load bomb texture" << endl;
		exit(EXIT_FAILURE);
	}

	
	//background image sprite
	Sprite background;
	background.setTexture(starsTexture);
	// The texture file is 640x480, so scale it up a little to cover 800x600 window
	background.setScale(1.5, 1.5);

	
	

	Vector2f shipPos;
	// initial position of the ship
	shipPos.x = window.getSize().x / 2.0f;
	shipPos.y = window.getSize().y / 1.2f;

	//creates the player ship
	Player ship(shipTexture, shipPos, 3);

	//creates the enemy levels
	AliensList* aliens1 = new AliensList(AlienTexture, .3); //level 1 aliens;
	AliensList* aliens2 = new AliensList(Alien2Texture, .7); //level 2 aliens; different texture and different speed 

	Missiles list; //list of missiles
	Missile* ptr; //using for dynamically allocating a missile
	int framecount = 0; //counts the frames for timing
	bool canshoot = true; //used for shoot timing
	int randomnum;
	Bombslist bombs; //list of bombs
	bool candrop; // bomb drop boolean
	UI userint; // user interface
	int loosetimer = 0; //timer for lose screen
	int wintimer = 0; //timer for win screen

	
	while (window.isOpen())
	{
		
		Event event;
		if (userint.getlevel() == 0) // no level; start screen
		{
		
			while (window.pollEvent(event))
			{
				// "close requested" event: we close the window
				if (event.type == Event::Closed)
					window.close();
				
				
				else if (event.type == Event::MouseButtonReleased)
				{
					//checks for start button pressed
					Vector2f mousePos = window.mapPixelToCoords(Mouse::getPosition(window));
					userint.startinput(mousePos);

				}
				
			}
			window.clear();

			window.draw(background);
			userint.drawSTART(window); //display start window
			window.display();
		}
		else if (userint.getlevel() == 1) //level 1
		{
			framecount++; //
			if ((framecount % 15) == 14)
			{
				canshoot = true;
			}
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
						ptr = new Missile(ship.getposition(), missiletexture);
						list.addMissile(*ptr);
						canshoot = false;
					}

				}
			}
			window.clear();

			window.draw(background);
			moveShip(ship); // moves ship
			ship.draw(window); //draws ship

			if (framecount % 60 == 1) //bombdrop minimum (1 second)
			{
				candrop = true;
			}
			randomnum = (rand() % 80); //bombdrop maximum (1.3 seconds)
			if (randomnum == 1 && candrop == true)
			{
				aliens1->dropbombs(bombtexture, bombs);//drops bombs
				candrop = false;
			}

			userint.drawNUMKILLED(window); //draws numkilled stats
			userint.drawNUMLIVES(window); //draws numlives stats
			userint.drawNUMLEVEL(window); //draws numlevel stats
			userint.setlives(ship.getlives());

			aliens1->sethits(list); //checks aliens against missiles
			aliens1->removeAlien(background, userint); //removes aliens
			aliens1->draw(window);

			bombs.removebomb(background); //removes bombs
			bombs.draw(window);
			list.removemissile(background); //removes missiles
			list.drawMissiles(window); //draws missiles
			
			
			ship.detecthit(bombs); //detects bombs hitting

		
			

			if (aliens1->aliensleft() == 0) //checks next level
			{
				userint.setlevel(2); //next level
			}
			if (userint.getlives() == 0) //checks if all lives are lost
			{
				userint.setlevel(3); //game over
			}
			window.display();
		}
		else if (userint.getlevel() == 2) // level 2
		{
			framecount++;
			if ((framecount % 15) == 14)
			{
				canshoot = true;
			}
			while (window.pollEvent(event))
			{
				// "close requested" event: we close the window
				if (event.type == Event::Closed)
					window.close();
				else if (event.type == Event::KeyPressed)
				{
					if (event.key.code == Keyboard::Space && canshoot == true)
					{
						// handle space bar]
						ptr = new Missile(ship.getposition(), missiletexture);
						list.addMissile(*ptr);
						canshoot = false;
					}

				}
			}
			window.clear();

			window.draw(background);
			moveShip(ship);
			ship.draw(window);
			
			if (framecount % 30 == 1) //min interval (half second on lvl 2)
			{
				candrop = true;
			}
			randomnum = (rand() % 60); //max interval (full second)
			if (randomnum == 1 && candrop == true)
			{
				aliens2->dropbombs(bombtexture, bombs);
				candrop = false;
			}

			userint.drawNUMKILLED(window);
			userint.drawNUMLIVES(window);
			userint.drawNUMLEVEL(window);
			userint.setlives(ship.getlives());

			aliens2->sethits(list);
			aliens2->removeAlien(background, userint);
			aliens2->draw(window);

			bombs.removebomb(background);
			bombs.draw(window);
			list.removemissile(background);
			list.drawMissiles(window);

			ship.detecthit(bombs);

			if (aliens2->aliensleft() == 0)
			{
				userint.setlevel(4);
			}
			if (userint.getlives() == 0)
			{
				userint.setlevel(3);
			}

			window.display();
		}
		else if (userint.getlevel() == 3) //lose page
		{
			window.clear();
			window.draw(background);
			userint.drawGAMEOVER(window); //draws gameover screen
			loosetimer++;
			if (loosetimer % 300 == 299) //gameover screen timer
			{
				delete aliens1;
				delete aliens2;
				aliens1 = new AliensList(AlienTexture, .3);  //creates new alienslist
				aliens2 = new AliensList(Alien2Texture, .7);
				userint.setlevel(0); //resetting UI stats
				userint.setkills(0);
				ship.setlives(3);
			}
			window.display();
		}
		else if (userint.getlevel() == 4) //win page
		{
			window.clear();
			window.draw(background);
			userint.drawYOUWIN(window); //draws win screen
			wintimer++;
			if (wintimer % 300 == 299) //win screen timer
			{
				delete aliens1;//deletes existing alienslist
				delete aliens2;
				aliens1 = new AliensList(AlienTexture, .3);  //creates new alienslist
				aliens2 = new AliensList(Alien2Texture, .7);
				userint.setlevel(0);
				userint.setkills(0);
				userint.setlives(3);
			}
			window.display();

	
		}
		

	} // end body of animation loop

	return 0;
}

