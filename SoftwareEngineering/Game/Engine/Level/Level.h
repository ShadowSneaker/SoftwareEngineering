#pragma once
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include "../Graphics/Images/Image.h"
#include "../Graphics/Renderer/Renderer.h"
#include "Tile.h"

using namespace std;

#define ERROR_SINGLETON "ERROR!!! TWO OR MORE LEVEL INSTANCES!"
#define ERROR_FILE_NOT_FOUND "FILE DO NOT EXIST"
#define ERROR_TILE_NOT_FOUND "TILE WAS NOT FOUND! YOU TRY TO ACCESS SOMETHING THAT DOESN'T EXIST!!"

///To Be Added and Defined Tile Paths
///
//
#define TILE_GRASS "Content/Images/tile01.png"
#define TILE_DIRT "Content/Images/tile02.png"


#define FILE_OPEN_TEST(x) ((x)?true:false)
#define CHAR_CHECK(input, character) (input==character)



class Level
{
private:

	//Read File Stream Variable
	ifstream file;

	//Singleton
	static Level* Instance;

	//Tile to be drawn
	Tile* tile;

	//Vector of all tiles
	std::vector<std::vector <Tile*>> tiles;

	//Position to draw tile at
	SVectord tilePosition;


	///Create tile overload functions
	Tile* CreateTile(string ImgPath, float leftOffSet = 1, float rightOffSet = 1, float topOffSet = 1, float bottomOffSet = 1, bool CanWalkOn = true);
	Tile* CreateTile(string ImgPath, float leftOffSet = 1, float rightOffSet = 1, float topOffSet = 1, float bottomOffSet = 1);
	Tile* CreateTile(string ImgPath, float leftOffSet = 1, float rightOffSet = 1, float topOffSet = 1);
	Tile* CreateTile(string ImgPath, float leftOffSet = 1, float rightOffSet = 1);
	Tile* CreateTile(string ImgPath, float leftOffSet = 1);
	Tile* CreateTile(string ImgPath);


	//
	void SetUpTile(int row);

	void ReadTileInput(float InitialPosX,float ImageSizeY);


public:

	//Constructor
	Level(string fileNamePath, int StartingPosX, int StartingPosY, int SizeOfBiggestTileY);

	//Destructor
	~Level();


	//Add all tile images to Renderer 
	void AddTilesToRenderer(CRenderer* renderer);

	std::vector<std::vector <Tile*>> GetTilesVector();


	//Get Singleton Instance of the Level class
	static Level* getInstance();
};

