#pragma once
namespace ya {
	struct Vector2
	{
		static Vector2 Zero;
		static Vector2 One;
		static Vector2 Right;
		static Vector2 Left;
		static Vector2 Up;
		static Vector2 Down;

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

		Vector2 operator / (const float value)
		{
			Vector2 temp;
			temp.x = x / value;
			temp.y = y / value;

			return temp;
		}

		Vector2 operator +(const Vector2& other)
		{
			Vector2 temp;
			temp.x = x + other.x;
			temp.y = y + other.y;

			return temp;
		}


		Vector2 operator -(const Vector2& other)
		{
			Vector2 temp;
			temp.x = x - other.x;
			temp.y = y - other.y;

			return temp;
		}

		void operator +=(const Vector2& other)
		{
			x += other.x;
			y += other.y;
		}
	};
}