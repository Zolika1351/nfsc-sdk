#define _CRT_SECURE_NO_WARNINGS

#include <windows.h>
#include <stdint.h>
#include <string>
#include <list>
#include <d3dx9.h>
#include "injector/injector.hpp"

#include "CarbonSDK.h"
#include "Hooks.h"

namespace plugin
{
	uint32_t DoHook(uint32_t address, void(*Function)())
	{
		if (address)
		{
			uint32_t origcall = (uint32_t)injector::ReadRelativeOffset(address + 1);

			injector::MakeCALL(address, Function);

			return origcall;
		}
		return 0;
	}
	void InitHooks()
	{
		plugin::drawingEvent::callAddress = DoHook(0x7313DF, drawingEvent::MainHook);
		plugin::processSimSystemEvent::returnAddress = DoHook(0x7678A3, processSimSystemEvent::MainHook);
		plugin::processWorldEvent::returnAddress = DoHook(0x6B7B3A, processWorldEvent::MainHook);
		plugin::toggleSpeedbreakerEvent::returnAddress = DoHook(0x761CF9, toggleSpeedbreakerEvent::MainHook);
	}
	void Init()
	{
		InitHooks();
		gameStartupEvent();
	}
}

BOOL APIENTRY DllMain(HMODULE, DWORD ul_reason_for_call, LPVOID lpReserved)
{
	if (ul_reason_for_call == DLL_PROCESS_ATTACH) plugin::Init();
	return TRUE;
}