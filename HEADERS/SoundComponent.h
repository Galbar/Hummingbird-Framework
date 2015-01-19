#ifndef SOUND_COMPONENT
#define SOUND_COMPONENT
#include <SFML/Audio.hpp>
#include "GameObject.h"

namespace hb
{
	class SoundComponent : public GameObject::Component
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