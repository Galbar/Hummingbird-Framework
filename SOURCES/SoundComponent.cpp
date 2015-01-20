#include "SoundComponent.h"
using namespace hb;

void SoundComponent::setSound(const sf::Sound& sound)
{
	setData(sound);
}


sf::Sound& SoundComponent::getSound()
{
	return getData();
}


const sf::Sound& SoundComponent::getSound() const
{
	return getData();
}


void SoundComponent::update()
{
	float x = getPosition().x + getGameObject()->getPosition().x;
	float y = getPosition().y + getGameObject()->getPosition().y;
	float z = getZIndex() + getGameObject()->getZIndex();
	getData().setPosition(x, y, z);
}
