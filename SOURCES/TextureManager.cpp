#include "TextureManager.h"
using namespace hb;

TextureManager* TextureManager::s_instance = NULL;

TextureManager* TextureManager::instance()
{
	if (s_instance == NULL)
		s_instance = new TextureManager();

	return s_instance;
}


/* Load a Texture resource from file and return its id.
   Returns -1 if error while loading texture. */
int TextureManager::loadFromFile(const std::string& path, const sf::IntRect& area)
{
	sf::Texture tex;
	if (!isLoaded(path, area))
		tex.loadFromFile(path, area);

	return this->addResource(makeTexId(path, area), tex);
}


bool TextureManager::isLoaded(const std::string& path, const sf::IntRect& area) const
{
	return ResourceManager<sf::Texture, detail::tex_id>::isLoaded(makeTexId(path, area));
}


detail::tex_id TextureManager::makeTexId(const std::string& path, const sf::IntRect& area)
{
	detail::pair_int p1(area.left, area.top);
	detail::pair_int p2(area.width, area.height);
	detail::pair2_int p3(p1, p2);
	detail::tex_id id(path, p3);
	return id;
}
