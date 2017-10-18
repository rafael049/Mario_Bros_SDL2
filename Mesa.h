#ifndef MESA_H
#define MESA_H

#include "Vector2.h"
#include "Texture.h"

class Mesa
{
    public:

        // --- Constants ---
        const int WIDTH = 64;
        const int HEIGHT = 64;

        // --- Position ---
        Vector2 pos;

        // --- Construtors ---
        Mesa();

        void render( Texture& );
};

#endif // MESA_H
