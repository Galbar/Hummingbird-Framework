#ifndef HB_VECTOR_2D_H
#define HB_VECTOR_2D_H
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
	
	Vector2d operator -(const Vector2d& right);
	Vector2d& operator +=(Vector2d& left, const Vector2d& right);
	Vector2d& operator -=(Vector2d& left, const Vector2d& right);
	Vector2d operator +(const Vector2d& left, const Vector2d& right);
	Vector2d operator -(const Vector2d& left, const Vector2d& right);
	Vector2d operator *(const Vector2d& left, double right);
	Vector2d operator *(double left, const Vector2d& right);
	Vector2d& operator *=(Vector2d& left, double right);
	Vector2d operator /(const Vector2d& left, double right);
	Vector2d& operator /=(Vector2d& left, double right);
	bool operator ==(const Vector2d& left, const Vector2d& right);

}
#endif