#include "game.hpp"
#include "mainmenu.hpp"

#include<SFML/Graphics.hpp>

#include <memory>



game::game(): m_context(std::make_shared<Context>())
{
	m_context->m_window->create(sf::VideoMode(1280, 720), "Main Menu", sf::Style::Close);
	//TODO;
	//Add first state to m_states

	m_context->m_states->Add(std::make_unique<mainmenu>(m_context));
}

game::~game()
{
}

void game::Run()
{
	sf::CircleShape shape(100.0f);
	shape.setFillColor(sf::Color::Red);

	sf::Clock clock;
	sf::Time timesincelastframe = sf::Time::Zero;

	while (m_context->m_window->isOpen()) {

		timesincelastframe += clock.restart();

		while (timesincelastframe > TIME_PER_FRAME)
		{
			timesincelastframe -= TIME_PER_FRAME;

			//TODO;
			m_context->m_states->ProcessStateChange();
			m_context->m_states->GetCurrent()->ProcessInput();
			m_context->m_states->GetCurrent()->Update(TIME_PER_FRAME);
			m_context->m_states->GetCurrent()->Draw();

			//}

		}

		
		
	}
}