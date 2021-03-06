#pragma once

#include<SFML/Graphics/Texture.hpp>
#include<SFML/Graphics/Font.hpp>
#include<map>
#include<memory>
#include<string>
namespace Engine
{
	class assetman
	{
	private:
		std::map<int, std::unique_ptr<sf::Texture>> m_textures;
		std::map<int, std::unique_ptr<sf::Font>> m_fonts;
	public:
		assetman();
		~assetman();

		void AddTexture(int id,std::string& filePath,bool wantRepeated= false);
		void AddFont(int id, std::string& filePath);

		const sf::Texture& GetTexture(int id) const;
		const sf::Font& GetFont(int id) const;
	};


}

