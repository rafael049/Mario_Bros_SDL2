#include "Mesa.h"

Mesa::Mesa()
{
    pos.x = 0;
    pos.y = 0;
}

void Mesa::render( Texture& texture){
    texture.render( pos );
}
