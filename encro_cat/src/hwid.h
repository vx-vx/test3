#pragma once
#include <iostream>
#include <intrin.h>
#include <string>
#include <windows.h>
#include <iphlpapi.h>

#pragma comment(lib, "IPHLPAPI.lib")


namespace hwid
{

#define A 54059
#define B 76963
#define C 86969

#define FIRSTH 37

    unsigned hash_str(const char* s)
    {
        unsigned h = FIRSTH;
        while (*s)
        {
            h = (h * A) ^ (s[0] * B);
            s++;
        }
        return h;
    }

    std::string getMAC(void)
    {
        ULONG BufferLength = 0;
        BYTE* pBuffer = 0;
        static int networkAdapters{ 0 };
        std::string mac;

        if (ERROR_BUFFER_OVERFLOW == GetAdaptersInfo(0, &BufferLength))
        {
            pBuffer = new BYTE[BufferLength];
        }

        PIP_ADAPTER_INFO pAdapterInfo = reinterpret_cast<PIP_ADAPTER_INFO>(pBuffer);
        GetAdaptersInfo(pAdapterInfo, &BufferLength);


        while (pAdapterInfo)
        {
            std::string mac_tmp = std::to_string(pAdapterInfo->Address[0]) + std::to_string(pAdapterInfo->Address[1]) + std::to_string(pAdapterInfo->Address[2]) + std::to_string(pAdapterInfo->Address[3]) + std::to_string(pAdapterInfo->Address[4]) + std::to_string(pAdapterInfo->Address[5]);

            mac = mac + mac_tmp;

            pAdapterInfo = pAdapterInfo->Next;
        }

        delete[] pBuffer;
        return mac;

    }

    std::string getCPUID()
    {
        static char buf[1000];

        int reg1[4];
        int reg2[4];
        int reg3[4];

        __cpuid(reg1, 0);


        int len = snprintf(buf, sizeof(buf), "%08lX", reg1[1]);

        if (len >= sizeof(buf)) {
            buf[sizeof(buf) - 1] = '\0';
        }

        return std::string(buf);
    }

    std::string getVolume()
    {
        DWORD hwid_VolumeSerialNumber = 0;
        GetVolumeInformationA(LPCSTR("c:\\"), NULL, NULL, &hwid_VolumeSerialNumber, NULL, NULL, NULL, NULL);
        return std::to_string(hwid_VolumeSerialNumber);
    }

    std::string getHWID()
    {
        std::string hwid;

        std::string hwid_volume = std::to_string(hash_str(getVolume().c_str()));
        std::string hwid_CPUID = std::to_string(hash_str(getCPUID().c_str()));
        std::string hwid_mac = std::to_string(hash_str(getMAC().c_str()));


        hwid = hwid_CPUID + hwid_volume + hwid_mac;

        return hwid;
    }
}