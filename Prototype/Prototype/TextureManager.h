// TextureManager

#pragma once

class TextureManager
{
public:
	TextureManager();
	~TextureManager();

	sf::Texture* CreateTexture(std::string filename);
	void Shutdown();

private:
	std::map<std::string, sf::Texture*> m_textures;
};