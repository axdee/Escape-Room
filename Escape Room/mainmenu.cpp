#include "mainmenu.hpp"
#include<memory>
#include <box2d/box2d.h>
#include<SFML/Graphics.hpp>
#include<iostream>
#include"asset.h"

// Box2D world for physics simulation, gravity = 9 m/s^2
b2World world(b2Vec2(0, -9));

mainmenu::mainmenu(std::shared_ptr<Context>& context)
	:m_context(context)
{
}

mainmenu::~mainmenu()
{
}

Box mainmenu::createBox(float x, float y, float width, float height, float density, float friction, sf::Color color)
{
	b2BodyDef boxBodyDef;
	boxBodyDef.position.Set(x / PPM, y / PPM);
	boxBodyDef.type = b2_dynamicBody;

	// Shape definition
	b2PolygonShape boxShape;
	boxShape.SetAsBox(width / 2 / PPM, height / 2 / PPM);

	// Fixture definition
	b2FixtureDef fixtureDef;
	fixtureDef.density = density;
	fixtureDef.friction = friction;
	fixtureDef.shape = &boxShape;

	b2Body* boxBody = world.CreateBody(&boxBodyDef);
	
	boxBody->CreateFixture(&fixtureDef);

	return Box{ width, height, color, boxBody };
}

Box mainmenu::createGround(float x, float y, float width, float height, sf::Color color)
{
	b2BodyDef groundBodyDef;
	groundBodyDef.position.Set(x / PPM, y / PPM);

	
	b2PolygonShape groundBox;
	groundBox.SetAsBox(width / 2 / PPM, height / 2 / PPM);

	
	b2Body* groundBody = world.CreateBody(&groundBodyDef);
	
	groundBody->CreateFixture(&groundBox, 0.0f);

	return Box{ width, height, color, groundBody };
}

void mainmenu::render(sf::RenderWindow& w, std::vector<Box>& boxes)
{
	sf::Text text;

	text.setFont(font);

	text.setString("Tap to Start");

	text.setCharacterSize(50);

	text.setFillColor(sf::Color::Blue);

	text.setPosition(265.f, 100.f);
	w.clear();
	for (const auto& box : boxes)
	{
		sf::RectangleShape rect;

		rect.setPosition(box.body->GetPosition().x * PPM, WINDOW_HEIGHT - (box.body->GetPosition().y * PPM));


		rect.setOrigin(box.width / 2, box.height / 2);

		rect.setSize(sf::Vector2f(box.width, box.height));

		
		rect.setRotation(-1 * box.body->GetAngle() * DEG_PER_RAD);

		rect.setFillColor(box.color);
		w.draw(rect);
	}
	w.draw(text);
	w.display();
}


void mainmenu::Init()
{
	font.loadFromFile("shortbaby.ttf");

	boxes.push_back(createGround(300, 20, 1000, 100, sf::Color::Magenta));
	
	for (int i = 0; i < 250; i++)
	{
		
		auto box = createBox(static_cast<float>(150 + (std::rand() % (550 - 50 + 1))),
												 static_cast<float>(70 + (std::rand() % (550 - 70 + 1))), 15, 15, 1.f, 0.4f, sf::Color::Red);
		boxes.push_back(box);
	}
}
void mainmenu::ProcessInput()

{

	sf::Event evnt;

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{

		float localPositionx = static_cast<float>(sf::Mouse::getPosition().x);
		float localPositiony = static_cast<float>(sf::Mouse::getPosition().y);

		auto&& box = createBox(localPositionx, WINDOW_HEIGHT - localPositiony, 15.f, 15.f, 1.f, 0.7f, sf::Color::Red);
		boxes.push_back(box);

	}


	while (m_context->m_window->pollEvent(evnt))
	{
		switch (evnt.type) {
		case sf::Event::Closed:
			m_context->m_window->close();
		case sf::Event::TextEntered:
			if (evnt.text.unicode < 128) {
				printf("%c", evnt.text.unicode);
			}

		}

	}
}
void mainmenu::Update(sf::Time deltatime)
{

}

void mainmenu::Draw()
{
	render(*m_context->m_window, boxes);
}