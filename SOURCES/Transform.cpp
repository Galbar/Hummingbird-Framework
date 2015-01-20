#include "Transform.h"
using namespace hb;

Transform::Transform():
m_position(Vector2d()),
m_scale(Vector2d(1, 1)),
m_z_index(0),
m_rotation_angle(0)
{}


Transform::~Transform()
{}


const Vector2d& Transform::getPosition() const
{
	return m_position;
}


void Transform::setPosition(const Vector2d& position)
{
	m_position = position;
}


double Transform::getZIndex() const
{
	return m_z_index;
}


void Transform::setZIndex(double z_index)
{
	m_z_index = z_index;
}


double Transform::getRotation() const
{
	return m_rotation_angle;
}


void Transform::setRotation(double angle)
{
	m_rotation_angle = angle;
}


const Vector2d& Transform::getScale() const
{
	return m_scale;
}


void Transform::setScale(const Vector2d& scale)
{
	m_scale = scale;
}
