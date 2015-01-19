#ifndef TEXTURE_MANAGER_H
#define TEXTURE_MANAGER_H
#include <string>
#include <SFML/Graphics.hpp>
#include "hash_pair.h"
#include "ResourceManager.h"

namespace detail
{
	typedef std::pair<int, int> pair_int;
	typedef std::pair<pair_int, pair_int> pair2_int;
	typedef std::pair<std::string, pair2_int> tex_id;
}

class TextureManager : public ResourceManager<sf::Texture, detail::tex_id> 
{
public:
	static TextureManager* instance()
	{
		if (s_instance == NULL)
			s_instance = new TextureManager();

		return s_instance;
	}
	/* Load a Texture resource from file and return its id.
	   Returns -1 if error while loading texture. */
	int loadFromFile(const std::string& path, const sf::IntRect& area = sf::IntRect())
	{
		sf::Texture tex;
		if (!isLoaded(path, area))
			tex.loadFromFile(path, area);
	
		return this->addResource(makeTexId(path, area), tex);
	}
	bool isLoaded(const std::string& path, const sf::IntRect& area = sf::IntRect()) const
	{
		return ResourceManager<sf::Texture, detail::tex_id>::isLoaded(makeTexId(path, area));
	}

private:
	static detail::tex_id makeTexId(const std::string& path, const sf::IntRect& area)
	{
		detail::pair_int p1(area.left, area.top);
		detail::pair_int p2(area.width, area.height);
		detail::pair2_int p3(p1, p2);
		detail::tex_id id(path, p3);
		return id;
	}
	static TextureManager* s_instance;
};

TextureManager* TextureManager::s_instance = NULL;
#endif
