#include "LevelEditor.h"

LevelEditor::LevelEditor()
{
    //ctor
}

LevelEditor::~LevelEditor()
{
    //dtor
}

void LevelEditor::mouseAdd() {
    /*static*/ bool flag = true;

    Vector2 pos = inputHandler::mPos;
    pos = pos;
    // Trunk posistion
	Vector2 adjPos;
	int restoX = (int) pos.x % (16*SCALE);
	int restoY = (int) pos.y % (16*SCALE);

	adjPos.x =  (int)pos.x - restoX;
	adjPos.y =  (int)pos.y - restoY ;

    adjPos.y -= 3*SCALE;
    // Spawn Tile
	if( inputHandler::mRB ){
		if (flag == true) {
			//createTile( adjPos, selectedTile);
			flag = false;
		}
	}
	else {
		flag = true;
	}

	// Drawn Spawn Area
	SDL_Rect spawArea = { adjPos.x - Camera::camPos.x , adjPos.y - Camera::camPos.y, 16*SCALE, 16*SCALE};
	SDL_RenderDrawRect(Graphics::gRenderer, &spawArea);
}

