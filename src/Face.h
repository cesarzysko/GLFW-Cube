#pragma once

#include "Vector3F.h"

class Face
{
private:
    static const Vector3F s_colors[6];
    static int s_colorIterator;

    Vector3F m_vertices[4];

public:
    Face() = default;
    Face(Vector3F v1, Vector3F v2, Vector3F v3, Vector3F v4);

    void Draw(float size, float colorProgress);
};
