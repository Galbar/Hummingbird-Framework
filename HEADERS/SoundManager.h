#ifndef SOUND_MANAGER
#define SOUND_MANAGER
#include <string>
#include <SFML/Audio.hpp>
#include "ResourceManager.h"

class SoundManager : public ResourceManager<sf::SoundBuffer, std::string>
{
public:
	static SoundManager* instance();
	int loadFromFile(const std::string& path);

private:
	static SoundManager* s_instance;
};
#endif