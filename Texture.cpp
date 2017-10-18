#include "Texture.h"
#include <iostream>
#include <string>
#include <sstream>

#include "Camera.h"
#include "Consts.h"




//--DEFINICOES

Texture::Texture( ){
    mTexture = NULL;
    mWidth = 0;
    mHeight = 0;

}

Texture::~Texture(){
    free();
}

bool Texture::loadFromFile(std::string file){

    // Clean
    free();

    // Final Texture
    SDL_Texture* newTexture = NULL;

    // Load
    std::string path = "Images/";
    path += file;

    SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
    if( loadedSurface == NULL ){
        printf( "Erro ao carregar imagem %s,\n %s\n", path.c_str(), IMG_GetError());
    }

    // Color key ( Alpha )
    SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB( loadedSurface->format, 0, 0xFF, 0xFF ) );

    // Create texture from surface pixels
    newTexture = SDL_CreateTextureFromSurface( Graphics::gRenderer, loadedSurface );

    // Get dimentions
    mWidth = loadedSurface->w;
    mHeight = loadedSurface->h;

    // Clean surface
    SDL_FreeSurface(loadedSurface);

    // Set mTexture
    mTexture = newTexture;

	return true;

}

//bool Texture::loadFromRenderedText(std::string textureText, SDL_Color textColor){
//    free();
//
//    //create surface
//    SDL_Surface* textSurface = TTF_RenderText_Blended(fontBig, textureText.c_str(), textColor);
//    if(textSurface == NULL){
//        printf("erro ao render text surface\n");
//    }
//    else{
//        //create texture
//        mTexture = SDL_CreateTextureFromSurface(gRenderer,textSurface);
//        if(mTexture == NULL){
//            printf("erro ao criar textura de texto a partir da Surface\n");
//        }
//        else{
//            mWidth = textSurface->w;
//            mHeight = textSurface->h;
//        }
//        SDL_FreeSurface(textSurface);
//    }
//    return mTexture != NULL;
//}
//
void Texture::free(){

    if(mTexture != NULL){
        SDL_DestroyTexture(mTexture);
        mTexture = NULL;
        mWidth = 0;
        mHeight = 0;
    }
}

void Texture::SetColor(Uint8 red, Uint8 green, Uint8 blue){

    SDL_SetTextureColorMod(mTexture, red, green, blue);
}

void Texture::SetBlendMode(SDL_BlendMode blending){

    SDL_SetTextureBlendMode(mTexture, blending);
}

void Texture::setAlpha(Uint8 alpha){

    SDL_SetTextureAlphaMod(mTexture, alpha);
}

// --- General Render
void Texture::render(Vector2 renderPos, bool Static, SDL_Rect* clip, double angle, SDL_Point* center, SDL_RendererFlip flip){

    SDL_Rect renderQuad;

    if(Static) // is static
        renderQuad = { (int) renderPos.x - mWidth / 2,  (int) renderPos.y - mHeight / 2, mWidth * SCALE, mHeight * SCALE };
    else       //isn't static
        renderQuad = {(int) (renderPos.x - mWidth / 2 - Camera::camPos.x),  (int) (renderPos.y - mHeight / 2 - Camera::camPos.y), mWidth * SCALE, mHeight * SCALE };

    // For sprites
    if(clip != NULL){
        renderQuad.w = clip->w * SCALE;
        renderQuad.h = clip->h * SCALE;
    }

    // Render to screen
    SDL_RenderCopyEx( Graphics::gRenderer, mTexture, clip, &renderQuad, angle, center, flip);
}

// --- Sprite Render
void Texture::render( Vector2 renderPos, SDL_Rect* clip, SDL_RendererFlip flip ) {

	SDL_Rect renderQuad;
	
	// Set renderQuad Position and Size
	renderQuad = { (int)(renderPos.x /*- clip->w*SCALE / 2*/ - Camera::camPos.x),  (int)(renderPos.y/* - clip->h*SCALE / 2*/ - Camera::camPos.y), mWidth, mHeight };

	// Resize renderQuad to render a tile
	if (clip != NULL) {
		renderQuad.w = clip->w * SCALE;
		renderQuad.h = clip->h * SCALE;
	}

	// Render to screen
	SDL_RenderCopyEx(Graphics::gRenderer, mTexture, clip, &renderQuad, NULL, NULL, flip);
}

int Texture::getWidth(){
    return mWidth;
}

int Texture::getHeight(){
    return mHeight;
}




