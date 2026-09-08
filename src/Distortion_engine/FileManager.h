#pragma once
#include <fstream>
#include <map>
#include <string>

class FileManager
{
private:
	std::map <std::string, std::ifstream> m_OpenFile;

	std::ifstream& Open(std::string filePath);
	std::string Read(int lineNumber, std::string filePath);

};

