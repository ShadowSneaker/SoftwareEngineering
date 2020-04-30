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

void InventoryUI::Clear()
{
	clearElements();
}

void InventoryUI::UpdateElements()
{
	UILabelBuilder* labelbuilder = (UILabelBuilder*)GetUIFactory()->getBuilder<Label>("Label");
	UIBoxBuilder* boxbuilder = (UIBoxBuilder*)factory->getBuilder<UIBox>("Box");

	SVector2i screenSize = m_renderer->GetWindowSize();

	Clear();

	auto mainBox = boxbuilder->withPosition((float)screenSize.X() / 2.f - screenSize.X() / 4.f, (float)screenSize.Y() / 2.f - screenSize.Y() / 4.f).
	withDimensions(screenSize.X() / 2.f, screenSize.Y() / 2.f).withColour({ 255,255,255,255 }).build();
	
	AddElement(mainBox);
	
	AddElement(labelbuilder->withText("Player Inventory").withAnchor(Anchor::TOP_CENTRE).withFont(FONT_ROBOTO, 12).
		withParent(mainBox).withColour({ 0,0,0,255 }).withDimensions(96, 32).build());

	AddElement(labelbuilder->withText("Money Amount " + std::to_string(m_inventory->CountMoney())).withAnchor(Anchor::TOP_RIGHT).
		withFont(FONT_ROBOTO, 12).withParent(mainBox).withColour({ 0,0,0,255 }).withDimensions(96, 32).withPosition(0,24).build());


	int w = 9;
	int h = m_inventory->GetMaxSlots() / w;

	int itemsXOffset = 24;
	int itemsYOffset = 64;

	int i = 0;
	for (int y = 0; y < h; y++)
	{
		for (int x = 0; x < w; x++)
		{
			int size = 32;
			if(m_inventory->GetItems().size() > i && m_inventory->GetItems()[i] != nullptr)
			{
				AddElement(labelbuilder->withText(m_inventory->GetItems()[i]->GetName()).withFont(FONT_ROBOTO, 8).withParent(mainBox).withDimensions(size, size).
					withPosition(itemsXOffset + x * (size + 8), itemsYOffset + y * (size + 8)).withColour({ 0,0,0,255 }).build());
			}
			else
			{
				AddElement(boxbuilder->withParent(mainBox).withDimensions(size, size).withPosition(itemsXOffset + x * (size + 8), itemsYOffset + y * (size + 8)).withColour({ 0,0,0,255 }).build());
			}
			i++;
		}
	}
	
	delete boxbuilder;
	delete labelbuilder;
}
