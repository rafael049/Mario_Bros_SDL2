#ifndef CHARACTER_H
#define CHARACTER_H
#include <SDL2/SDL.h>
#include <vector>
#include "Vector2.h"
#include "Texture.h"
#include "LibMedia.h"
#include "MapTile.h"
#include "TileManager.h"
#include "GameManager.h"


class Character
{
public:

    Character();
    virtual ~Character();

    void update();

    // --- Atibutes ---
	int WIDTH = 16 * SCALE;
	int HEIGHT = 32 * SCALE;
	int VEL0 = 0;
	int VELF = 5;
	int JUMP = 10;
	float SMOOTHNESS = 0.5;

	// --- Vars ---

	// Position and Velocity vectors
	Vector2 pos;
	Vector2 vel;

	// Texture
	Texture* texture;

    SDL_Rect animSheet;
	SDL_RendererFlip direction;

	// PlayerCollider
	SDL_Rect collider;

	// Array of objects in collision
	std::vector <MapTile*> collisors;


	bool canJump;
	bool moveR;
	bool moveL;

	// Coliisions
	bool ColBottom;
	bool ColTop;
	bool ColLeft;
	bool ColRight;

    // Life Atributes
    bool killed;

	// --- Functions

	// Render
	void render();

	// Apply Velocity
	void movement();

	// Smooth Aceleration
	void smoothVel(float velF);

	// Get collisors list
	void getCollisors();

	// Check if the character is colliding
	void getObstacles();

	// Stop the player movement while in collision
	void applyCollisions();

	// Gravity
	void gravity();

    // Makes the player jump
	void jump( int force );

	// Get Character Atributes
	Vector2 getPosition(){ return pos; }
	int getWidth(){ return WIDTH; }
	int getHeight(){ return HEIGHT; }



    protected:

    private:
};

#endif // CHARACTER_H
