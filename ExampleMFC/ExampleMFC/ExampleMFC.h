
// ExampleMFC.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CExampleMFCApp:
// �� Ŭ������ ������ ���ؼ��� ExampleMFC.cpp�� �����Ͻʽÿ�.
//

class CExampleMFCApp : public CWinApp
{
public:
	CExampleMFCApp();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern CExampleMFCApp theApp;