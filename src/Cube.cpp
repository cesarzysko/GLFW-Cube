#include "Cube.h"

Cube::Cube() : m_size(0.5f)
{
    m_faces[CubeFace_Left]   = Face(Vector3F(-1, -1, -1), Vector3F(-1, -1,  1), Vector3F(-1,  1,  1), Vector3F(-1,  1, -1));
    m_faces[CubeFace_Right]  = Face(Vector3F( 1, -1,  1), Vector3F( 1, -1, -1), Vector3F( 1,  1, -1), Vector3F( 1,  1,  1));
    m_faces[CubeFace_Bottom] = Face(Vector3F(-1, -1, -1), Vector3F( 1, -1, -1), Vector3F( 1, -1,  1), Vector3F(-1, -1,  1));
    m_faces[CubeFace_Top]    = Face(Vector3F(-1,  1, -1), Vector3F( 1,  1, -1), Vector3F( 1,  1,  1), Vector3F(-1,  1,  1));
    m_faces[CubeFace_Back]   = Face(Vector3F(-1,  1, -1), Vector3F(-1, -1, -1), Vector3F( 1, -1, -1), Vector3F( 1,  1, -1));
    m_faces[CubeFace_Front]  = Face(Vector3F(-1,  1,  1), Vector3F(-1, -1,  1), Vector3F( 1, -1,  1), Vector3F( 1,  1,  1));
}

void Cube::Draw(float colorProgress)
{
    for (Face face : m_faces)
    {
        face.Draw(m_size, colorProgress);
    }
}
