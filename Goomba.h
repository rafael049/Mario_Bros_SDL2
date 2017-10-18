#ifndef GOOMBA_H
#define GOOMBA_H
#include "Player.h"
#include "Character.h"

class Goomba : public Character
{
    public:
        Goomba();
        virtual ~Goomba();

        void update();

    private:
        enum ANIMATION { ANIM_STOP, ANIM_RUN, ANIM_DIE};
        ANIMATION currentAnim;

        // --- Functions
        // Animations Manager
        void animsSet();

        // Manage amimations events
        void animManager();

        // Artificial Inteligence
        void ai();

        // Killed by Player
        void die();
};

#endif // GOOMBA_H
