#pragma once
#include <vector>
#include "Character.h"
using namespace std;



class Player : public Character
{
public:

    // Constructor
	Player();

	// Upadate all functions
	void update();

	// Array of players
    static vector < Player* > arrayPlayers;

    // External Jump Call
	void jumpCall( int force);

private:

    enum ANIMATION{ ANIM_STOP, ANIM_RUN, ANIM_JUMP };
    // Animation
	ANIMATION currentAnim;

	// --- Functions ---

	// Key press and set velocity
    void checkInput();

	// Animations Manager
	void animsSet();

	// Manage amimations events
	void animManager();

	// visual debug
	void debug();

	void resetPos();
};

