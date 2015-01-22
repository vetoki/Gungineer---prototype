//SpriteManager.h

#include "stdafx.h"
#include "SpriteManager.h"

SpriteManager::SpriteManager()
{

}

SpriteManager::~SpriteManager()
{

}

sf::Sprite* SpriteManager::CreateSprite(const std::string& filename, int x, int y, int w, int h)
{
	auto it = m_textures.find(filename);
	if (it == m_textures.end())
	{
		sf::Texture* texture = new sf::Texture();
		texture->loadFromFile(filename);

		m_textures.insert(std::pair<std::string, sf::Texture*>(filename, texture));
		it = m_textures.find(filename);
	}

	sf::Sprite* sprite = new sf::Sprite();
	sprite->setTexture(*it->second);
	
	sf::IntRect rect = sf::IntRect(x, y, w, h);
	sprite->setTextureRect(rect);
	
	return sprite;
}

void SpriteManager::DestroySprite(sf::Sprite* sprite)
{
	auto it = m_sprites.begin();
	while (it != m_sprites.end())
	{
		// if we find the right one 
		if ((*it) == sprite)
		{
			// we delete the sprite
			delete sprite;
			// and remove it from the vector
			m_sprites.erase(it);
			break;
		}
		++it;
	}
}
