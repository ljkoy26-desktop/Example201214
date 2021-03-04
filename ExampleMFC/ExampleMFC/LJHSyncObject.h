#pragma once
#include <iostream>
#include <windows.h>

class LJHSyncObject
{
public:
	HANDLE m_hMutex;



public:
	int testMutex();
	int testCriticalSection();

	LJHSyncObject();
	~LJHSyncObject();
};

