#ifndef VECTOR_2D
#define VECTOR_2D
#include <SFML/System.hpp>

namespace hb
{
	struct Vector2d
	{
		double x, y;
		Vector2d(): x(0), y(0){};
		Vector2d(double x, double y): x(x), y(y){};
		Vector2d(const sf::Vector2f& v): x(v.x), y(v.y){};
		sf::Vector2f sfVector2f() const
		{
			return sf::Vector2f(x, y);
		}

	};

	Vector2d operator -(const Vector2d& right)
	{
		return Vector2d(-right.x, -right.y);
	}


	Vector2d& operator +=(Vector2d& left, const Vector2d& right)
	{
		left.x += right.x;
		left.y += right.y;
		return left;
	}


	Vector2d& operator -=(Vector2d& left, const Vector2d& right)
	{
		left.x -= right.x;
		left.y -= right.y;
		return left;
	}


	Vector2d operator +(const Vector2d& left, const Vector2d& right)
	{
		Vector2d ret;
		ret.x = left.x + right.x;
		ret.y = left.y + right.y;
		return ret;
	}


	Vector2d operator -(const Vector2d& left, const Vector2d& right)
	{
		Vector2d ret;
		ret.x = left.x - right.x;
		ret.y = left.y - right.y;
		return ret;
	}


	Vector2d operator *(const Vector2d& left, double right)
	{
		return Vector2d(left.x * right, left.y * right);
	}


	Vector2d operator *(double left, const Vector2d& right)
	{
		return Vector2d(left * right.x, left * right.y);
	}


	Vector2d& operator *=(Vector2d& left, double right)
	{
		left.x *= right;
		left.y *= right;
		return left;
	}


	Vector2d operator /(const Vector2d& left, double right)
	{
		Vector2d ret(left);
		ret.x /= right;
		ret.y /= right;
		return ret;
	}


	Vector2d& operator /=(Vector2d& left, double right)
	{
		left.x /= right;
		left.y /= right;
		return left;
	}


	bool operator ==(const Vector2d& left, const Vector2d& right)
	{
		return (left.x == right.x and left.y == right.y);
	}

}
#endif