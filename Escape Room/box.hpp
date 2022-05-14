#pragma once

#include <SFML/Graphics.hpp>
#include <box2d/box2d.h>

struct Box
{
	float width;
	float height;
	sf::Color color;
	b2Body* body;
};

