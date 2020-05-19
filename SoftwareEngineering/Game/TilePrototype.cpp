#include "TilePrototype.h"

bool TilePrototype::IsThisFirstColumn(int tilePosY)
{
	if (tilePosY == 0)
	{
		//printf("THIS IS FIRST COLUMN");
		return true;
	}

	return false;
}



TilePrototype::TilePrototype()
{
}

TilePrototype::~TilePrototype()
{
}

void TilePrototype::ReuseTileX(Level* level, int PositionX, int PositionY)
{
	std::vector<Tile*> TargetVector = level->GetTilesVector()[PositionX];
	if (!TargetVector.empty())
	{
		Tile* ShiftedTile;
		if (IsThisFirstColumn(PositionY))
		{
			ShiftedTile = TargetVector[0];

			ShiftedTile->SetTilePosition(ShiftedTile->GetTilePosition().GetX() -ShiftedTile->GetLeftBorder() - ShiftedTile->GetRightBorder()+(ShiftedTile->GetImage()->GetSize().GetX()) * TargetVector.size(), ShiftedTile->GetTilePosition().GetY(), 1);

			for (int j = 1; j < TargetVector.size(); j++)
			{
				TargetVector[j - 1] = TargetVector[j];
				if (j == TargetVector.size() - 1)
					TargetVector[j] = ShiftedTile;
			}

			printf("This is FIRST column, %dth row\n", PositionX);
		}
		else
		{
			ShiftedTile = TargetVector[TargetVector.size() - 1];

			ShiftedTile->SetTilePosition((int)ShiftedTile->GetTilePosition().GetX() + ShiftedTile->GetLeftBorder() + ShiftedTile->GetRightBorder() - (ShiftedTile->GetImage()->GetSize().GetX()) * TargetVector.size(), ShiftedTile->GetTilePosition().GetY(), 1);

			for (int j = TargetVector.size() - 1; j >= 0; j--)
			{
				TargetVector[j] = TargetVector[j - 1];
				if (j == 0)
					TargetVector[j] = ShiftedTile;

			}
			printf("This is LAST column, %dth row\n", PositionX);
		}
		level->GetTilesVector()[PositionX] = TargetVector;
	}
	else printf("Cannot reuse Tiles \n, ROW EMPT! \n %s", SDL_GetError());
}
