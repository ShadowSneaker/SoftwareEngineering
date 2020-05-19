#pragma once
#include "Engine/Level/Level.h"

class TilePrototype
{
private:
	//tests
	bool IsThisFirstColumn(int tilePosY);
	void PrintMatrixTest();
public:
	TilePrototype();
	~TilePrototype();

	void ReuseTileX(Level* level, int PositionX, int PositionY);
};

