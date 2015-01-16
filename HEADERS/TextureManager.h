#ifndef TEXTURE_MANAGER_H
#define TEXTURE_MANAGER_H value
#include <string>
#include <unordered_map>
#include <SFML/Graphics.hpp>
#include "hash_pair.h"


class TextureManager
{
public:
	// Constructor
	TextureManager();
	// Destructor
	~TextureManager();
	/* Load a Texture resource from file and return its id.
	   Returns -1 if error while loading texture. */
	int loadFromFile(const std::string& path, const sf::IntRect& area);
	// Release a Texture resource with identifier id
	void release(int id);
	// Release all Texture resources with identifier id
	void releaseAll(int id);
	// Get Texture with identifier id
	const sf::Texture& get(int id) const;
	// Returns wether the Texture resource with identifier id is loaded
	bool isLoaded(int id) const;
	// Returns wether the Texture resource with path path is loaded
	bool isLoaded(const std::string& path, const sf::IntRect& area) const;

private:
	typedef std::pair<int, int> pair_int;
	typedef std::pair<pair_int, pair_int> pair2_int;
	typedef std::pair<std::string, pair2_int> tex_id;

	struct TextureInfo
	{
		int id, count;
		std::unordered_map<tex_id, int>::iterator it;
		sf::Texture texture;
	};
	
	static tex_id makeTexId(const std::string& path, const sf::IntRect& area);
	int m_texture_count;
	std::unordered_map<tex_id, int> m_id_table;
	std::unordered_map<int, TextureInfo> m_info_table;
};
#endif
