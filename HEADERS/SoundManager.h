#ifndef SOUND_MANAGER
#define SOUND_MANAGER
#include <string>
#include <SFML/Audio.hpp>
#include "ResourceManager.h"

class SoundManager : public ResourceManager<sf::SoundBuffer, std::string>
{
public:
	static SoundManager* instance()
	{
		if (s_instance == NULL)
			s_instance = new SoundManager();

		return s_instance;
	}

	int loadFromFile(const std::string& path)
	{
		sf::SoundBuffer sb;
		if (!isLoaded(path))
			sb.loadFromFile(path);
	
		return this->addResource(path, sb);
	}

private:
	static SoundManager* s_instance;
};
SoundManager* SoundManager::s_instance = NULL;
#endif