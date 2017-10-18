#include <iostream>
#include "TileManager.h"
#include "inputHandler.h"
#include "Camera.h"

std::vector <MapTile*> TileManager::array_Tiles;
TileType TileManager::selectedTile;
int TileManager::selectedTile_Int = 1;

TileManager::TileManager()
{

}


TileManager::~TileManager()
{
	for (int i = 0; i < array_Tiles.size(); i++) {
		delete array_Tiles[i];
	}
}

void TileManager::createTile( Vector2 pos, TileType type ){

    // Create Tile
	MapTile* novo = new MapTile( pos, type );
    // Add to array of Tiles
    array_Tiles.push_back( novo );

}

void TileManager::renderTiles(){

	for (int i = 0; i < array_Tiles.size(); i++) {
		array_Tiles[i]->render();
	}
}

void TileManager::mouseAdd() {
    /*static*/ bool flag = true;

    Vector2 pos = inputHandler::mPos;
    pos = pos;
    // Trunk posistion
	Vector2 adjPos;
	int restoX = (int) pos.x % (16*SCALE);
	int restoY = (int) pos.y % (16*SCALE);

	adjPos.x =  (int)pos.x - restoX;
	adjPos.y =  (int)pos.y - restoY ;

    adjPos.y -= 3*SCALE;
    // Spawn Tile
	if( inputHandler::mRB ){
		if (flag == true) {
			createTile( adjPos, selectedTile);
			flag = false;
		}
	}
	else {
		flag = true;
	}

	// Drawn Spawn Area
	SDL_Rect spawArea = { adjPos.x - Camera::camPos.x , adjPos.y - Camera::camPos.y, 16*SCALE, 16*SCALE};
	SDL_RenderDrawRect(Graphics::gRenderer, &spawArea);
}

void TileManager::selectTile(){

    // Select Current Tile with the mouse Wheel
    static bool flag = true;

    if( inputHandler::kAction2 == true){
        if(flag){
            selectedTile_Int++;
            updateEnumTile();
            flag = false;
        }
    }
    else{
        flag = true;
    }

   /* if( inputHandler::mWhD == true){
        selectedTile_Int--;
        updateEnumTile();
    }*/


}

void TileManager::updateEnumTile(){
    switch(selectedTile_Int){
    case 0:
        selectedTile = TI_BRICK; break;
    case 1:
        selectedTile = TI_BRICKTOP; break;
    case 2:
        selectedTile = TI_ROCKS; break;
    case 3:
        selectedTile = TI_BUSH; break;
    case 4:
        selectedTile = TI_BUSH; break;
    case 5:
        selectedTile = TI_BUSH; break;
    case 6:
        selectedTile = TI_BUSH; break;
    default:
        selectedTile_Int = 0; break;

    }
    std::cout << selectedTile_Int;
}

void TileManager::update() {
	renderTiles();
	selectTile();
	mouseAdd();

}
