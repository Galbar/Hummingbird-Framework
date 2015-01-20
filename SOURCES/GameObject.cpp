#include "GameObject.h"
using namespace hb;

GameObject::GameObject():
Transform()
{}


GameObject::~GameObject()
{}

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
