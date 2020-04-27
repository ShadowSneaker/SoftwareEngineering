#pragma once
#include "../UI/UIBase.h"

class Inventory;
class CRenderer;

class InventoryUI : UIBase
{
public:
	InventoryUI(CRenderer* renderer, Inventory* inventory);
	void update() override;

	void Draw();

	void AddElement(UIElement* element) { addElement(element); }
	BuilderFactory* GetUIFactory() { return factory; }

	virtual void UpdateElements();
private:
	CRenderer* m_renderer;
	Inventory* m_inventory;
};

