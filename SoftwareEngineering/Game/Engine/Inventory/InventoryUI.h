#pragma once
#include "../UI/UIBase.h"
#include "../Graphics/Renderer/Renderer.h"

class InventoryUI : UIBase
{
public:
	InventoryUI(CRenderer* renderer);
	void update() override;

	void Draw();

	void AddElement(UIElement* element) { addElement(element); }
	BuilderFactory* GetUIFactory() { return factory; }
};

