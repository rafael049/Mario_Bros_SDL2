#include "Player.h"
#include "inputHandler.h"
#include "Camera.h"
#include "GameManager.h"
#include "Physics.h"
#include "TileManager.h"
#include "Consts.h"

vector < Player* > Player::arrayPlayers;

Player::Player()
{
    // Set Atributes
    WIDTH = 16 * SCALE;
	HEIGHT = 32 * SCALE;
	VEL0 = 0;
    VELF = 5;
	JUMP = 10;
	SMOOTHNESS = 0.5;

	// Set defaut position
	pos.x = 0;
	pos.y = 0;

	// Set default velocity
	vel.x = VEL0;
	vel.y = VEL0;

	// Set Texture;
	texture = &LibMedia::mario;

	// Set default sheet
	animSheet = { 0, 0, 16, 32 };

	// Set default direction
	direction = SDL_FLIP_NONE;

	// Set Collider Dimension
	collider.w = WIDTH;
	collider.h = HEIGHT;

	// Set physical vars
	ColBottom = true;
	canJump = true;
	moveR = true;
	moveL = true;

	// Add Player to the arrayPlayers
	arrayPlayers.push_back( this );


}

void Player::update() {
    Character::update();
	checkInput();
	animsSet();
	animManager();
	//debug();
	resetPos();

}

void Player::checkInput() {

	// Right
	if( inputHandler::kRight && moveR ){
		smoothVel( VELF);
	}

	// Left
	else if (inputHandler::kLeft && moveL) {
		smoothVel( -VELF );
	}

	// Stop
	else {
		smoothVel( 0 );
	}

	//Jump
	static bool flag = true;
	if (inputHandler::kJump) {
		if (flag) {
			jump( JUMP );
			flag = false;
		}
	}
	else {
		flag = true;
	}

}



void Player::animsSet() {
	// Apply the velocity of the animation
	int frame = GameManager::frame / ANIMSPEED;

	// Anim mario stoped
	if( currentAnim == ANIM_STOP){
		animSheet.x =  0;
	}
	// Anim mario running
	if (currentAnim == ANIM_RUN) {
		frame = frame % 3; // The number of frames of the animation
		animSheet.x = 32 + frame * 16;
	}
	if (currentAnim == ANIM_JUMP) {
		animSheet.x = 6 * 16;
	}

}

void Player::animManager() {
	if (ColBottom) {
		if (vel.x > 0) {
			currentAnim = ANIM_RUN;
			direction = SDL_FLIP_NONE;
		}
		else if (vel.x < 0) {
			currentAnim = ANIM_RUN;
			direction = SDL_FLIP_HORIZONTAL;
		}
		else if (vel.x == 0){
			currentAnim = ANIM_STOP;
		}
	}
	else {
		currentAnim = ANIM_JUMP;
	}
}

void Player::jumpCall( int force){
    vel.y = -force;
}

void Player::debug() {
	Vector2 A, B, C, D;
	A  = pos;

	B.x = pos.x + WIDTH;
	B.y = pos.y;
	//Graphics::drawnLine(pos, B );
	SDL_Rect debugCollider = collider;
	debugCollider.x -= Camera::camPos.x;
	debugCollider.y -= Camera::camPos.y;
	SDL_RenderDrawRect(Graphics::gRenderer, &debugCollider);

	//std::cout << collisors.size() << std::endl;
}

void Player::resetPos() {
	if (inputHandler::kDown) {
		pos.x = 0;
		pos.y = 0;
		vel.x = 0;
		vel.y = 0;
	}
}


