#include "GameObject.h"
using namespace hb;

GameObject::GameObject()
{
	m_position = Vector2d();
	m_z_index = 0;
}


GameObject::~GameObject()
{}


const Vector2d& GameObject::getPosition() const
{
	return m_position;
}


void GameObject::setPosition(const Vector2d& p)
{
	m_position = p;
}


double GameObject::getZIndex() const
{
	return m_z_index;
}


void GameObject::setZIndex(double z_index)
{
	m_z_index = z_index;
}


double GameObject::getRotation() const
{
	return m_rotation_angle;
}


void GameObject::setRotation(double angle)
{
	m_rotation_angle = angle;
}


const Vector2d& GameObject::getScale() const
{
	return m_scale;
}


void GameObject::setScale(const Vector2d& scale)
{
	m_scale = scale;
}


void GameObject::update()
{
	for (Component& component : m_components)
	{
		component.update();
	}
}


GameObject::Component* GameObject::addComponent(const Component& component)
{
	m_components.push_back(component);
	m_components[m_components.size() - 1].setGameObject(this);
	return &m_components[m_components.size() - 1];
}
