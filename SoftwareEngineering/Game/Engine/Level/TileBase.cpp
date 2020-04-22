#include "TileBase.h"

TileBase::TileBase()
{
}

TileBase::~TileBase()
{
}

void TileBase::SetTilePosition(int x, int y, int z)
{
}

void TileBase::SetBorders(float leftOffSet, float rightOffSet, float topOffSet, float bottomOffSet)
{
}

void TileBase::SetTileLayerOrder(int z)
{
}

void TileBase::SetWalkable(bool CanWalkOn)
{
}

CImage* TileBase::GetImage()
{
	return nullptr;
}

float TileBase::GetLeftBorder()
{
	return 0.0f;
}

float TileBase::GetRightBorder()
{
	return 0.0f;
}

float TileBase::GetTopBorder()
{
	return 0.0f;
}

float TileBase::GetBottomBorder()
{
	return 0.0f;
}
