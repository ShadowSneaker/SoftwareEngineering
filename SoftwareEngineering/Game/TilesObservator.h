#pragma once
#include "Engine/System/Camera.h"
#include "../Libraries/CopiriteMath/CopiriteMath/Datatypes/Vector.h"
#include "Engine/Graphics/Renderer/Renderer.h"
#include "Engine/Level/Level.h"
#include "TilePrototype.h"
class TilesObservator
{
private:
	SVector2d* CameraLastPos;
	bool CameraGoingLeft;
	std::vector<std::vector<Tile*>> LevelMatrix;
	TilePrototype* tilePrototype = new TilePrototype();

	//Tests
	bool TestCameraPositionInput();
	bool IsCameraInputNull(CCamera* camera);
	bool HasCameraMoved(CCamera* camera);
	bool IsCameraMovingLeft(CCamera* camera, CRenderer* renderer);
	std::vector<std::vector<Tile*>> IsLevelMatrixLoaded(Level* level);
	bool AreAnyTilesOffScreen(Level* level, CRenderer* renderer, CCamera* camera, bool GoingLeft);
public:
	TilesObservator();
	TilesObservator(CCamera* camera);
	~TilesObservator();

	void ObserveCameraPosition(Level* level, CCamera* camera, CRenderer* renderer);
	void UpdateLevelMatrix(Level* level);

};

