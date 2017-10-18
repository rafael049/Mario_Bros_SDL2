#include "Physics.h"
#include "TileManager.h"
#include <cmath>

// Static Members
//PoolBall* Physics::getCurrentCollison( PoolBall* ball );
//bool Physics::collisionCircle( PoolBall* ball1, PoolBall* ball2 );


Physics::Physics()
{
    //ctor
}

Physics::~Physics()
{
    //dtor
}

PoolBall* Physics::getCurrentCollison( PoolBall* ball ){

    for( int i = 0; i < BallList::ballArray.size(); i++ ){

        if ( ball != BallList::ballArray[ i ] ){

            if( Physics::collisionCircle( ball, BallList::ballArray[ i ] ) && !BallList::ballArray[i]->isDominant ){
                ball->isDominant = true;
                return BallList::ballArray[ i ];
            }
            else{
                ball->isDominant = false;
            }
        }
    }
    return nullptr;
}

bool Physics::collisionCircle( PoolBall* ball1, PoolBall* ball2 ){

    int a = pow( ( ball1->pos.x - ball2->pos.x ), 2 );
    int b = pow( ( ball1->pos.y - ball2->pos.y ), 2 );
    int distance = sqrt( a + b );


    if ( distance < 64 ){
        return true;
    }

    return false;

}



