#pragma once
class WVBase
{
public:

	enum { BASE = 0, A = 1, B, C, D };
	int m_nType;
	CArray<WVBase*, WVBase*> m_aItem;
	
	WVBase();
	virtual ~WVBase();
};

