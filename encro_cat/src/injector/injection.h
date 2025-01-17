#pragma once

#include <Windows.h>
#include <iostream>
#include <string>
#include <fstream>
#include <TlHelp32.h>
#include <comdef.h>
#include <urlmon.h>
#include <filesystem>

#pragma comment(lib, "urlmon.lib")

using f_LoadLibraryA = HINSTANCE(WINAPI*)(const char* lpLibFilename);
using f_GetProcAddress = FARPROC(WINAPI*)(HMODULE hModule, LPCSTR lpProcName);
using f_DLL_ENTRY_POINT = BOOL(WINAPI*)(void* hDll, DWORD dwReason, void* pReserved);
using f_RtlAddFunctionTable = BOOL(WINAPIV*)(PRUNTIME_FUNCTION FunctionTable, DWORD EntryCount, DWORD64 BaseAddress);

struct MANUAL_MAPPING_DATA {
	f_LoadLibraryA pLoadLibraryA;
	f_GetProcAddress pGetProcAddress;
	f_RtlAddFunctionTable pRtlAddFunctionTable;
	BYTE* pbase;
	HINSTANCE hMod;
	DWORD fdwReasonParam;
	LPVOID reservedParam;
	BOOL SEHSupport;
};

struct MemoryStruct {
	char* memory;
	size_t size;
};

bool ManualMap(HANDLE hProc, std::filesystem::path DllPath);
int GetPIDByName(const char* ProcName);
HANDLE OpenProc(const char* ProcName);
void __stdcall Shellcode(MANUAL_MAPPING_DATA* pData);
void dump(std::string file, std::string url, std::string savepath);