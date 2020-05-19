#include "TilesObservator.h"

bool TilesObservator::TestCameraPositionInput()
{
	if (CameraLastPos->GetX() == NULL && CameraLastPos->GetY() == NULL)
	{
		return false;
		//printf("Previous Camera Input does not exist! %s\n", SDL_GetError());
	}

	return true;

}

bool TilesObservator::IsCameraInputNull(CCamera* camera)
{
	if (camera->GetCameraX() == NULL && camera->GetCameraY() == NULL)
		return true;

	//printf("Camera input is NOT NULL! %s\n", SDL_GetError());
	return false;
}

bool TilesObservator::HasCameraMoved(CCamera* camera)
{
	if (TestCameraPositionInput() && !IsCameraInputNull(camera))
	{
		if (camera->GetCameraX() != CameraLastPos->GetX() || camera->GetCameraY() != CameraLastPos->GetY())
			return true;

		//printf("Camera input is the same! %s\n", SDL_GetError());
	}
	return false;
}

bool TilesObservator::IsCameraMovingLeft(CCamera* camera, CRenderer* renderer)
{
	if (CameraLastPos->GetX() > camera->GetCameraX())
	{
		//printf("Camera is moving left!!!!!!!!!!!!!!!!!");
		return true;
	}
	return false;
}

std::vector<std::vector<Tile*>> TilesObservator::IsLevelMatrixLoaded(Level* level)
{
	if (LevelMatrix.size() <= 0)
	{
		printf("Maxtrix Level Has been loaded\n");
		LevelMatrix = level->GetTilesVector();
	}
	return LevelMatrix;
}

bool TilesObservator::AreAnyTilesOffScreen(Level* level, CRenderer* renderer, CCamera* camera, bool GoingLeft)
{
	if (!IsLevelMatrixLoaded(level).empty())
	{
		for (int i = 0; i < LevelMatrix.size(); i++)
		{
			if (GoingLeft)
			{
				SVector2 tilePos = LevelMatrix[i][LevelMatrix[i].size() - 1]->GetTilePosition();
				if (tilePos.GetX() > renderer->GetWindowSize().GetX() / 2 + camera->GetCameraX())
				{
					tilePrototype->ReuseTileX(level, i, LevelMatrix[i].size() - 1);
					UpdateLevelMatrix(level);
				}

			}
			else
			{
				SVector2 tilePos = LevelMatrix[i][0]->GetTilePosition();
				if (tilePos.GetX() < camera->GetCameraX() - renderer->GetWindowSize().GetX() / 2)
				{
					tilePrototype->ReuseTileX(level, i, 0);
					UpdateLevelMatrix(level);
				}
			}

		}
		//printf("Matrix is not empty\n");
		return false;
	}
}



TilesObservator::TilesObservator()
{
}

TilesObservator::TilesObservator(CCamera* camera)
{
	if (!IsCameraInputNull(camera))
		CameraLastPos = new SVector2d(camera->GetCameraX(), camera->GetCameraY());
	if (TestCameraPositionInput())
		printf("Camera Last Pos was not set! %s\n", SDL_GetError());
}

TilesObservator::~TilesObservator()
{
}

void TilesObservator::ObserveCameraPosition(Level* level, CCamera* camera, CRenderer* renderer)
{
	if (HasCameraMoved(camera))
	{
		AreAnyTilesOffScreen(level, renderer, camera, IsCameraMovingLeft(camera, renderer));
		CameraLastPos->SetX(camera->GetCameraX());
		CameraLastPos->SetY(camera->GetCameraY());
	}
}

void TilesObservator::UpdateLevelMatrix(Level* level)
{
	LevelMatrix = level->GetTilesVector();
}
