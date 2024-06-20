#define UNICODE
#include <windows.h>
#include <dshow.h>
#include <stdio.h>  // For file operations

#pragma comment(lib, "strmiids.lib")  // Link with strmiids.lib for DirectShow interfaces

namespace playbinarymp3
{
    const char* convertLPCWSTRToLPCSTR(const wchar_t* wideStr)
    {
        // Length of the wide string, excluding null terminator
        int len = WideCharToMultiByte(CP_UTF8, 0, wideStr, -1, nullptr, 0, nullptr, nullptr);

        // Allocate buffer for converted string
        char* buffer = new char[len];

        // Convert wide string to UTF-8 (or another encoding as needed)
        WideCharToMultiByte(CP_UTF8, 0, wideStr, -1, buffer, len, nullptr, nullptr);

        return buffer;
    }

    BOOL WriteMP3DataToTempFile(const unsigned char* data, int size, LPCWSTR tempFileName) {
        FILE* file;
        errno_t err = _wfopen_s(&file, tempFileName, L"wb");
        if (err != 0)
        {
            //printf("Error opening temporary file: %d\n", err);
            return FALSE;
        }

        size_t bytesWritten = fwrite(data, 1, size, file);
        fclose(file);

        if (bytesWritten != size)
        {
           // printf("Error writing to temporary file.\n");
            DeleteFile(convertLPCWSTRToLPCSTR(tempFileName));  // Clean up on failure
            return FALSE;
        }

        return TRUE;
    }

    void playBinaryMP3File(const unsigned char* mp3_data, int mp3_data_size)
    {
        // Initialize COM for DirectShow
        CoInitialize(NULL);

        // Path to the temporary file
        LPCWSTR tempFileName = L"x.mp3";

        // Write MP3 data to the temporary file
        if (!WriteMP3DataToTempFile(mp3_data, mp3_data_size, tempFileName))
        {
            //printf("Failed to write MP3 data to temporary file.\n");
            CoUninitialize();
            return;
        }

        // Create the filter graph manager
        IGraphBuilder* pGraph = NULL;
        IMediaControl* pControl = NULL;
        IMediaEvent* pEvent = NULL;

        HRESULT hr = CoCreateInstance(CLSID_FilterGraph, NULL, CLSCTX_INPROC_SERVER, IID_IGraphBuilder, (void**)&pGraph);
        if (FAILED(hr))
        {
            //printf("Error creating Filter Graph Manager.\n");
            DeleteFile(convertLPCWSTRToLPCSTR(tempFileName));
            CoUninitialize();
            return;
        }

        // Query interfaces to control playback
        pGraph->QueryInterface(IID_IMediaControl, (void**)&pControl);
        pGraph->QueryInterface(IID_IMediaEvent, (void**)&pEvent);

        // Render the file in the filter graph
        hr = pGraph->RenderFile(tempFileName, NULL);
        if (FAILED(hr))
        {
            //printf("Error rendering file: %x\n", hr);
            DeleteFile(convertLPCWSTRToLPCSTR(tempFileName));
            pGraph->Release();
            pControl->Release();
            pEvent->Release();
            CoUninitialize();
            return;
        }

        // Start playback
        hr = pControl->Run();
        if (FAILED(hr))
        {
            //printf("Error starting playback: %x\n", hr);
            DeleteFile(convertLPCWSTRToLPCSTR(tempFileName));
            pGraph->Release();
            pControl->Release();
            pEvent->Release();
            CoUninitialize();
            return;
        }

        // Wait for completion (optional)
        long evCode;
        pEvent->WaitForCompletion(INFINITE, &evCode);

        // Clean up
        DeleteFile(convertLPCWSTRToLPCSTR(tempFileName));  // Delete temporary file
        pGraph->Release();
        pControl->Release();
        pEvent->Release();
        CoUninitialize();

        return;
    }

}
