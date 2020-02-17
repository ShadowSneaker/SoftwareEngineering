#pragma once
#include "UsableItem.h"
class Switchable :
	public UsableItem
{
private:
	bool m_active;
public:
	Item* Clone() override { return new Switchable(*this); }
protected:
	void OnUsed() override;
	void OnAdded() override;
	void OnRemoved() override;
};

