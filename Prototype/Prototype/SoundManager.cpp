//SoundManager.cpp

#include "stdafx.h"
#include "SoundManager.h"

SoundManager::SoundManager()
{

}

SoundManager::~SoundManager()
{
	for (int i = m_sounds.size(); i > 0; i--)
	{
		if (m_sounds[i - 1])
		{
			delete m_sounds[i - 1];
		}
	}
	m_sounds.clear();
}

void SoundManager::DestroySound(sf::Sound* sound)
{
	auto it = m_sounds.begin();
	while (it != m_sounds.end())
	{
		if ((*it) == sound)
		{
			delete sound;
			m_sounds.erase(it);
			break;
		}
		++it;
	}
}

sf::Music* SoundManager::CreateMusic(std::string filename)
{
	sf::Music* music = new sf::Music();
	music->openFromFile(filename);
	music->setLoop(true);

	return music;
}

sf::Sound* SoundManager::CreateSound(std::string filename)
{
	auto it = m_buffers.find(filename);
	if (it == m_buffers.end())
	{
		sf::SoundBuffer* buffer = new sf::SoundBuffer();
		buffer->loadFromFile(filename);

		m_buffers.insert(std::pair<std::string, sf::SoundBuffer*>(filename, buffer));
		it = m_buffers.find(filename);
	}

	sf::Sound* sound = new sf::Sound();
	sound->setBuffer(*it->second);
	m_sounds.push_back(sound);
	
	return sound;
}