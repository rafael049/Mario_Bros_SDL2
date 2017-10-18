#ifndef BALLLIST_H
#define BALLLIST_H
#include <iostream>
#include <vector>
#include "PoolBall.h"

class BallList
{
    public:
        // --- Construtors ---

        BallList();
        ~BallList();

        // --- Vars ---

        // Array of Balls in Current Scene
        static std::vector < PoolBall* > ballArray;


        // --- Metods ---

        // Add PollBall to the array
        static void addToArray( PoolBall* ball );
};

#endif // BALLLIST_H
