#ifndef SCENE_BETA_H
#define SCENE_BETA_H

#include "Dot.h"
#include "Camera.h"
#include "Player.h"
#include "MapTile.h"
#include "Goomba.h"

class Scene_Beta
{
    public:
        // --- Contructors ---
        Scene_Beta();
        ~Scene_Beta();

        // --- Textures ---


        // --- Camera ---
        Camera camera;


        // --- Objects ---
		Player player;
		Goomba goomba;
        MapTile tile;
		MapTile* tileArray[20];

        // --- Metods ---
        void render();
        void update();


    private:
};

#endif // SCENE_BETA_H
