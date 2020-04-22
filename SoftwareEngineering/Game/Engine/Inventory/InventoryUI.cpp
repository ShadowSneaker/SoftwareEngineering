#include "InventoryUI.h"
#include "../Graphics/Renderer/Renderer.h"
#include "Inventory.h"
#include "ItemSystem/Item.h"

InventoryUI::InventoryUI(CRenderer* renderer, Inventory* inventory) : UIBase(renderer) 
{
	m_inventory = inventory;
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

	AddElement(boxbuilder->withDimensions(800, 400).build());

	//for (int i = 0; i < m_inventory->GetItems().size(); i++)
	//{
	//	auto item = m_inventory->GetItems()[i];
	//	AddElement(labelbuilder->withText(item->GetName()).withPosition(0, i * 24).withFont(FONT_ROBOTO, 18).withColour({ 255,255,255,255 }).withDimensions(200, 24).build());
	//}

	delete boxbuilder;
	delete labelbuilder;
}
