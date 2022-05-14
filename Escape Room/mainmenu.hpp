#pragma once

#include <memory>

#include <SFML/Graphics.hpp>

#include "state.hpp"
#include "game.hpp"
#include "box.hpp"


class mainmenu: public Engine::state
{
private:
	
	std::shared_ptr<Context>m_context;
	sf::Text m_gameTitle;

public:
	std::vector<Box> boxes;
	mainmenu(std::shared_ptr<Context> &context);
	~mainmenu();
	
	Box createBox(float x, float y, float width, float height, float density, float friction, sf::Color color);
	Box createGround(float x, float y, float width, float height, sf::Color color);
	void render(sf::RenderWindow& w, std::vector<Box>& boxes) ;
	void Init() override;
	void ProcessInput() override;
	void Update(sf::Time deltatime) override;
	void Draw() override;

};

