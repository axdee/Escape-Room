#pragma once

#include<memory>


#include"assetman.hpp"
#include"stateman.hpp"
#include<SFML/Graphics/RenderWindow.hpp>

struct Context
{
	std::unique_ptr<Engine::assetman> m_assets;
	std::unique_ptr<Engine::StateMan> m_states;
	std::unique_ptr<sf::RenderWindow> m_window;
	
	Context()
	{
		m_assets = std::make_unique<Engine::assetman>();
		m_states = std::make_unique<Engine::StateMan>();
		m_window = std::make_unique<sf::RenderWindow>();
	}
};

class game
{
private:
	std::shared_ptr<Context> m_context;
	const sf::Time TIME_PER_FRAME= sf::seconds(1.f / 60.f);
public:
	game();
	~game();
	void Run();
};

