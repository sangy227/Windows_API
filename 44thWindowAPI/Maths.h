#pragma once

struct Vector2
{
	float x;
	float y;

	Vector2(float x, float y)
	{
		this->x = x;
		this->y = y;
	}

	Vector2(const Vector2& other) = default;
	Vector2() = default;
	~Vector2() = default;
};