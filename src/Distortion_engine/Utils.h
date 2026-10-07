#pragma once
#include <fstream>
#include <map>
#include <string>

namespace Utils
{
	int Srand(int min, int max);
	
	int AskInt(const char* msg, int min, int max);	


	class FileManager
	{
	private:
		std::map <std::string, std::ifstream> m_OpenFile;
		std::ifstream& Open(std::string filePath);

	public:
		std::string Read(int lineNumber, std::string filePath);
	};

};

