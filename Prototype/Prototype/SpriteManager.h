//spriteManager.h

#pragma once

class SpriteManager
{
public:
	SpriteManager();
	~SpriteManager();

	sf::Sprite* CreateSprite(const std::string& filename, int x, int y, int w, int h);
	void DestroySprite(sf::Sprite* sprite);

private:
	std::vector<sf::Sprite*> m_sprites;
	std::map<std::string, sf::Texture*> m_textures;
};