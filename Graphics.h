#ifndef SDL_GRAPHICS_H
#define SDL_GRAPHICS_H

#include "Consts.h"
#include <stdio.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
#include "Vector2.h"


class Graphics
{
    public:
        // --- Constructors ---
        Graphics();
        ~Graphics();

        // --- Variables ---

        static SDL_Window* gWindow;
        static SDL_Renderer* gRenderer;

        // --- Functions ---

        static void clearScreen();
        static void updateScreen();
        static void setRenderColor( Uint8 r = 0xFF, Uint8 g = 0xFF, Uint8 b = 0xFF, Uint8 a = 0xFF );
        static void drawnLine( Vector2 origin, Vector2 destiny );




    private:
};

#endif // SDL_GRAPHICS_H
