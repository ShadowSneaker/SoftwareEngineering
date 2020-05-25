#include "Level.h"

Level* Level::Instance = nullptr;

Tile* Level::CreateTile(string ImgPath, float leftOffSet, float rightOffSet, float topOffSet, float bottomOffSet, bool CanWalkOn)
{
	Tile* tile = new Tile(ImgPath, leftOffSet, rightOffSet, topOffSet, bottomOffSet, CanWalkOn);
	return tile;
}

Tile* Level::CreateTile(string ImgPath, float leftOffSet, float rightOffSet, float topOffSet, float bottomOffSet)
{
	Tile* tile = new Tile(ImgPath, leftOffSet, rightOffSet, topOffSet, bottomOffSet);
	return tile;
}

Tile* Level::CreateTile(string ImgPath, float leftOffSet, float rightOffSet, float topOffSet)
{
	Tile* tile = new Tile(ImgPath, leftOffSet, rightOffSet, topOffSet);
	return tile;
}

Tile* Level::CreateTile(string ImgPath, float leftOffSet, float rightOffSet)
{
	Tile* tile = new Tile(ImgPath, leftOffSet, rightOffSet);
	return tile;
}

Tile* Level::CreateTile(string ImgPath, float leftOffSet)
{
	Tile* tile = new Tile(ImgPath, leftOffSet);
	return tile;
}

Tile* Level::CreateTile(string ImgPath)
{
	Tile* tile = new Tile(ImgPath);
	return tile;
}

void Level::SetUpTile(int row)
{
	if (tile)
	{
		//Set Position of The Tile's Image
		//Tile X Pos - Tile Excess of Alpha Pixels + Tile Width, Tile Y Pos
		tile->GetImage()->Transform.Location.Set(tilePosition.GetX() - tile->GetLeftBorder() - tile->GetRightBorder(), tilePosition.GetY());

		//Set Layer Order of The Tile's Image
		tile->SetTileLayerOrder(0);

		//Add To The Total Tile Vector
		tiles[row-1].push_back(tile);
	}
	else printf(ERROR_TILE_NOT_FOUND "%s\n", SDL_GetError());

}

void Level::ReadTileInput(float InitialPosX, float ImageSizeY)
{

	//Reset Rows 
	int rows = 0;

	//File Line Variable
	string line;

	//Character from line
	char c;

	//Get a line out of the file
	while (getline(file, line))
	{
		//Increase The Rows Amount
		tiles.resize(tiles.size() + 1);

		//Add the line into a string stream
		istringstream stream(line);

		//Increase the row 
		rows++;

		//If Not First Tile
		//Reset Starting X Position
		if (tile)
			tilePosition.SetX(InitialPosX);

		//Get Character Out of Stream
		while (stream.get(c))
		{
			switch (c)
			{

				//Grass Tile Initialisation
			case '1':
				tile = new Tile(TILE_GRASS);

				tile->SetBorders(1);

				SetUpTile(rows);
				break;

			case '2':
				tile = new Tile(TILE_DIRT);

				//Set X Border
				tile->SetBorders(1);

				SetUpTile(rows);
				break;

				//Space Character Adds Tile Width To The X Tile Pos
			case ' ':
				if (tile)
					tilePosition.SetX(tilePosition.GetX() + tile->GetImage()->GetImageSize().GetX());
				break;

				//Hashtag Character Adds 1/2 Tile Width To The X Tile Pos
				//Shift the row by half of the width because of the isometric effect
			case '#':
				if (tile)
					tilePosition.SetX(tilePosition.GetX() + tile->GetImage()->GetImageSize().GetX() / 2);
				break;

			default:
				break;
			}
		}

		//Adds 1/3 Tile Height To The Y Pos At The End Of The Line
		//Because of the isometric effect it requires only a third of the biggest tile size (Assuming the tile pack had different dimensions for different tiles)
		if (tile)
			tilePosition.SetY(tile->GetImage()->Transform.Location.GetY() - tile->GetTopBorder() + ImageSizeY / 3);

	}

}

Level::Level(string fileNamePath, int StartingPosX, int StartingPosY, int SizeOfBiggestY)
{
	//Singleton Check
	if (Level::Instance == nullptr)
	{
		//Assign the first instance of the Level
		Instance = this;

		//Set the Starting Position
		tilePosition.SetX(StartingPosX);
		tilePosition.SetY(StartingPosY);

		float BiggestY = SizeOfBiggestY;

		//Open the file
		file.open(fileNamePath);


		// Check if the file openned correctly
		if (FILE_OPEN_TEST(file.is_open()) && FILE_OPEN_TEST(file.good()))
		{
			
			ReadTileInput(StartingPosX, SizeOfBiggestY);

			//Closes File
			file.close();
		}

		//Throws Error If File Was Not Openned Correctly
		else
			printf(ERROR_FILE_NOT_FOUND "%s\n", SDL_GetError());
	}

	//Throws Error If Class Has Been Instantiated Before
	else
		printf(ERROR_SINGLETON "%s\n", SDL_GetError());

}

Level::~Level()
{
	if (tiles.size() > 0)
	{
		for (auto i : tiles)
		{
			for (auto j : i)
			{
				delete j;
				j = nullptr;
			}
			i.clear();
		}
		tiles.clear();
	}

	if (tile)
	{
		delete tile;
		tile = nullptr;
	}

}

void Level::AddTilesToRenderer(CRenderer* renderer)
{
	for (int i = 0; i < tiles.size(); i++)
		for(int j=0;j<tiles[i].size();j++)
			renderer->AddImage(tiles[i][j]->GetImage());
}

std::vector<std::vector <Tile*>>& Level::GetTilesVector()
{
	return tiles;
}

Level* Level::getInstance()
{
	return Level::Instance;
}
