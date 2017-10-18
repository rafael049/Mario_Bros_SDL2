#include "Goomba.h"


Goomba::Goomba()
{
     // Set Atributes
    WIDTH = 16 * SCALE;
	HEIGHT = 16 * SCALE;
	VEL0 = 0;
    VELF = 2;
	JUMP = 10;
	SMOOTHNESS = 0.5;

	// Set defaut position
	pos.x = 100;
	pos.y = -1000;

	// Set default velocity
	vel.x = VELF;
	vel.y = VEL0;

	// Set Texture;
	texture = &LibMedia::goomba;

	// Set default sheet
	animSheet = { 0, 0, 16, 16 };

	// Set default direction
	direction = SDL_FLIP_NONE;

	// Set Collider Dimension
	collider.w = WIDTH;
	collider.h = HEIGHT;

	// Set physical vars
	ColBottom = true;
	canJump = true;
	moveR = false;
	moveL = false;

	// Set Enemy atributes
	killed = false;
}

Goomba::~Goomba()
{
    //dtor
}

void Goomba::update(){
    Character::update();
    if( !killed ){
        die();
        ai();
        animsSet();
        animManager();

    }

}

void Goomba::ai(){
    if(ColRight)
        vel.x = -VELF;
    if(ColLeft)
        vel.x = VELF;
    if(!ColBottom)
        vel.x = -vel.x;
}

void Goomba::animsSet() {
	// Apply the velocity of the animation
	int frame = GameManager::frame / 16;

	// Anim goomba stoped
	if( currentAnim == ANIM_STOP){
		animSheet.x = 16;
	}
	// Anim goomba running
	if (currentAnim == ANIM_RUN) {
		frame = frame % 2; // The number of frames of the animation
		animSheet.x = 16 + frame * 16;
	}
	if( currentAnim == ANIM_DIE ){
        animSheet.x = 0;
	}


}

void Goomba::animManager() {
    if( killed ){
        currentAnim = ANIM_DIE;
    }

	else if (ColBottom) {
		if (vel.x > 0) {
			currentAnim = ANIM_RUN;
			direction = SDL_FLIP_NONE;
		}
		else if (vel.x < 0) {
			currentAnim = ANIM_RUN;
			direction = SDL_FLIP_HORIZONTAL;
		}
		else if (vel.x == 0){
			currentAnim = ANIM_RUN;
		}
	}

}

void Goomba::die(){
    int margin = 0;
    for( auto player : Player::arrayPlayers){
        if( !( player->getPosition().x > ( pos.x + WIDTH - margin ) || ( player->getPosition().x + player->getWidth() - margin < pos.x) )
           && ( pos.y -player->getPosition().y > player->getHeight() - margin) && ( pos.y -player->getPosition().y < player->getHeight() + HEIGHT/4)  ){
            currentAnim = ANIM_DIE;
            player->jumpCall( 5 );
            killed = true;
            vel.setVector(0,0);
        }
    }
}

