#include "Vector2.h"


Vector2::Vector2(float X, float Y)
{
    x = X;
    y = Y;

}

Vector2::~Vector2()
{
}

Vector2 operator+ ( Vector2& lVet, const Vector2& rVet ){

    Vector2 result;
    result.x = lVet.x + rVet.x;
    result.y = lVet.y + rVet.y;

//
    return result;

}

Vector2 operator- ( Vector2& lVet, Vector2& rVet ){

    Vector2 result;
    result.x = lVet.x + rVet.x;
    result.y = lVet.y + rVet.y;

    return lVet;

}

float &operator* ( Vector2& lVet, Vector2& rVet ){
    float product = (lVet.x * rVet.x) + (lVet.y * rVet.y);
    return product;
}


Vector2 &operator* ( int c, Vector2& rVet ){
    rVet.x *= c;
    rVet.y *= c;

    return rVet;
}

Vector2 &operator/ ( int c, Vector2& rVet ){
    c /= rVet.x;
    c /= rVet.y;

    return rVet;
}

Vector2 &operator/ ( Vector2& rVet, int c ){
    rVet.x /= c;
    rVet.y /= c;

    return rVet;
}

ostream &operator << (ostream &output, Vector2& vet){
    output << "X = " << vet.x << " e " << "Y = "<< vet.y << std::endl;
    return output;
}

Vector2 Vector2::operator = (Vector2 rVet){
    x = rVet.x;
    y = rVet.y;
	return *this;
}

Vector2 &Vector2::operator*(const float k){
    x *= k;
    y *= k;
	return *this;
}

void Vector2::normalize(){
    x = x / getNorma();
    y = y / getNorma();
}

float Vector2::getNorma(){
    return ( sqrt( (x*x) + (y*y) ) );
}

void Vector2::rotateVector(float ang){
    float _x = x;
    float _y = y;

    x = cos( ang )*_x - sin( ang )*_y;
    y = sin( ang )*_x + cos( ang )*_y;

}

bool Vector2::isNull(){
            if( x == 0 && y == 0){
                return true;
            }
            return false;
}

void Vector2::setVector(float X, float Y){
    x = X;
    y = Y;
}
