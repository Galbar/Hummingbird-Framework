#ifndef SOUND_COMPONENT_H
#define SOUND_COMPONENT_H
#include <SFML/Audio.hpp>
#include "DataComponent.h"
#include "Transform.h"

namespace hb
{
	class SoundComponent : public DataComponent<sf::Sound>, public Transform
	{
	public:
		void setSound(const sf::Sound& sound);
		sf::Sound& getSound();
		const sf::Sound& getSound() const;
		void update();
	};
}
#endif