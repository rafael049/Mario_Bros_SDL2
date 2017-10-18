#include <iostream>
#include "Vector2.h"
#include "Graphics.h"

#include "gameManger_Vars.h"
#include "GameManager.h"
#include "inputHandler.h"

#include "Texture.h"

#include "Scene_Beta.h"

#include "Dot.h"



int main(int argc, char *argv[]){


    // --- Game System ---

    GameManager gameManager;

    Graphics graph;

    inputHandler input;


    // --- Scenes ---
    Scene_Beta sceneBeta;


    // --- SetUps ---
    graph.setRenderColor(0, 0, 0xFF, 0xFF);



    while ( gameManager.quit() == false ){

        input.checksKeys();

        Graphics::clearScreen();

        sceneBeta.render();
        sceneBeta.update();

        Graphics::updateScreen();

		///SDL_Delay(20);









    }

    return 0;
}
