#include "Tile.h"

Tile::Tile(string ImgPath, float leftOffSet, float rightOffSet, float topOffSet, float bottomOffSet, bool CanWalkOn)
{
	image = new CImage();
	image->SetImage(ImgPath);
	LeftBorderOffSet = leftOffSet;
	RightBorderOffSet = rightOffSet;
	TopBorderOffSet = topOffSet;
	BottomBorderOffSet = bottomOffSet;
	walkable = CanWalkOn;
}

Tile::~Tile()
{
	if (image)
	{
		delete image;
		image = nullptr;
	}
}

void Tile::SetTilePosition(int x, int y, int z)
{
	image->Transform.Location.Set(x, y, z);
	image->ZOrder = 0;

}

void Tile::SetBorders(float leftOffSet, float rightOffSet, float topOffSet, float bottomOffSet)
{
	LeftBorderOffSet = leftOffSet;
	RightBorderOffSet = rightOffSet;
	TopBorderOffSet = topOffSet;
	BottomBorderOffSet = bottomOffSet;
}

void Tile::SetTileLayerOrder(int z)
{
	image->ZOrder = z;
}

void Tile::SetWalkable(bool CanWalkOn)
{
	walkable = CanWalkOn;
}

CImage* Tile::GetImage()
{
	return image;
}

float Tile::GetLeftBorder()
{
	return LeftBorderOffSet;
}

float Tile::GetRightBorder()
{
	return RightBorderOffSet;
}

float Tile::GetTopBorder()
{
	return TopBorderOffSet;
}

float Tile::GetBottomBorder()
{
	return BottomBorderOffSet;
}

bool Tile::CanWalkOn()
{
	return walkable;
}
