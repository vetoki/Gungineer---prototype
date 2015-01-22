//SoundManager.h

#pragma once

class SoundManager
{
public:
	SoundManager();
	~SoundManager();
	void DestroySound(sf::Sound* sound);

	sf::Music* CreateMusic(std::string filename);
	sf::Sound* CreateSound(std::string filename);

private:
	std::vector<sf::Sound*> m_sounds;
	std::map<std::string, sf::SoundBuffer*> m_buffers;
};