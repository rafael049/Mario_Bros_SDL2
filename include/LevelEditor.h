#ifndef LEVELEDITOR_H
#define LEVELEDITOR_H
#include "Vector2.h"
#include "inputHandler.h"
#include "Camera.h"

class LevelEditor
{
    public:
        LevelEditor();
        ~LevelEditor();

        void update();

    private:
        static void mouseAdd();
};

#endif // LEVELEDITOR_H
