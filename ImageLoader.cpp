#include "ImageLoader.h"



ImageLoader::ImageLoader()
{
}


ImageLoader::~ImageLoader()
{
}

SDL_Texture * ImageLoader::loadFile(std::string file)
{
	// Clean
	free();

	// Final Texture
	SDL_Texture* newTexture = NULL;

	// Load
	std::string path = "Images/";
	path += file;

	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	if (loadedSurface == NULL) {
		printf("Erro ao carregar imagem %s,\n %s\n", path.c_str(), IMG_GetError());
	}

	// Color key ( Alpha )
	SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, 0, 0xFF, 0xFF));

	// Create texture from surface pixels
	newTexture = SDL_CreateTextureFromSurface(Graphics::gRenderer, loadedSurface);

	// Get dimentions
	mWidth = loadedSurface->w;
	mHeight = loadedSurface->h;

	// Clean surface
	SDL_FreeSurface(loadedSurface);

	// Set mTexture
	mTexture = newTexture;

	return true;
}

void ImageLoader::free() {

}
