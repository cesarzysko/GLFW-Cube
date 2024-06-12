#pragma once

struct Vector3F
{
public:
    float x, y, z;

    Vector3F() = default;
    Vector3F(float x, float y, float z) : x(x), y(y), z(z) { }

    friend Vector3F operator+(const Vector3F& left, const Vector3F& right);
    friend Vector3F operator-(const Vector3F& left, const Vector3F& right);
    friend Vector3F operator*(const Vector3F& left, const float right);

    static Vector3F LerpUnclamped(const Vector3F& a, const Vector3F& b, float p);
};
