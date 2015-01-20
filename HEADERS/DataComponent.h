#ifndef HB_DATA_COMPONENT_H
#define HB_DATA_COMPONENT_H
#include <SFML/Graphics.hpp>
#include "GameObject.h"

namespace hb
{
	template <typename T>
	class DataComponent : public GameObject::Component
	{
	public:
		void setData(const T& data)
		{m_data = data;}
		T& getData()
		{return m_data;}
		const T& getData() const
		{return m_data;}

	private:
		T m_data;
	};
}
#endif