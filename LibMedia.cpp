#include "LibMedia.h"

// External members
Texture LibMedia::background;
Texture LibMedia::mario;
Texture LibMedia::mapTiles;
Texture LibMedia::goomba;

LibMedia::LibMedia(){
	background.loadFromFile("BackGround.png");
	mario.loadFromFile( "sprites_mario.png" );
	goomba.loadFromFile( "Goomba.png" );
	mapTiles.loadFromFile( "MapTiles.png" );
}


LibMedia::~LibMedia()
{
}
