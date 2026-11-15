#pragma once
#include <map>
#include <fstream>

namespace Utils
{
	static int Srand(int min, int max);
	
	static int AskInt(const char* msg, int min, int max);

	class FileManager
	{
	private:
		std::map <std::string, std::ifstream> m_OpenFile;

		std::ifstream& Open(std::string filePath);
		static FileManager* instance;

	public:
		static FileManager* Get();
		std::string Read(int lineNumber, std::string filePath);
		void Write(int lineNumber, std::string newText);
	};

};

