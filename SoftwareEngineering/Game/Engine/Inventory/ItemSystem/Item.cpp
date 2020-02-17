#include "Item.h"
#include "../Inventory.h"

void Item::Destroy()
{
	//Remove item from owning inventory
	if (m_owner)
		m_owner->RemoveItem(this);
	//delete object
}

void Item::UpdateOwner(Inventory* newOwner)
{
	//If the new owner is null, set the owner to null and then go no further
	if (newOwner == nullptr)
	{
		m_owner = nullptr;
		return;
	}

	//Only update the owner the if new owner actually contains this item
	if(newOwner->ContainsItem(this))
		m_owner = newOwner;
}

void Item::IncrementStackSize()
{
	//Only increment if item is actually stackable, if not just set stacksize to default
	if (m_stackable)
		m_stackSize++;
	else
		m_stackSize = 1;
}

void Item::DecrementStackSize()
{
	//Only decrement if item is actually stackable, if not just set stacksize to default
	if (m_stackable)
		m_stackSize--;
	else
		m_stackSize = 1;
}

void Item::OnAdded()
{
}

void Item::OnRemoved()
{
}
