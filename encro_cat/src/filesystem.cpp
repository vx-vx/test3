#include "filesystem.h"

Files* files = new Files();

void Files::onSetup(const char* filepath)
{
	char buffer[MAX_PATH];
	GetModuleFileNameA(NULL, buffer, MAX_PATH);

	memset(m_fileName, 0x00, 255);
	strcpy_s(m_fileName, std::string(buffer).substr(0, std::string(buffer).find_last_of("\\/") + 1).c_str());
	strcat_s(m_fileName, filepath);
}

int Files::readInt(const char* element, const char* item)
{
	return GetPrivateProfileIntA(element, item, NULL, m_fileName);
}

float Files::readFloat(const char* element, const char* item)
{
	char result[255];
	GetPrivateProfileStringA(element, item, NULL, result, 255, m_fileName);
	return atof(result);
}

std::string Files::readString(const char* element, const char* item)
{
	char buffer[255];
	int result = GetPrivateProfileString(element, item, NULL, buffer, 255, m_fileName);
	DWORD dwPreferredPLID = std::strtoul(std::string(buffer, result).c_str(), NULL, 16);
	return std::string(buffer, result);;
}

bool Files::readBool(const char* element, const char* item)
{
	char result[255];
	GetPrivateProfileStringA(element, item, NULL, result, 255, m_fileName);
	return (strcmp(result, "True") == 0 || strcmp(result, "true") == 0) ? true : false;
}

void Files::writeInt(const char* element, const char* item, int value)
{
	char temp[255];
	sprintf_s(temp, "%d", value);
	WritePrivateProfileStringA(element, item, temp, m_fileName);
}

void Files::writeFloat(const char* element, const char* item, float value)
{
	char temp[255];
	sprintf_s(temp, "%f", value);
	WritePrivateProfileStringA(element, item, temp, m_fileName);
}

void Files::writeBool(const char* element, const char* item, bool value)
{
	char temp[255];
	sprintf_s(temp, "%s", value ? "true" : "false");
	WritePrivateProfileStringA(element, item, temp, m_fileName);
}
void Files::writeString(const char* element, const char* item, std::string value)
{
	char temp[255];
	sprintf_s(temp, value.c_str());
	WritePrivateProfileStringA(element, item, temp, m_fileName);
}


bool Files::fileExists(std::string path)
{
	std::ifstream file(path);
	if (!file.is_open())
	{
		return false;
	}
	return true;
}