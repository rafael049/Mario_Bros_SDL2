#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include "inputHandler.h"

class GameManager
{
    public:



        // --- Constructors/Des ---
        GameManager();
        ~GameManager();

        // --- Vars ---

		// Is the game ruuning
        static bool gameRunning;

		// Frames
		static int frame;

        // --- Functions ---

        static bool quit();
		static void frameUpdate();


    private:
        // --- Objects ---
        inputHandler input;
};

#endif // GAMEMANAGER_H
