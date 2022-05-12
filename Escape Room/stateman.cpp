#include "stateman.hpp"

Engine::StateMan::StateMan() : m_add(false), m_remove(false), m_repalce(false)
{
}

Engine::StateMan::~StateMan()
{
}
void Engine::StateMan::Add(std::unique_ptr<state> toAdd, bool replace)
{
}
void Engine::Add(std::unique_ptr<Engine::state> toAdd, bool replace = false)
{
	m_add = true;
	m_mnewState = std::move(toAdd);

	m_replace = replace;
}
void Engine::PopCurrent()
{
	m_remove
}
void Engine::ProcessStateChange()
{

}
std::unique_ptr<state>& GetCurrent()
{

}