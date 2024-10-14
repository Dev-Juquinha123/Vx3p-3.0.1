// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"

void AddMessageJumpQ(const char* text, unsigned int time, unsigned short flag, bool bPreviousBrief)
{
    ((void(__cdecl*)(const char*, unsigned int, unsigned short, bool))0x69F1E0)(text, time, flag, bPreviousBrief);
}

DWORD WINAPI InitializeAndLoad(LPVOID) {
    while (*reinterpret_cast<unsigned char*>(0xC8D4C0) != 9) {
        Sleep(100);
    }
    AddMessageJumpQ("Bot Minerador ~g~On", 1000, 0, false);
    return 0;
}

BOOL APIENTRY DllMain(HMODULE hModule,
    DWORD  ul_reason_for_call,
    LPVOID lpReserved
)
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        DisableThreadLibraryCalls(hModule);
        CreateThread(0, 0, &InitializeAndLoad, 0, 0, 0);
        break;

    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}
