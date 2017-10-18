#include "PoolBall.h"
#include "BallList.h"
#include "Physics.h"
#include <cmath>

PoolBall::PoolBall(int X, int Y)
{
    // Add to the Vector PoolBalls
    BallList::addToArray( this );

    // Set default Velocity Vector and Aceleration Module
    vel.setVector(0, 0);
    acelNorma = -0.1;

    // Set default Radius and Mass
    radius = 64;
    mass = 1;

    // Set as not the white ball as default
    isTheWhite = false;

    isDominant = false;

}

PoolBall::~PoolBall()
{

}

void PoolBall::update(){

    applyVel();
    applyAcel();

    impulse();
    collision();

}

void PoolBall::applyVel(){

    pos = pos + vel;
}

void PoolBall::applyAcel(){

    acel = vel;
    float k = acelNorma/acel.getNorma();
    Vector2 aux;
    aux = vel;
    acel *k;

    if(vel.getNorma() > acel.getNorma()){
        vel = vel + acel;
    }
    else{
        vel.setVector(0, 0);
    }
}

void PoolBall::render(Texture& texture){
    texture.render( pos );
}

void PoolBall::impulse(){
    if(isTheWhite){

        if(inputHandler::mRB){

            vel = ( pos - inputHandler::mPos )* -0.08;

            Graphics::drawnLine( inputHandler::mPos, pos);
        }
    }
}

void PoolBall::ballReflection( Vector2 ballPos ){

    // Vector conecting the balls centers
    Vector2 normal = pos - ballPos;
    // Normalizing the normal vector
    normal = normal / normal.getNorma();

    // Calculating vel projection in normal
    Vector2 proj = ( ( -1*vel ) * normal ) * normal;

    // Vel final
    vel = proj + ( vel + proj );


}

void PoolBall::ballReflection2( PoolBall& ball){
    Vector2& vel2 = ball.vel;

    Vector2 normal = (pos - ball.pos);
    normal = normal / normal.getNorma();

    if( vel.getNorma() > 0.001){
        vel.normalize();
    }
    else{
        vel.setVector(0, 0);
    }

    if( vel2.getNorma() > 0.001){
        vel2.normalize();
    }
    else{
        vel2.setVector(0, 0);
    }

    vel = vel - normal;
    vel.normalize();
    vel2 = ball.vel - normal;
    vel2.normalize();

}

void PoolBall::setMomentum( Vector2& vel2, float ballMass ){

    float temp1, temp2;

    // Calculating final velocity for vel
    temp1 = ( mass - ballMass ) / ( mass + ballMass);
    temp2 = ( 2 * ballMass) / ( mass + ballMass);
    velF = temp1 * vel.getNorma() + temp2 * vel2.getNorma();
    std::cout << velF << std::endl;
    // Apply velF to vel;
    ///vel = vel * velF;

    // Calculating final velocity for vel2
    temp1 = ( ballMass - mass ) / ( mass + ballMass);
    temp2 = ( 2 * mass) / ( mass + ballMass);
    velF2 = temp1 * vel2.getNorma() + temp2 * vel.getNorma();

    // Apply velF to vel2;
    ///vel2 = vel2 * velF;


}

void PoolBall::collision(){

    // Temporaly var
    PoolBall* collider;

    static bool flag = true;

    if( ( collider = Physics::getCurrentCollison( this ) ) != nullptr ){
        if( flag){
            //pos = pos - vel;
            setMomentum( collider->vel, collider->mass);
            ballReflection2( *collider );
            vel = vel*velF;
            collider->vel = collider->vel * velF2;
            flag = false;
        }

    }
    else{
        flag = true;
    }



    ///std::cout << pos << std::endl;
}

void PoolBall::setPosition( Vector2 _pos ){
    pos = _pos;
}

void PoolBall::setWhite( bool white ){
    isTheWhite = white;
}


