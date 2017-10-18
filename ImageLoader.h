#pragma once
#include <SDL2/SDL.h>
#include "Graphics.h"
#include <string>
#include <sstream>

class ImageLoader
{
public:
	ImageLoader();
	~ImageLoader();

	static SDL_Texture* loadFile( std::string file);
	static void free();


};

