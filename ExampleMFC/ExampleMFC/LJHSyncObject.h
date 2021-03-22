#pragma once
#include <iostream>
#include <windows.h>

class CLJHSyncObject
{
public:
	HANDLE m_hMutex;

private:
	int testMutex();
	int testCriticalSection();

	CLJHSyncObject();
	~CLJHSyncObject();
};

