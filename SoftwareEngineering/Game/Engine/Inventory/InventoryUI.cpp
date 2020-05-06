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

	int w = 9;
	int h = m_inventory->GetMaxSlots() / w;

	int itemSize = 32;

	int itemsXOffset = 24;
	int itemsYOffset = 64;
	int moneyYOffset = 32;

	int height = (itemsYOffset + moneyYOffset + (h * itemSize) + (h * 8));


	SVector2i screenSize = m_renderer->GetWindowSize();

	clearElements();
	auto mainBox = boxbuilder->withPosition((float)screenSize.X() / 2.f - screenSize.X() / 4.f, (float)screenSize.Y() / 2.f - height / 2.f).
		withDimensions(screenSize.X() / 2.f, height).withColour({ 255,255,255,255 }).build();

	AddElement(mainBox);

	AddElement(labelbuilder->withText("Player Inventory").withAnchor(Anchor::TOP_CENTRE).withFont(FONT_ROBOTO, 12).
		withParent(mainBox).withColour({ 0,0,0,255 }).withDimensions(96, 32).build());

	AddElement(labelbuilder->withText("Money Amount " + std::to_string(m_inventory->CountMoney())).withAnchor(Anchor::TOP_RIGHT).
		withFont(FONT_ROBOTO, 12).withParent(mainBox).withColour({ 0,0,0,255 }).withDimensions(96, moneyYOffset).withPosition(0, 24).build());

	int i = 0;
	for (int y = 0; y < h; y++)
	{
		for (int x = 0; x < w; x++)
		{
			if (m_inventory->GetItems().size() > i&& m_inventory->GetItems()[i] != nullptr)
			{
				//AddElement(labelbuilder->withText(m_inventory->GetItems()[i]->GetName()).withFont(FONT_ROBOTO, 8).withParent(mainBox).withDimensions(itemSize, itemSize).
				//	withPosition(itemsXOffset + x * (itemSize + 8), itemsYOffset + y * (itemSize + 8)).withColour({ 0,0,0,255 }).build());
			}
			else
			{
				AddElement(boxbuilder->withParent(mainBox).withDimensions(itemSize, itemSize).withPosition(itemsXOffset + x * (itemSize + 8), itemsYOffset + y * (itemSize + 8)).withColour({ 0,0,0,255 }).build());
			}
			i++;
		}
	}

	delete boxbuilder;
	delete labelbuilder;
}
