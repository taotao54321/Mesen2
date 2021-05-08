#pragma once
#include "stdafx.h"
#include "NES/NesPpu.h"

class NsfPpu final : public NesPpu<NsfPpu>
{
public:
	NsfPpu(NesConsole* console) : NesPpu(console)
	{
	}

	__forceinline void StoreSpriteAbsoluteAddress()
	{
	}

	__forceinline void StoreTileAbsoluteAddress()
	{
	}

	__forceinline void ProcessScanline()
	{
	}

	__forceinline void DrawPixel()
	{
	}

	__forceinline bool IsEmulatorBgEnabled()
	{
		return false;
	}

	__forceinline bool IsEmulatorSpritesEnabled()
	{
		return false;
	}

	void Run(uint64_t runTo) override
	{
		do {
			//Always need to run at least once, check condition at the end of the loop (slightly faster)
			if(_cycle < 340) {
				//Process cycles 1 to 340
				_cycle++;
			} else {
				//Process cycle 0
				ProcessScanlineFirstCycle();
			}
			_masterClock += _masterClockDivider;
		} while(_masterClock + _masterClockDivider <= runTo);
	}
};
