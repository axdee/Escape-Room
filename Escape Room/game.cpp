#include "game.hpp"
#include<SFML/Graphics.hpp>



game::game(): m_context(std::make_shared<Context>())
{
	m_context->m_window->create(sf::VideoMode(1280, 720), "Main Menu", sf::Style::Close);
	//TODO;
	//Add first state to m_states


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
			//m_context->m_states->ProcessStateChange();
			//m_context->m_states->GetCurrent()->ProcessInput();
			//m_context->m_states->GetCurrent()->Update(TIME_PER_FRAME);
			//m_context->m_states->GetCurrent()->Draw();

			sf::Event evnt;
			while (m_context->m_window->pollEvent(evnt))
			{
				if (evnt.type == sf::Event::Closed) {
					m_context->m_window->close();
				}
			}
			m_context->m_window->clear();
			m_context->m_window->draw(shape);
			m_context->m_window->display();
		}

		
		
	}
}