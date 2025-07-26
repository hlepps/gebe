#include "GraphicsProcessor.h"

#include "Offsets.h"
#include "Emulator.h"
#include "Useful.h"

Color* GraphicsProcessor::RenderTile(unsigned char id, bool signedAddressing)
{
	Color* tile = (Color*)malloc(8 * 8 * sizeof(Color));
	//bool bigObjects = GetBit(Emulator::GetInstance().GetMemoryManagerRef().memory[LCDC], LCDC_OBJ_SIZE);
	unsigned short address;
	if(!signedAddressing)
		address = MEMORY_VRAM_BEGIN + id * 0xF;
	else
		address = MEMORY_VRAM_BEGIN+0x1000 + (id-0x80) * 0xF;

	for (unsigned char i = 0; i < 0xF; i += 2)
	{
		unsigned short line = Emulator::GetInstance().GetMemoryManagerRef().memory[address+i];

	}
	return tile;
}