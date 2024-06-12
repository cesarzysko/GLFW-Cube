#include "Face.h"
#include <GLFW/glfw3.h>

const Vector3F Face::s_colors[6] = 
{
    Vector3F(0, 0.278f, 0.878f),
    Vector3F(0.698f, 0, 0.878f),
    Vector3F(0.82f, 0.094f, 0.094f),
    Vector3F(0.898f, 1, 0.149f),
    Vector3F(0, 0.902f, 0.286f),
    Vector3F(0, 0.902f, 0.812f)
};

int Face::s_colorIterator = 0;

Face::Face(Vector3F v1, Vector3F v2, Vector3F v3, Vector3F v4)
{
    m_vertices[0] = v1;
    m_vertices[1] = v2;
    m_vertices[2] = v3;
    m_vertices[3] = v4;
}

void Face::Draw(float size, float colorProgress)
{
    Vector3F color1 = s_colors[s_colorIterator];
    s_colorIterator = (s_colorIterator + 1) % 6;
    Vector3F color2 = s_colors[s_colorIterator];
    Vector3F color = Vector3F::LerpUnclamped(color1, color2, colorProgress);

    glBegin(GL_QUADS);
    glColor3f(color.x, color.y, color.z);
    for (Vector3F v : m_vertices)
    {
        Vector3F vSized = v * size;
        glVertex3f(vSized.x, vSized.y, vSized.z);
    }
    glEnd();

    glBegin(GL_LINES);
    glColor3f(1, 1, 1);
    for (int i = 1; i < 4; ++i)
    {
        Vector3F begin = m_vertices[i - 1] * size;
        Vector3F end = m_vertices[i] * size;
        glVertex3f(begin.x, begin.y, begin.z);
        glVertex3f(end.x, end.y, end.z);
    }
    glEnd();
}
