#pragma once

#include "unzip.h"
#include "zip.h"
class CTestObject2
{
public:
	BOOL m_bOpen;
};

class CLJHZip
{
public:
	CLJHZip();
	~CLJHZip();

public:
	void CreateZipFile();
	CString GetZipErrorMsg(ZRESULT zResult);
	BOOL AddFile(CString strFileName, CString strTargetPath);

private:
	HZIP m_hZip;
};

