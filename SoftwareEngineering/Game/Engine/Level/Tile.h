#pragma once
#include "TileBase.h"
using namespace std;

class Tile :TileBase
{
public:
	//Constructor
	Tile(string img, float leftOffSet = 1, float rightOffSet = 1, float topOffSet = 1, float bottomOffSet = 1, bool CanWalkOn = true);

	//Destructor
	~Tile();



	///Setters

	//Sets the image position of the tile
	void SetTilePosition(int x, int y, int z = 0) override;

	//Overwrite the border pixels
	void SetBorders(float leftOffSet = 1, float rightOffSet = 1, float topOffSet = 1, float bottomOffSet = 1) override;

	//Set the layer order
	void SetTileLayerOrder(int z) override;

	//Set tile ability to walk on
	void SetWalkable(bool CanWalkOn) override;



	///Getters

	//Get Image of the tile
	CImage* GetImage();

	//Get Borders Value
	float GetLeftBorder();
	float GetRightBorder();
	float GetTopBorder();
	float GetBottomBorder();

	SVector2 GetTilePosition();

	//Check if it is walkable
	bool CanWalkOn() override;
};

