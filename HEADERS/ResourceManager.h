#ifndef RESOURCE_MANAGER_H
#define RESOURCE_MANAGER_H
#include <unordered_map>
#include <cassert>


template <typename Resource, typename ResourceId, typename Hash = std::hash<ResourceId>>
class ResourceManager
{
public:
	// Constructor
	ResourceManager();
	// Destructor
	~ResourceManager();
	// Add Resource to manager
	int addResource(const ResourceId& resource_id, const Resource& resource);
	// Release a Resource resource with identifier id
	void release(int id);
	// Release all Resource resources with identifier id
	void releaseAll(int id);
	// Get Resource with identifier id
	const Resource& get(int id) const;
	// Returns wether the Resource resource with identifier id is loaded
	bool isLoaded(int id) const;
	// Returns wether the Resource resource with path path is loaded
	bool isLoaded(const ResourceId& resource_id) const;
	// Returns number of active requests for resource id
	int countResourceUsage(int id) const;
	// Returns total number of resources loaded
	int size() const;
	// Release all resources
	void clear();

private:
	struct ResourceInfo
	{
		int id, count;
		typename std::unordered_map<ResourceId, int, Hash>::iterator it;
		Resource data;
	};

	int m_resource_count;
	std::unordered_map<ResourceId, int, Hash> m_id_table;
	std::unordered_map<int, ResourceInfo> m_info_table;
};
#endif
