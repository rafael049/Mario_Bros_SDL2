#ifndef VECTOR2_H
#define VECTOR2_H

#include <iostream>
#include <iomanip>
#include <cmath>
#include "Consts.h"
using std::ostream;


class Vector2
{
    // Sum and diference of two Vectors
    friend Vector2 operator+ ( Vector2& lVet, const Vector2& rVet );
    friend Vector2 operator- ( Vector2& lVet, Vector2& rVet );

    // Multiplication and division by a integer
    friend Vector2 &operator* ( int c, Vector2& rVet );
    friend Vector2 &operator/ ( int c, Vector2& rVet );
    friend Vector2 &operator/ ( Vector2& rVet, int c );

    // Internal Product
    friend float &operator* ( Vector2& lVet, Vector2& rVet );

    // Output Vector (std::cout << Vector)
    friend ostream &operator << ( ostream &, Vector2& );

    public:

        // Atribution operator
        Vector2 operator = (Vector2 rVet);

        // Multiplication by a constant
        Vector2 &operator * (const float);

        // Contrutors
        Vector2 (float x = 0, float y = 0);
        ~Vector2();

        // Vars
        float x;
        float y;

        // Get Norma of the Vector
        void normalize();
        float getNorma();

        // Rotate Vector
        void rotateVector( float ang );

        // Check if the vector is Null
        bool isNull();

        // Set the Vector
        void setVector(float X, float Y);

    private:

};

#endif // VECTOR2_H
