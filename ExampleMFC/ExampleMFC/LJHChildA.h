#pragma once
#include "LJHBase.h"

class CLJHChildA : public CLJHBase
{
public:
	CLJHChildA();
	virtual ~CLJHChildA();

	int virtual VirtualTest() { return 'A'; };
};

