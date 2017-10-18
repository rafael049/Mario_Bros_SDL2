#pragma once
#include <SDL2/SDL.h>
#include "Vector2.h"
#include "Texture.h"

typedef enum{ TI_BRICK, TI_BRICKTOP, TI_ROCKS, TI_EMPTYBOX, TI_BLOCK1, TI_CLOUD, TI_BUSH, TI_SKY} TileType;

class MapTile
{
public:
	MapTile( Vector2 _pos = {0, 0}, TileType _type = TI_BRICK );

	// --- Constants
	const int WIDTH = 16*SCALE;
	const int HEIGHT = 16*SCALE;

	// --- Variables

	// Texturas
	Texture* texture;

	// Set Tile Type
	void setTile( TileType type );

	// Render Tile
	void render( );

	// Can Collide?
	bool isSolid;

	// Get the Tile type
	SDL_Rect getType();

	// Position of the tile
	Vector2 pos;

	// Type of the tile
	SDL_Rect type;

	// Collider
	SDL_Rect collider;

	// Number of Objects in the scene
	static int count;
};

