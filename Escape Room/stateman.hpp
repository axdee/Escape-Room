#pragma once
#include<stack>
#include<memory>
#include "state.hpp"

namespace Engine {
	class StateMan
	{
	private:
		std::stack < std::unique_ptr<state>> m_stateStack;
		std::unique_ptr<state> m_newState;

		bool m_add;
		bool m_replace;
		bool m_remove;

	public:
		StateMan();
		~StateMan();

		void Add(std::unique_ptr<state> toAdd, bool replace = false);
		void PopCurrent();
		void ProcessStateChange();
		std::unique_ptr<state>& GetCurrent();
	};
	
}
