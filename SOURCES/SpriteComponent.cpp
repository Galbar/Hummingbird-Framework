#include "SpriteComponent.h"
#include <iostream>
using namespace hb;


SpriteComponent::SpriteComponent(sf::Sprite* sprite, RenderWindowManager* render_manager):
DataComponent<sf::Sprite*>(sprite),
m_visible(true),
m_render_manager(render_manager)
{}


void SpriteComponent::setRenderWindowManager(RenderWindowManager* render_manager)
{
	m_render_manager = render_manager;
}


RenderWindowManager* SpriteComponent::getRenderWindowManager()
{
	return m_render_manager;
}


const RenderWindowManager* SpriteComponent::getRenderWindowManager() const
{
	return m_render_manager;
}


void SpriteComponent::setSprite(sf::Sprite* sprite)
{
	setData(sprite);
}


sf::Sprite* SpriteComponent::getSprite()
{
	return getData();
}


const sf::Sprite* SpriteComponent::getSprite() const
{
	return getData();
}


bool SpriteComponent::isVisible() const
{
	return m_visible;
}


void SpriteComponent::setVisible(bool visible)
{
	m_visible = visible;
}


void SpriteComponent::postUpdate()
{
	if (m_visible)
	{
		float x = getPosition().x + getGameObject()->getPosition().x;
		float y = getPosition().y + getGameObject()->getPosition().y;
		getData()->setPosition(x, y);
		x = getScale().x * getGameObject()->getScale().x;
		y = getScale().y * getGameObject()->getScale().y;
		getData()->setScale(x, y);
		x = getRotation() + getGameObject()->getRotation();
		getData()->setRotation(x);
		if (getData()->getTexture())
			getData()->setOrigin(getData()->getTexture()->getSize().x / 2, getData()->getTexture()->getSize().y / 2);
		double z_index = getZIndex() + getGameObject()->getZIndex();
		m_render_manager->addDrawable(std::pair<double, sf::Drawable*>(z_index, getData()));
	}
}
