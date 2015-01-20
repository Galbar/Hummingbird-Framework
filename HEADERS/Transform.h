#ifndef HB_TRANSFORM_H
#define HB_TRANSFORM_H
#include "Vector2d.h"

namespace hb
{
	class Transform
	{
	public:
		Transform();
		~Transform();
		const Vector2d& getPosition() const;
		void setPosition(const Vector2d& p);
		double getZIndex() const;
		void setZIndex(double z_index);
		double getRotation() const;
		void setRotation(double angle);
		const Vector2d& getScale() const;
		void setScale(const Vector2d& scale);

	private:
		Vector2d m_position;
		Vector2d m_scale;
		double m_z_index;
		double m_rotation_angle;
	};
}
#endif