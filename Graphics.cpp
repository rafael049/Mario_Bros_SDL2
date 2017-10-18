#include "Graphics.h"
#include "Camera.h"

// Static Members
SDL_Window* Graphics:: gWindow;
SDL_Renderer* Graphics:: gRenderer;

Graphics::Graphics()
{
    //SDL init
    SDL_Init(SDL_INIT_VIDEO);

    //Activate Filter
    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "0");

    //Create Window
    gWindow = SDL_CreateWindow("teste", 0, 20, SCREEN_WIDTH, SCREEN_HEIGHT,SDL_WINDOW_SHOWN);

    //Create Render
    gRenderer = SDL_CreateRenderer(gWindow,-1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    //Render Color
    SDL_SetRenderDrawColor(gRenderer, 0, 0x0F, 0xFF, 0xFF );

    //PNG load
    IMG_Init(IMG_INIT_PNG);

    //TTF Fonts
    TTF_Init();

    //SDL Mixer
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT,2, 2048);
}

Graphics::~Graphics()
{

    SDL_DestroyRenderer(gRenderer);
    gRenderer = NULL;

    SDL_DestroyWindow(gWindow);
    gWindow = NULL;

    Mix_Quit();
    TTF_Quit();
    IMG_Quit();
    SDL_Quit();
}

void Graphics::clearScreen(){
    SDL_RenderClear( gRenderer );
}

void Graphics::updateScreen(){
    SDL_RenderPresent( gRenderer );
}

void Graphics::setRenderColor( Uint8 r, Uint8 g, Uint8 b, Uint8 a ){
    SDL_SetRenderDrawColor( gRenderer, r, g, b, a );
}

void Graphics::drawnLine( Vector2 origin, Vector2 destiny ){

    SDL_RenderDrawLine( gRenderer, origin.x - Camera::camPos.x, origin.y - Camera::camPos.y,
                        destiny.x - Camera::camPos.x, destiny.y - Camera::camPos.y );
    
}

