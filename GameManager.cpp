#include "GameManager.h"
#include "inputHandler.h"
#include <iostream>


//Static members
bool GameManager::gameRunning = true;
int GameManager::frame = 0;

GameManager::GameManager()
{

}

GameManager::~GameManager()
{

}

bool GameManager::quit(){

    if(inputHandler::quit || inputHandler::kEsc){
        gameRunning = false;
        std::cout << "type = SDL quit";
        return true;
    }
    return false;
}

void GameManager::frameUpdate(){
	
	frame++;

	if (frame == 256) {
		frame = 0;
	}
}
