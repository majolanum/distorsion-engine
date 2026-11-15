#include "Utils.h"
#include <iostream>
#include <stdlib.h>
#include <string>

using namespace Utils;

static int Srand(int min, int max)
{
	int r = min + (rand() % (max - min + 1));
	return r;
}

static int AskInt(const char* msg, int min, int max)
{
	int value = 0;
	do {
		std::cout << msg << std::endl;
		std::cout << "->";
		std::cin >> value;
		std::cout << std::endl;
		if (value > max || value < min)
			std::cout << "mauvaise valeur entree, reessayer" << std::endl;
	} while (value > max || value < min);
	return value;
}

FileManager* FileManager::instance = nullptr;

FileManager* FileManager::Get()
{
	if (instance == nullptr)
		instance = new FileManager;
	return instance;
}

std::ifstream& FileManager::Open(std::string filePath)
{
	auto it = m_OpenFile.find(filePath);
	if (it != m_OpenFile.end())
		return it->second;
	else
	{
		std::ifstream file ;
		file.open(filePath);
		if (file.fail())
		{
			std::cerr << "Erreur lors de l'ouverture du fichier." << std::endl;
		}
		else
		{
			m_OpenFile.emplace(filePath, std::move(file));
			auto it = m_OpenFile.find(filePath);
			if (it != m_OpenFile.end())
				return it->second;
		}
	}
}

std::string FileManager::Read(int ligne, std::string filePath)
{
	std::string IngoredLigne;
	std::string SaveLigne;
	std::ifstream& File = Open(filePath);
	
	for (int i = 0; i < ligne; i++)
		std::getline(File, IngoredLigne);

	while (std::getline(File, SaveLigne))
		return SaveLigne;
}

void Utils::FileManager::Write(int lineNumber, std::string newText)
{

}
