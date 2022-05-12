#pragma once
#include<stack>
#include<memory>
#include<C:\Users\asing\Documents\Escape Room\Escape Room\state.hpp>

namespace Engine {
	class StateMan
	{
	private:
		std::stack < std::unique_ptr<state>> m_stateStack;
		std::unique_ptr<state> m_newState;

		bool m_add;
		bool m_repalce;
		bool m_remove;

	public:
		StateMan();
		~StateMan();

		void Add(std::unique_ptr<state> toAdd, bool replace = false);
		void PopCurrent();
		void ProcessStateChange();
		std::unique_ptr<state>& GetCurrent();
	};
	void Add(std::unique_ptr<Engine::state> toAdd, bool replace);
}
