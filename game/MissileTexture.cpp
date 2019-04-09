#include "MissileTexture.h"
MissileTexture::MissileTexture()
{
	Texture missileTexture;
	if (!missiletexture.loadFromFile("missile.png"))
	{
		cout << "Unable to load missile texture" << endl;
		exit(EXIT_FAILURE);
	}
	missiletexture = missileTexture;
}
Texture MissileTexture::gettexture()
{
	return missiletexture;
}