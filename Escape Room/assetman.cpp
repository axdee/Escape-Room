#include "assetman.hpp"

Engine::assetman::assetman()
{
}

Engine::assetman::~assetman()
{
}


void Engine::assetman::AddTexture(int id, std::string& filePath, bool wantRepeated)
{
	auto texture = std::make_unique<sf::Texture>();

	if (texture->loadFromFile(filePath))
	{
		texture->setRepeated(wantRepeated);
		m_textures[id] = std::move(texture);
	}
}
void Engine::assetman::AddFont(int id, std::string& filePath)
{
	auto font = std::make_unique<sf::Font>();

	if (font->loadFromFile(filePath))
	{
		m_fonts[id] = std::move(font);
	}
}

const sf::Texture& Engine::assetman::GetTexture(int id) const
{
	return *(m_textures.at(id).get());
}
const sf::Font& Engine::assetman::GetFont(int id) const 
{
	return *(m_fonts.at(id).get());
}


