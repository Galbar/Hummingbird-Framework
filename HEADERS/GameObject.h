#ifndef HB_GAME_OBJECT_H
#define HB_GAME_OBJECT_H
#include <Box2D/Box2D.h>
#include <vector>
#include <memory>
#include "Transform.h"
#include "Vector2d.h"

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
			{m_game_object = nullptr;}
			virtual ~Component(){}
			virtual void update(){}

		private:
			void setGameObject(GameObject* game_object)
			{m_game_object = game_object;}
			GameObject* m_game_object;

		protected:
			GameObject* getGameObject() const
			{return m_game_object;}
		};

		GameObject();
		~GameObject();
		void update();
		Component* addComponent(const Component& component);

	private:
		std::vector<Component> m_components;
	};
}
#endif
