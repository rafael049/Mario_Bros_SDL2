#pragma once

#include "Vector2.h"
#include <vector>
#include "MapTile.h"
#include "Texture.h"

class TileManager
{
public:
	// --- Constructors ---
	TileManager();
	~TileManager();

	// --- Variables ----



	// tiles list
	static std::vector <MapTile*> array_Tiles;

	// --- Metods ----
	static void createTile( Vector2 pos, TileType type );
	static void renderTiles();
	static void mouseAdd();
	static void selectTile();
	static void update();

private:
    static TileType selectedTile;
    static int selectedTile_Int;
    static void updateEnumTile();

};

