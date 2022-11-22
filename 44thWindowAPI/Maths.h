#pragma once

#define PI 3.14159265f

#include <cmath>
#include <algorithm>

namespace ya
{
    struct Vector2
    {
        static Vector2 Zero;
        static Vector2 One;
        static Vector2 Up;
        static Vector2 Down;
        static Vector2 Right;
        static Vector2 Left;

        float x;
        float y;

        Vector2() = default;

        Vector2(const Vector2&) = default;
        Vector2& operator=(const Vector2&) = default;

        Vector2(Vector2&&) = default;
        Vector2& operator=(Vector2&&) = default;

        Vector2 operator -()
        {
            return Vector2(-x, -y);
        }

        Vector2 operator+(const Vector2& other)
        {
            Vector2 temp;
            temp.x = x + other.x;
            temp.y = y + other.y;

            return temp;
        }

        Vector2 operator-(const Vector2& other)
        {
            Vector2 temp;
            temp.x = x - other.x;
            temp.y = y - other.y;

            return temp;
        }

        Vector2 operator*(const Vector2& other)
        {
            Vector2 temp;
            temp.x = x * other.x;
            temp.y = y * other.y;

            return temp;
        }

        Vector2 operator*(const float& value)
        {
            Vector2 temp;
            temp.x = x * value;
            temp.y = y * value;

            return temp;
        }

        Vector2 operator/(const float& value)
        {
            Vector2 temp;

            temp.x = x / value;
            temp.y = y / value;

            return temp;
        }

        Vector2& operator +=(const Vector2& other)
        {
            x += other.x;
            y += other.y;

            return *this;
        }

        Vector2& operator *=(const float value)
        {
            x *= value;
            y *= value;

            return *this;
        }

        Vector2& operator -=(const Vector2& other)
        {
            x -= other.x;
            y -= other.y;

            return *this;
        }

        bool operator ==(const Vector2& other)
        {
            return (x == other.x && y == other.y);
        }
        //bool operator !=(const Vector2& other)
        //{
        //    return (x != other.x && y != other.y);
        //}

        constexpr Vector2(float _x, float _y) noexcept
            : x(_x)
            , y(_y)
        {

        }
        explicit Vector2(_In_reads_(2) const float* pArray)  noexcept
            : x(pArray[0])
            , y(pArray[1])
        {

        }

        void clear()
        {
            x = 0.0f;
            y = 0.0f;
        }

        float Length()
        {
            return sqrtf(x * x + y * y);
        }

        Vector2& Normalize()
        {
            float length = Length();
            x /= length;
            y /= length;

            return *this;
        }
    };
    typedef Vector2 Pos;
    typedef Vector2 Size;
}


namespace ya::math 
{
	__forceinline float DegreeToRadian(float degree)
	{
		return degree * (180.0f / PI);
	}

	__forceinline float RadianToDegree(float radian)
	{
		return radian * (PI / 180.0f);
	}

	inline Vector2 Rotate(Vector2 vector,float degree)
	{
        float radian = (degree / 180.f) * PI;
        vector.Normalize();
        float x = cosf(radian) * vector.x - sinf(radian) * vector.y;
        float y = sinf(radian) * vector.x + cosf(radian) * vector.y;

        return Vector2(x, y);
	}

	inline float Dot(Vector2& v1, Vector2& v2)
	{
		return v1.x * v2.x + v1.y * v2.y;
	}

	inline float Cross(Vector2 v1, Vector2 v2)
	{
		return v1.x * v2.y - v1.y * v2.x;
	}

    
    float lerp(float p1, float p2, float t)
    {
        return (1 - t) * p1 + t * p2;
    }

    Vector2 lerp(Vector2 v1, Vector2 v2, float t)
    {
        Vector2 temp;
        temp.x = lerp(v1.x, v2.x, t);
        temp.y = lerp(v1.y, v2.y, t);

        return temp;
    }
}
