#pragma once
class Effect
{
private:
	bool m_isActive = false;
public:
	virtual void StartEffect(/*pass entity here*/) { m_isActive = true; }
	virtual void EndEffect(/*pass entity here*/) { m_isActive = false; }

	bool GetIsActive()const { return m_isActive; }
};