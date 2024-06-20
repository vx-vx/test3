#include <iostream>

std::string xorEncryptDecrypt(char inpString[], std::string xorKey)
{
    // Define XOR key 
    // Any character value will work 

    std::string result;

    // calculate length of input string 
    int len = std::strlen(inpString);

    // perform XOR operation of key 
    // with every character in string 
    for (int i = 0; i < len; i++)
    {
        inpString[i] = inpString[i] ^ std::strlen(xorKey.c_str());
        result += inpString[i];
    }

    return result;
}