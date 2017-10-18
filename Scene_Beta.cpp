#include "Scene_Beta.h"
#include <SDL2/SDL.h>
#include "GameManager.h"
#include "BallList.h"
#include "MapTile.h"
#include "TileManager.h"
#include "LibMedia.h"

Scene_Beta::Scene_Beta()
{
    // --- Load Media ---

    // Load Textures
	//LibMedia::LibMedia();
	LibMedia libMedia;

    // Sounds

	// --- Setup objects ---
	Vector2 xx(100, 100 );

	tileArray[1] = new MapTile( xx, TI_BRICK );

	for( int i = 0; i< 10 ; i++ ){
		for( int j = 0; j < 200; j++)
            TileManager::createTile( {-800 + (float)j*16*SCALE, 61*SCALE + (float)i*16*SCALE}, TI_ROCKS);
	}


    // Positions



    // Atributes




}

Scene_Beta::~Scene_Beta(){

}

void Scene_Beta::render(){

    LibMedia::background.render({0,0}, false);

}

void Scene_Beta::update(){

	GameManager::frameUpdate(); // Update frame count
    camera.update();
	player.update();
	goomba.update();
	TileManager::update();

}
