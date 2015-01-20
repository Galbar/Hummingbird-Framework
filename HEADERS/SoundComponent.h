#ifndef SOUND_COMPONENT_H
#define SOUND_COMPONENT_H
#include <SFML/Audio.hpp>
#include "GameObject.h"
#include "Transform.h"

namespace hb
{
	class SoundComponent : public GameObject::Component, public Transform
	{
	public:
		SoundComponent();
		~SoundComponent();
		void setSound(const sf::Sound& sound);
		sf::Sound& getSound();
		void update();

	private:
		sf::Sound m_sound;
	};
}
#endif