#pragma once
#include "LJHBase.h"

class LJHChildA : public LJHBase
{
public:
	LJHChildA();
	virtual ~LJHChildA();

	int virtual VirtualTest() { return 'A'; };
};

