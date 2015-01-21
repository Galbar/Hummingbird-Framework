#ifndef HB_EVENT_MANAGER_H
#define HB_EVENT_MANAGER_H
#include <functional>
#include <vector>

namespace hb
{
	namespace detail
	{
		template <typename Event>
		class EventManager
		{
		public:
			typedef std::function<void(const Event&)> Listener;
			void listen(Listener&& listener)
			{
				m_listeners.push_back(std::move(listener));
			}

			void message(const Event& event)
			{
				for (const auto& listener : m_listeners)
					listener(event);
			}

		private:
			std::vector<Listener> m_listeners;
		};

		template <typename T>
		struct traits : public traits<decltype(&T::operator())> {};

		template <typename C, typename R, typename A>
		struct traits<R(C::*)(const A&) const>
		{
			typedef A type;
		};
	}

	template <typename... Events>
	class EventManager : detail::EventManager<Events>...
	{
	public:
		template <typename Listener>
		void listen(Listener&& listener)
		{
			typedef typename detail::traits<Listener>::type Event;
			detail::EventManager<Event>& em = *this;
			em.listen(std::move(listener));
		}

		template <typename Event>
		void message(const Event& event)
		{
			detail::EventManager<Event>& em = *this;
			em.message(event);
		}
	};
}
#endif