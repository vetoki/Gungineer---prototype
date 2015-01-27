// TextureManager

#include "stdafx.h"
#include "TextureManager.h"

TextureManager::TextureManager()
{

}

TextureManager::~TextureManager()
{

}

void TextureManager::Shutdown()
{

}

sf::Texture* TextureManager::CreateTexture(std::string filename)
{
	sf::Texture* texture;
	auto it = m_textures.find(filename);
	if (it == m_textures.end())
	{
		texture = new sf::Texture();
		texture->loadFromFile(filename);

		m_textures.insert(std::pair<std::string, sf::Texture*>(filename, texture));
		it = m_textures.find(filename);
	}

	texture = it->second;

	return texture;
}

