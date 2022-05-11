#include "stateman.hpp"

Engine::StateMan::StateMan()
{
}

Engine::StateMan::~StateMan()
{
}
void Engine::Add(std::unique_ptr<state> toAdd, bool replace = false)
{

}
void Engine::PopCurrent()
{

}
void Engine::ProcessStateChange()
{

}
std::unique_ptr<state>& GetCurrent()
{

}