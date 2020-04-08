#pragma once
#include "UIBase.h"
#include "../Graphics/Renderer/Renderer.h"

class SampleUI : public UIBase {
public:
	SampleUI(CRenderer* renderer);
	void update() override;
};