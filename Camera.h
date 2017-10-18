#ifndef CAMERA_H
#define CAMERA_H

#include "Consts.h"
#include "Vector2.h"
#include "Graphics.h"

class Camera
{
    public:
        Camera();
        ~Camera();



    static Vector2 camPos;

    void update();

    private:

        Vector2 camVel;
        int maxVel;

        void checkInput();
        void applyVelocity();
        void mouseControl();

};

#endif // CAMERA_H
