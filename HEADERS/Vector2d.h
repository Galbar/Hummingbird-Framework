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
	
}

hb::Vector2d operator -(const hb::Vector2d& right);
hb::Vector2d& operator +=(hb::Vector2d& left, const hb::Vector2d& right);
hb::Vector2d& operator -=(hb::Vector2d& left, const hb::Vector2d& right);
hb::Vector2d operator +(const hb::Vector2d& left, const hb::Vector2d& right);
hb::Vector2d operator -(const hb::Vector2d& left, const hb::Vector2d& right);
hb::Vector2d operator *(const hb::Vector2d& left, double right);
hb::Vector2d operator *(double left, const hb::Vector2d& right);
hb::Vector2d& operator *=(hb::Vector2d& left, double right);
hb::Vector2d operator /(const hb::Vector2d& left, double right);
hb::Vector2d& operator /=(hb::Vector2d& left, double right);
bool operator ==(const hb::Vector2d& left, const hb::Vector2d& right);
#endif