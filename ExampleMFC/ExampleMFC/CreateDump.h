#pragma once

// https://docs.microsoft.com/en-us/windows/win32/api/dbghelp/ 
class CTestObject
{
public:
	BOOL m_bOpen;
};

class CCreateDump
{
public:
	CCreateDump();
	~CCreateDump();

public:
	static BOOL Begin(VOID);
	static BOOL End(VOID);
public:
	void TestDump1();
	void TestDump2();
	void TestDump3();
	void TestDump4();

};

