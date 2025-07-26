#pragma once

#include "raylib.h"

class GraphicsProcessor {
private:

public:
	Color* RenderTile(unsigned char id, bool signedAddressing);
};