#pragma once
class CLJHBase
{
public:
	CLJHBase();
	virtual ~CLJHBase();

public:
	enum EM_TYPE {
		BASE = 0,
		A = 1,
		B,
		C,
		D 
	};
	int m_nType;
	CArray<CLJHBase*, CLJHBase*> m_aItem;
	
	virtual int VirtualTest() { return -1; };
};

