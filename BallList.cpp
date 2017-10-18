#include "BallList.h"

// Static Members
std::vector < PoolBall* > BallList::ballArray;


// Construtors

BallList::BallList(){

}
BallList::~BallList(){

}

// Metods

void BallList::addToArray( PoolBall* ball ){
    ballArray.push_back( ball );
}




