#include "MapTile.h"
#include "LibMedia.h"

int MapTile::count = 0;

MapTile::MapTile( Vector2 _pos, TileType _type ){

	// Setup Atributes
	pos = _pos;
	isSolid = true;
	setTile( _type );
	//

	// Set Texture
	texture = &LibMedia::mapTiles;

	// Set collider dimensions and position
	collider.w = WIDTH;
	collider.h = HEIGHT;
	collider.x = _pos.x;
	collider.y = _pos.y;

	count++;
	//std::cout << "Number of tiles in the scene: " << count << std::endl;
}

void MapTile::render() {

	texture->render( pos, &type );
}

void MapTile::setTile(TileType _type) {

	switch (_type) {

		case TI_BRICK:
			type = { 32, 0, 16, 16 };
			isSolid = true;
			break;

		case TI_BRICKTOP:
			type = { 16, 0, 16, 16};
			isSolid = true;
			break;
        case TI_ROCKS:
			type = { 0, 0, 16, 16};
			break;
        case TI_BUSH:
			type = { 11*16, 11*16, 48, 16};
			isSolid = false;
			break;
	}
}
