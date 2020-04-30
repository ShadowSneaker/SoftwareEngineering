#include "InventoryUI.h"
#include "../Graphics/Renderer/Renderer.h"
#include "Inventory.h"
#include "ItemSystem/Item.h"

InventoryUI::InventoryUI(CRenderer* renderer, Inventory* inventory) : UIBase(renderer) 
{
	m_inventory = inventory;
	m_renderer = renderer;
}

void InventoryUI::update()
{
}

void InventoryUI::Draw()
{
	//UpdateElements();
	updateAllElements();
	drawAllElements();
}

void InventoryUI::UpdateElements()
{
	UILabelBuilder* labelbuilder = (UILabelBuilder*)GetUIFactory()->getBuilder<Label>("Label");
	UIBoxBuilder* boxbuilder = (UIBoxBuilder*)factory->getBuilder<UIBox>("Box");

	SVector2i screenSize = m_renderer->GetWindowSize();
	
	//AddElement(boxbuilder->withPosition((float)screenSize.X()/2.f - screenSize.X() / 4.f, (float)screenSize.Y() / 2.f - screenSize.Y()/4.f).withDimensions(screenSize.X()/2.f, screenSize.Y()/2.f).withColour({255,255,255,255}).build());

	for (int i = 0; i < m_inventory->GetItems().size(); i++)
	{
		auto item = m_inventory->GetItems()[i];
		AddElement(labelbuilder->withText(item->GetName()).withPosition(0, i * 24).withFont(FONT_ROBOTO, 18).withColour({ 255,255,255,255 }).withDimensions(200, 24).build());
	}

	delete boxbuilder;
	delete labelbuilder;
}
