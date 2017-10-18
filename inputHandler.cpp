#include <SDL2/SDL.h>
#include <iostream>
#include "inputHandler.h"
#include "Graphics.h"
#include "Camera.h"
#include "Consts.h"


// --- Static members ---
// SDL Event
SDL_Event inputHandler::e;

// Keys
bool inputHandler::kEsc = false;
bool inputHandler::kEnter = false;
bool inputHandler::kLeft = false;
bool inputHandler::kRight = false;
bool inputHandler::kUp = false;
bool inputHandler::kDown = false;
bool inputHandler::kJump = false;
bool inputHandler::kAction1 = false;
bool inputHandler::kAction2 = false;
bool inputHandler::quit = false;

// Mouse
bool inputHandler::mLB = false;
bool inputHandler::mRB = false;
bool inputHandler::mWh = false;
bool inputHandler::mWhD = false;
bool inputHandler::mWhU = false;
bool inputHandler::isMov = false;

Vector2 inputHandler::mPos;

int inputHandler::mPosx = 0;
int inputHandler::mPosY = 0;
int inputHandler::mRelX = 0;
int inputHandler::mRelY = 0;


// --- Class Implementation ---

inputHandler::inputHandler()
{
    SDL_WarpMouseInWindow(Graphics:: gWindow, SCREEN_WIDTH/2, SCREEN_HEIGHT/2);

    // Auxiliar Variables for check if the mouse is stoped

    int mpx0, mpy0, mpxF, mpyF;
}

inputHandler::~inputHandler()
{

}


void inputHandler::checksKeys(){

    while ( SDL_PollEvent(&e) != 0){

        // --- Check quit
        if(e.type == SDL_QUIT){
        quit = true;
        }

        // --- Check Esc
        if( e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_ESCAPE ){
            kEsc = true;
        }
        else if(e.type == SDL_KEYUP && e.key.keysym.sym == SDLK_ESCAPE ){
            kEsc = false;
        }

        // --- Check Enter
        if( e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_RETURN ){
            kEnter = true;
        }
        else if(e.type == SDL_KEYUP && e.key.keysym.sym == SDLK_RETURN ){
            kEnter = false;
        }

        // --- Check Right
        if( e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_d ){
            kRight = true;
        }
        else if(e.type == SDL_KEYUP && e.key.keysym.sym == SDLK_d ){
            kRight = false;
        }

        // --- Check Left
        if( e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_a ){
            kLeft = true;
        }
        else if(e.type == SDL_KEYUP && e.key.keysym.sym == SDLK_a ){
            kLeft = false;
        }

        // --- Check Up
        if( e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_w ){
            kUp = true;
        }
        else if(e.type == SDL_KEYUP && e.key.keysym.sym == SDLK_w ){
            kUp = false;
        }

        // --- Check Down
        if( e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_s ){
            kDown = true;
        }
        else if(e.type == SDL_KEYUP && e.key.keysym.sym == SDLK_s ){
            kDown = false;
        }

        // --- Check Jump
        if( e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_SPACE ){
            kJump = true;
        }
        else if(e.type == SDL_KEYUP && e.key.keysym.sym == SDLK_SPACE ){
            kJump = false;
        }

         // --- Check Action 1
        if( e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_e ){
            kAction1 = true;
        }
        else if(e.type == SDL_KEYUP && e.key.keysym.sym == SDLK_e ){
            kAction1 = false;
        }

        // --- Check Action 2
        if( e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_f ){
            kAction2 = true;
        }
        else if(e.type == SDL_KEYUP && e.key.keysym.sym == SDLK_f ){
            kAction2 = false;
        }


        // --- Mouse Events ---

        // Mouse keys

        if(e.type == SDL_MOUSEBUTTONDOWN && e.button.button == SDL_BUTTON_LEFT){
            mLB = true;
        }
        else if(e.type == SDL_MOUSEBUTTONUP && e.button.button == SDL_BUTTON_LEFT){
            mLB = false;
        }

        if(e.type == SDL_MOUSEBUTTONDOWN && e.button.button == SDL_BUTTON_RIGHT){
            mRB = true;
        }
        else if(e.type == SDL_MOUSEBUTTONUP && e.button.button == SDL_BUTTON_RIGHT){
            mRB = false;
        }

        // Mouse whell
        if(e.wheel.direction > 0){
            mWhU = true;
            mWhD = false;
        }
        if(e.wheel.direction < 0){
            mWhD = true;
            mWhU = false;
        }
        if(e.wheel.direction == 0){
            mWhD = false;;
            mWhU = false;
        }



        // Movement

        if(e.type == SDL_MOUSEMOTION){
            //SDL_WarpMouseInWindow(Graphics::gWindow, SCREEN_WIDTH/2, SCREEN_HEIGHT/2);
            isMov = true;

            mPosx = e.motion.x;
            mPosY = e.motion.y;

            mPos.setVector( e.motion.x, e.motion.y );

            // Global Mouse Position
            mPos = mPos + Camera::camPos;

            mRelX = e.motion.xrel;
            mRelY = e.motion.yrel;



        }
        else{
            isMov = false;
            mRelX = 0;
            mRelY = 0;

        }



    }


}





