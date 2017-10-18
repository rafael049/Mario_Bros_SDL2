#ifndef POOLBALL_H
#define POOLBALL_H

#include <iostream>
#include "Vector2.h"
#include "Consts.h"

#include "inputHandler.h"
#include "Texture.h"


class PoolBall
{
    public:
        PoolBall( int X = 0, int Y = 0 );
        ~PoolBall();

        void update();
        void render( Texture& );

        void impulse();
        void setPosition( Vector2 _pos );
        void setWhite( bool white );

        float mass;
        bool isDominant;
        Vector2 pos;

    private:

        Vector2 vel;
        Vector2 acel;
        float acelNorma;

        int radius;

        bool isTheWhite;

        ///*****
        float velF;
        float velF2;


        void applyVel();
        void applyAcel();

        void ballReflection( Vector2 ballPos );
        void ballReflection2( PoolBall& ball );
        void setMomentum( Vector2& vel2, float ballMass );
        void collision();


};

#endif // POOLBALL_H
