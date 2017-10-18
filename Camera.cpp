#include "Camera.h"
#include "inputHandler.h"

// Static Members

Vector2 Camera::camPos;

Camera::Camera()
{

    camPos.x = -SCREEN_WIDTH/2;
    camPos.y = -SCREEN_HEIGHT/2;

    camVel.x = 0;
    camVel.y = 0;
}

Camera::~Camera()
{
    //dtor
}

void Camera::update(){
    ///checkInput();
    applyVelocity();
    mouseControl();
    //std::cout << camPos;
}

void Camera::checkInput(){

    // --- Right
    if( inputHandler::kRight ){
        camVel.x = maxVel;
    }

    // --- Left
    else if( inputHandler::kLeft ){
        camVel.x = -maxVel;
    }
    else{
        camVel.x = 0;
    }

    // --- Up
    if( inputHandler::kUp ){
        camVel.y = -maxVel;
    }

    // --- Down
    else if( inputHandler::kDown ){
        camVel.y = maxVel;
    }
    else{
        camVel.y = 0;
    }
}

void Camera::applyVelocity(){
    camPos.x += camVel.x;
    camPos.y += camVel.y;
}

void Camera::mouseControl(){
    if(inputHandler::mLB){

        // Lock Mouse


        // Add Mouse Vel to the camera
        camVel.x = (inputHandler::mRelX > 1 || inputHandler::mRelX < -1 )? -inputHandler::mRelX : 0;
        camVel.y = (inputHandler::mRelY > 1 || inputHandler::mRelY < -1 )? -inputHandler::mRelY : 0;
    }
    else{
        camVel.x = 0;
        camVel.y = 0;
    }
}
