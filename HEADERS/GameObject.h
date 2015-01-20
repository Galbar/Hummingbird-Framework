#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H
#include <Box2D/Box2D.h>
#include <vector>
#include <memory>
#include "Vector2d.h"

namespace hb
{
	class GameObject
	{
	public:
		class Component
		{
		public:
			friend class GameObject;
			Component(){}
			virtual ~Component(){}
			virtual void update(){}

		private:
			void setGameObject(GameObject* game_object)
			{m_game_object = game_object;}
			GameObject* m_game_object;

		protected:
			GameObject* getGameObject()
			{return m_game_object;}
		};

		GameObject();
		~GameObject();
		const Vector2d& getPosition() const;
		void setPosition(const Vector2d& p);
		double getZIndex() const;
		void setZIndex(double z_index);
		double getRotation() const;
		void setRotation(double angle);
		const Vector2d& getScale() const;
		void setScale(const Vector2d& scale);
		void update();
		Component* addComponent(const Component& component);

	private:
		Vector2d m_position;
		Vector2d m_scale;
		double m_z_index;
		double m_rotation_angle;
		std::vector<Component> m_components;
	};
}
#endif
