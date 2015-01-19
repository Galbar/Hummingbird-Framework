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
}
#endif