#pragma once

#include <string>
#include <windows.h>
#include <stdio.h>
#include <fstream>

class Files
{
public:
	void onSetup(const char* filepath);
	bool fileExists(std::string path);
	int	readInt(const char* element, const char* item);
	float readFloat(const char* element, const char* item);
	bool readBool(const char* element, const char* item);
	std::string readString(const char* element, const char* item);
	void writeInt(const char* element, const char* item, int value);
	void writeFloat(const char* element, const char* item, float value);
	void writeBool(const char* element, const char* item, bool value);
	void writeString(const char* element, const char* item, std::string value);
private:
	char m_fileName[1000];
};

extern Files* files;
