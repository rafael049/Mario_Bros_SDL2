#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "Consts.h"
#include "Dot.h"
#include "inputHandler.h"
#include "Texture.h"
#include "Camera.h"



//--DEFINITIONS

Dot::Dot(){

    pos.x = 0;
    pos.y = 0;

    vel.x = VEL0;
    vel.y = VEL0;



}

void Dot::checkInput(){

    // --- Right
    if( inputHandler::kRight ){
        vel.x = 5;
    }


    // --- Left
    else if( inputHandler::kLeft ){
        vel.x = -VELF;
    }
    else{
        vel.x = 0;
    }

    // --- Up
    if( inputHandler::kUp ){
        vel.y = -VELF;
    }
    else if( inputHandler::kDown ){
        vel.y = VELF;
    }
    else{
        vel.y = 0;
    }
}

void Dot::movement(){

    // Apply Velocity
    pos = pos + vel;


}

void Dot::render(Texture& texture){
    SDL_Rect sheet = {texture.getHeight(), texture.getWidth(), 0, 0};

    texture.render( pos );
}




