#include "Character.h"

Character::Character()
{
    //ctor
}

Character::~Character()
{
    //dtor
}

void Character::update() {
	render();
	movement();
	getCollisors();
	getObstacles();
	applyCollisions();
	//checkGrounded();
	gravity();

}

void Character::render() {

	texture->render( pos, &animSheet, direction );
}

void Character::movement() {

	// Apply velocity
	pos = (pos + vel);

	// Apply movement to the collider
	collider.x = pos.x;
	collider.y = pos.y;
}

void Character::smoothVel(float velF) {
	if (velF > 0 && vel.x < velF) {
		vel.x += SMOOTHNESS;
	}
	else if (velF < 0 && vel.x > velF) {
		vel.x -= SMOOTHNESS;
	}
	else if (velF == 0 && vel.x > 0) {
		vel.x -= SMOOTHNESS;
	}
	else if (velF == 0 && vel.x < 0) {
		vel.x += SMOOTHNESS;
	}
}

void Character::getCollisors() {

	collisors = TileManager::array_Tiles;
}

void Character::getObstacles() {

    int margin = 4;
    static int i = 0;

    ColBottom = false;
    ColTop = false;
    ColLeft = false;
    ColRight = false;


	for( auto col : collisors ){
        if( col->isSolid == false )
            continue;

         // Check Ground ant Top Collision
        if( !( col->pos.x > ( pos.x + WIDTH - margin ) || ( col->pos.x + col->collider.w - margin < pos.x) )){
            // Ground Collision
            if( col->pos.y - pos.y < HEIGHT && col->pos.y - pos.y > HEIGHT/2 ){
               ColBottom = true;
               pos.y = col->pos.y - HEIGHT + 2; // Lock player with the ground
            }
            // Top Collision
            if( col->pos.y - pos.y < 0 && col->pos.y - pos.y > -HEIGHT/2 ){
               ColTop = true;
               pos.y = col->pos.y + col->collider.h - 1;
            }
        }

        // Check Left and Right Collision
         if( !( col->pos.y > ( pos.y + HEIGHT - margin ) || ( col->pos.y + col->collider.h - margin < pos.y) )){
            // Right Collision
            if( pos.x + WIDTH > col->pos.x && pos.x < col->pos.x ){
               ColRight = true;
            }
            // Left Collision
            if( pos.x < col->pos.x + col->collider.w && pos.x > col->pos.x ){
               ColLeft = true;
            }
         }


	}// End For

}

void Character::applyCollisions(){
    // Top Collision
    if( ColTop ){
        pos.y += vel.y;
        vel.y = vel.y > 0 ? vel.y : 0;
    }

    // Left Collision
    if( ColLeft ){
        moveL = false;
        pos.x -= vel.x;
        vel.x = vel.x > 0 ? vel.x : 0;
    }
    else{
        moveL = true;
    }

    // Right Collision
    if( ColRight ){
        moveR = false;
        pos.x -= vel.x;
        vel.x = vel.x < 0 ? vel.x : 0;
    }
    else{
        moveR = true;
    }

}
void Character::gravity() {
	if (ColBottom) {
		vel.y = 0;
	}
	else{
		vel.y += GRAV;
	}

}

void Character::jump( int force ){
	// Check if the player is on ground and apply an up velocity
	if(ColBottom && canJump){
		vel.y = -force;
	}
	else {

	}
}


