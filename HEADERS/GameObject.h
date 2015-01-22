#ifndef HB_GAME_OBJECT_H
#define HB_GAME_OBJECT_H
#include <vector>
#include "Transform.h"

namespace hb
{
	class GameObject : public Transform
	{
	public:
		class Component
		{
		public:
			friend class GameObject;
			Component()
			{
				m_game_object = nullptr;
				m_relative = true;
			}
			virtual ~Component(){}
			virtual void preUpdate(){}
			virtual void update(){}
			virtual void postUpdate(){}
			GameObject* getGameObject() const {return m_game_object;}

		private:
			void setGameObject(GameObject* game_object)
			{m_game_object = game_object;}
			GameObject* m_game_object;
			bool m_relative;
		};

		GameObject();
		~GameObject();
		void update();
		void addComponent(Component* component);

	private:
		std::vector<Component*> m_components;
	};
}
#endif
