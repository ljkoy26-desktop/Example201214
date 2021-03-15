#pragma once
class LJHBase
{
public:

	enum EM_TYPE {
		BASE = 0,
		A = 1,
		B,
		C,
		D 
	};
	int m_nType;
	CArray<LJHBase*, LJHBase*> m_aItem;
	
	LJHBase();
	virtual ~LJHBase();

	int virtual VirtualTest() { return -1; };
};

