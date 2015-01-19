#include "ResourceManager.h"

template<typename R, typename RId, typename H>
ResourceManager<R, RId, H>::ResourceManager()
{
	m_resource_count = 0;
}


template<typename R, typename RId, typename H>
ResourceManager<R, RId, H>::~ResourceManager()
{}


template<typename R, typename RId, typename H>
int ResourceManager<R, RId, H>::addResource(const RId& resource_id, const R& resource)
{
	int ret = -1;
	if (isLoaded(resource_id))
	{
		ret = m_id_table.find(resource_id)->second;
		m_info_table.find(ret)->second.count++;
	}
	else
	{
		ret = m_resource_count++;
		ResourceInfo ti;
		ti.id = ret;
		ti.count = 1;
		ti.it = m_id_table.insert(std::pair<RId, int>(resource_id, ret)).first;
		ti.data = resource;
		m_info_table.insert(std::pair<int, ResourceInfo>(ret, ti));
	}
	assert(m_id_table.size() == m_info_table.size());
	return ret;
}


template<typename R, typename RId, typename H>
void ResourceManager<R, RId, H>::release(int id)
{
	ResourceInfo& ti = m_info_table.find(id)->second;
	if(--ti.count == 0)
	{
		m_id_table.erase(ti.it);
		m_info_table.erase(id);
	}
	assert(m_id_table.size() == m_info_table.size());
}


template<typename R, typename RId, typename H>
void ResourceManager<R, RId, H>::releaseAll(int id)
{
	ResourceInfo& ti = m_info_table.find(id)->second;
	m_id_table.erase(ti.it);
	m_info_table.erase(id);
	assert(m_id_table.size() == m_info_table.size());
}


template<typename R, typename RId, typename H>
const R& ResourceManager<R, RId, H>::get(int id) const
{
	return m_info_table.find(id)->second.texture;
}


template<typename R, typename RId, typename H>
bool ResourceManager<R, RId, H>::isLoaded(int id) const
{
	return (m_info_table.find(id) != m_info_table.end());
}


template<typename R, typename RId, typename H>
bool ResourceManager<R, RId, H>::isLoaded(const RId& resource_id) const
{
	return (m_id_table.find(resource_id) != m_id_table.end());
}

template<typename R, typename RId, typename H>
int ResourceManager<R, RId, H>::countResourceUsage(int id) const
{
	return m_info_table.find(id)->second.count;
}


template<typename R, typename RId, typename H>
int ResourceManager<R, RId, H>::size() const
{
	return m_id_table.size();
}


template<typename R, typename RId, typename H>
void ResourceManager<R, RId, H>::clear()
{
	m_resource_count = 0;
	m_id_table.clear();
	m_info_table.clear();
}
