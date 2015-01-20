#ifndef HB_SPRITE_COMPONENT_H
#define HB_SPRITE_COMPONENT_H
#include <SFML/Graphics.hpp>
#include "RenderWindowManager.h"
#include "DataComponent.h"
#include "Transform.h"

namespace hb
{
	class SpriteComponent : public DataComponent<sf::Sprite*>, public Transform
	{
	public:
		SpriteComponent(sf::Sprite* sprite, RenderWindowManager* render_manager);
		void setRenderWindowManager(RenderWindowManager* render_manager);
		RenderWindowManager* getRenderWindowManager();
		const RenderWindowManager* getRenderWindowManager() const;
		void setSprite(sf::Sprite* sprite);
		sf::Sprite* getSprite();
		const sf::Sprite* getSprite() const;
		bool isVisible() const;
		void setVisible(bool visible);
		void postUpdate() override;

	private:
		bool m_visible;
		RenderWindowManager* m_render_manager;
	};
}
#endif