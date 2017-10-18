#ifndef PHYSICS_H
#define PHYSICS_H

#include <SDL2/SDL.h>
#include <vector>
#include "Vector2.h"
#include "PoolBall.h"
#include "BallList.h"
#include "MapTile.h"

class Physics
{
    public:
        Physics();
        ~Physics();

        // PoolBall get collision
        static PoolBall* getCurrentCollison( PoolBall* ball );

        // Verify Circle Collision
        static bool collisionCircle( PoolBall* ball1, PoolBall* ball2);

		// Array of the objects in collision
		//static std::vector <MapTile*> collisorList;



    private:
};

#endif // PHYSICS_H
