#pragma once
#include <iostream>
using namespace std;
#include <SFML/Graphics.hpp>
using namespace sf;

class MissileTexture
{
private:
	Texture missiletexture;
public:
	MissileTexture();
	Texture gettexture();
};