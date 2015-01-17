#include "TextureManager.h"

TextureManager* TextureManager::s_instance = NULL;

TextureManager::TextureManager()
{
	m_texture_count = 0;
}


TextureManager::~TextureManager()
{}


TextureManager* TextureManager::instance()
{
	if (s_instance == NULL)
		s_instance = new TextureManager();

	return s_instance;
}


int TextureManager::loadFromFile(const std::string& path, const sf::IntRect& area)
{
	int ret = -1;
	if (isLoaded(path, area))
	{
		ret = m_id_table.find(makeTexId(path, area))->second;
		m_info_table.find(ret)->second.count++;
	}
	else
	{
		sf::Texture tex;
		if (tex.loadFromFile(path, area))
		{
			ret = m_texture_count++;
			TextureInfo ti;
			ti.id = ret;
			ti.count = 1;
			ti.it = m_id_table.insert(std::pair<tex_id, int>(makeTexId(path, area), ret)).first;
			ti.texture = tex;
			m_info_table.insert(std::pair<int, TextureInfo>(ret, ti));
		}
	}
	assert(m_id_table.size() == m_info_table.size());
	return ret;
}


void TextureManager::release(int id)
{
	TextureInfo& ti = m_info_table.find(id)->second;
	if(--ti.count == 0)
	{
		m_id_table.erase(ti.it);
		m_info_table.erase(id);
	}
	assert(m_id_table.size() == m_info_table.size());
}


void TextureManager::releaseAll(int id)
{
	TextureInfo& ti = m_info_table.find(id)->second;
	m_id_table.erase(ti.it);
	m_info_table.erase(id);
	assert(m_id_table.size() == m_info_table.size());
}


const sf::Texture& TextureManager::get(int id) const
{
	return m_info_table.find(id)->second.texture;
}


bool TextureManager::isLoaded(int id) const
{
	return (m_info_table.find(id) != m_info_table.end());
}


bool TextureManager::isLoaded(const std::string& path, const sf::IntRect& area) const
{
	return (m_id_table.find(makeTexId(path, area)) != m_id_table.end());
}


TextureManager::tex_id TextureManager::makeTexId(const std::string& path, const sf::IntRect& area)
{
	pair_int p1(area.left, area.top);
	pair_int p2(area.width, area.height);
	pair2_int p3(p1, p2);
	tex_id id(path, p3);
	return id;
}

int TextureManager::countResourceUsage(int id) const
{
	return m_info_table.find(id)->second.count;
}


int TextureManager::size() const
{
	return m_id_table.size();
}


void TextureManager::clear()
{
	m_texture_count = 0;
	m_id_table.clear();
	m_info_table.clear();
}
