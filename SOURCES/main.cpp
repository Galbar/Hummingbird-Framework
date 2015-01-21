#include <iostream>
#include <SFML/Graphics.hpp>
#include "Vector2d.h"
#include "TextureManager.h"
#include "RenderWindowManager.h"
#include "GameObject.h"
#include "SpriteComponent.h"
#include "FunctionComponent.h"
#include "EventManager.h"

void hello(const sf::Event::KeyEvent)
{
	std::cout << "world" << std::endl;
}


class InputMove : public hb::GameObject::Component
{
public:
	std::function<void(const sf::Event::KeyEvent&)> handleEvent;
};

int main(int argc, char const *argv[])
{
	hb::EventManager<sf::Event::MouseButtonEvent, sf::Event::KeyEvent> event_manager;
	event_manager.listen(std::function<void(const sf::Event::KeyEvent&)>(hello));
	hb::RenderWindowManager window_manager1(new sf::RenderWindow(sf::VideoMode(600, 600), "SFML works!1"));
	
	hb::TextureManager* tm = hb::TextureManager::instance();
	int tex1 = tm->loadFromFile("DATA/tex1.jpeg", sf::IntRect(10, 10, 64, 64));
	int tex2 = tm->loadFromFile("DATA/tex1.jpeg", sf::IntRect(45, 45, 64, 64));

	hb::GameObject go1;
	go1.addComponent(new hb::SpriteComponent(new sf::Sprite(tm->get(tex1)), &window_manager1));
	hb::FunctionComponent* move = new hb::FunctionComponent();
	move->setUpdateFunction([&] (hb::GameObject* go)
	{
		if (go->getPosition().x > 600)
			go->setPosition(hb::Vector2d(0, go->getPosition().y));

		if (go->getPosition().y > 600)
			go->setPosition(hb::Vector2d(go->getPosition().x, 0));

		go->setPosition(hb::Vector2d(go->getPosition().x+0.5, go->getPosition().y+0.5));
		go->setRotation(go->getRotation()+0.5);
	});
	go1.addComponent(move);

	hb::GameObject go2;
	event_manager.listen([&] (const sf::Event::KeyEvent& ev)
	{
		if (ev.code == sf::Keyboard::Key::Up)
			go2.setPosition(go2.getPosition() + hb::Vector2d(0,-1));
		if (ev.code == sf::Keyboard::Key::Down)
			go2.setPosition(go2.getPosition() + hb::Vector2d(0,1));
		if (ev.code == sf::Keyboard::Key::Right)
			go2.setPosition(go2.getPosition() + hb::Vector2d(1,0));
		if (ev.code == sf::Keyboard::Key::Left)
			go2.setPosition(go2.getPosition() + hb::Vector2d(-1,0));
	});
	go2.addComponent(new hb::SpriteComponent(new sf::Sprite(tm->get(tex2)), &window_manager1));
	go2.setPosition(hb::Vector2d(60, 60));
	go2.setZIndex(1);

	while (window_manager1.getWindow()->isOpen())
	{
		sf::Event event;
		while (window_manager1.getWindow()->pollEvent(event))
		{
			switch(event.type)
			{
				case sf::Event::Closed:
					window_manager1.getWindow()->close();
					break;
				case sf::Event::MouseButtonPressed:
					event_manager.message(event.mouseButton);
					break;
				case sf::Event::KeyPressed:
					event_manager.message(event.key);
					break;
			}

		}
		go1.update();
		go2.update();
		window_manager1.draw();
	}
	return 0;
}
