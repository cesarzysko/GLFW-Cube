#pragma once

#include "Face.h"
#include "Vector3F.h"

class Cube
{
private:
    enum CubeFace
    {
        CubeFace_Left,
        CubeFace_Right,
        CubeFace_Bottom,
        CubeFace_Top,
        CubeFace_Back,
        CubeFace_Front
    };

    Face m_faces[6];
    float m_size;

public:
    Cube();

    void Draw(float colorProgress);
};
