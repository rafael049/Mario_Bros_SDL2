#ifndef DOT_H_INCLUDED
#define DOT_H_INCLUDED

#include <SDL2/SDL.h>
#include "Vector2.h"
#include "Texture.h"



//  DOT CLASSES
class Dot{
    public:

    // --- Constants ---
    const int WIDTH = 64;
    const int HEIGHT = 64;
    const int VEL0 = 0;
    const int VELF = 5;

    // --- Functions ---
    // Contrutor
    Dot();

    // Key press and set velocity
    void checkInput();

    // Aplly Velocity
    void movement();

    // Render
    void render(Texture&);

    // Reset Position
    //void resetPosVel();

    //set Posistion
   // void setPosVel(int x, int y, int vel);


    //pos and vel
    Vector2 pos;
    Vector2 vel;

    //Collision Box

};


#endif // DOT_H_INCLUDED
