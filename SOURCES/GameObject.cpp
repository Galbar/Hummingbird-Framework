#include "GameObject.h"
using namespace hb;

GameObject::GameObject():
Transform()
{}


GameObject::~GameObject()
{
	for (Component* component : m_components)
		delete component;
}

void GameObject::update()
{
	for (Component* component : m_components)
		component->preUpdate();
	for (Component* component : m_components)
		component->update();
	for (Component* component : m_components)
		component->postUpdate();
}


void GameObject::addComponent(Component* component)
{
	m_components.push_back(component);
	m_components[m_components.size() - 1]->setGameObject(this);
}
