#include "Vector3F.h"

Vector3F operator+(const Vector3F& left, const Vector3F& right)
{
    return Vector3F(left.x + right.x, left.y + right.y, left.z + right.z);
}

Vector3F operator-(const Vector3F& left, const Vector3F& right)
{
    return Vector3F(left.x - right.x, left.y - right.y, left.z - right.z);
}

Vector3F operator*(const Vector3F& left, const float right)
{
    return Vector3F(left.x * right, left.y * right, left.z * right);
}

Vector3F Vector3F::LerpUnclamped(const Vector3F& a, const Vector3F& b, float p)
{
    return a + (b - a) * p;
}
