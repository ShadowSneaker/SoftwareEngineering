#pragma once
#include "../Graphics/Images/Image.h"
#include "../Graphics/Renderer/Renderer.h"
#include <string>

class  TileBase
{
protected:
	//Tile Image
	CImage* image;

	//Extra Alpha Pixels on Left Border
	//Detailed - Tiles do not glue to each other due to excess of alpha pixels 
	float LeftBorderOffSet;

	//Extra Alpha Pixels on Right Border
	//Detailed - Tiles do not glue to each other due to excess of alpha pixels 
	float RightBorderOffSet;

	//Extra Alpha Pixels on Top Border
	//Detailed - Tiles do not glue to each other due to excess of alpha pixels 
	float TopBorderOffSet;

	//Extra Alpha Pixels on Bottom Border
	//Detailed - Tiles do not glue to each other due to excess of alpha pixels 
	float BottomBorderOffSet;

	//Can walk on the tile?
	bool walkable;

public:
	//Constructor
	TileBase();

	//Destructor
	~TileBase();



	///Setters

	//Sets the image position of the tile
	virtual void SetTilePosition(int x, int y, int z = 0)=0;

	//Overwrite the border pixels
	virtual void SetBorders(float leftOffSet = 1, float rightOffSet = 1, float topOffSet = 1, float bottomOffSet = 1)=0;

	//Set the layer order
	virtual void SetTileLayerOrder(int z)=0;

	//Set tile ability to walk on
	virtual void SetWalkable(bool CanWalkOn)=0;


	//Check if it is walkable
	virtual bool CanWalkOn()=0;



};

