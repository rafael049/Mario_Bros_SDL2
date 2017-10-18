#ifndef LTEXTURA_H
#define LTEXTURA_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
//#include <SDL/SDL_ttf.h>
#include <stdio.h>
#include <string>
#include "Vector2.h"

#include "Graphics.h"




class Texture{
public:
    // Construct
    Texture();

    // Destuct
    ~Texture();

    // Load Image
    bool loadFromFile( std::string path);

    // Create image from string
    bool loadFromRenderedText( std::string textureText, SDL_Color textColor);

    // dealloca textura
    void free();

    // Color modulation
    void SetColor( Uint8 red, Uint8 green, Uint8 blue );

    // Set blending
    void SetBlendMode( SDL_BlendMode blending);

    // Set alpha modulation
    void setAlpha( Uint8 alpha);

    // Render Texture
    void render( Vector2 renderPos, bool Static = false, SDL_Rect* clip = NULL,double angle = 0.0, SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE);
	void render( Vector2 renderPos, SDL_Rect* clip, SDL_RendererFlip flip = SDL_FLIP_NONE );

    // Get dimensoes da imagem
    int getWidth();
    int getHeight();

private:
    // Hard Texture
    SDL_Texture* mTexture;

    //dimensoes
    int mWidth;
    int mHeight;

};
#endif // LTEXTURA_H
