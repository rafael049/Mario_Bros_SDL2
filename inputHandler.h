#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H
#include <SDL2/SDL.h>

#include "Vector2.h"
class inputHandler
{
    public:

        // --- Construtors ---
        inputHandler();
        ~inputHandler();

        // --- Vars ---
        static SDL_Event e;

        // ---Functions
        void checksKeys();


        // --- key Vars ---
        static bool kEsc, kEnter, kLeft, kRight, kUp, kDown, kJump, kAction1, kAction2;

        // --- Mouse Vars ---
        static bool mLB, mRB, mWh, mWhD, mWhU, mMiddle, isMov;
        static int mPosx, mPosY, mRelX, mRelY;
        static Vector2 mPos;

        // --- Window Vars ---
        static bool quit;
};


#endif // INPUTHANDLER_H
