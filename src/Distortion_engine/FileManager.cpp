#include "FileManager.h"
#include <iostream>

std::ifstream& FileManager::Open(std::string filePath)
{
	auto it = m_OpenFile.find(filePath);
	if (it != m_OpenFile.end())
		return it->second;
	else
	{
		std::ifstream file(filePath);
		if (!file)
		{
			std::cerr << "Erreur lors de l'ouverture du fichier." << std::endl;
		}
		else
		{
			m_OpenFile.emplace(filePath, std::move(file));
			return file;
		}
	}
}

std::string FileManager::Read(int ligne, std::string filePath)
{
	std::string IngoredLigne;
	std::string SaveLigne;
	std::ifstream* File = &Open(filePath);

	for (int i = 0; i < ligne; i++)
		std::getline(*File, IngoredLigne);

	while (std::getline(*File, SaveLigne))
		return SaveLigne;
}