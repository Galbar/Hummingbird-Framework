#include "SoundComponent.h"
using namespace hb;

SoundComponent::SoundComponent()
{}


SoundComponent::~SoundComponent()
{}


void SoundComponent::setSound(const sf::Sound& sound)
{
	m_sound = sound;
}


sf::Sound& SoundComponent::getSound()
{
	return m_sound;
}


void SoundComponent::update()
{
	float x = getGameObject()->getPosition().x;
	float y = getGameObject()->getPosition().y;
	float z = getGameObject()->getZIndex();
	m_sound.setPosition(x, y, z);
}
