
// ExampleMFCDlg.cpp : ���� ����
//

#include "stdafx.h"
#include "ExampleMFC.h"
#include "ExampleMFCDlg.h"
#include "afxdialogex.h"

#include "LJHChildA.h"
#include "LJHChildB.h"
#include "LJHChildC.h"
#include "LJHChildD.h"

#include "LJHZip.h"

#include "LamdaExpr.h"
#include <iostream>
#include <vector>

#include "CreateDump.h"

class CLJHChildA;
class CLJHChildB;
class CLJHChildC;
class CLJHChildD;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ���� ���α׷� ������ ���Ǵ� CAboutDlg ��ȭ �����Դϴ�.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

	// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

// �����Դϴ�.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CExampleMFCDlg ��ȭ ����



CExampleMFCDlg::CExampleMFCDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_EXAMPLEMFC_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CExampleMFCDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BUTTON1, m_ctrlButton);
}

BEGIN_MESSAGE_MAP(CExampleMFCDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CExampleMFCDlg::OnBnClickedButtonCArrayTest)
	ON_BN_CLICKED(IDC_BUTTON2, &CExampleMFCDlg::OnBnClickedButtonZip)
	ON_BN_CLICKED(IDC_BUTTON3, &CExampleMFCDlg::OnBnClickedButtonFilePathOutput)
	ON_BN_CLICKED(IDC_BUTTON5, &CExampleMFCDlg::OnBnClickedButtonThreadTest)
	ON_BN_CLICKED(IDC_BUTTON6, &CExampleMFCDlg::OnBnClickedButtonSmartPointer)
	ON_BN_CLICKED(IDC_BUTTON7, &CExampleMFCDlg::OnBnClickedButtonLamdaExpr)
	ON_BN_CLICKED(IDC_BUTTON9, &CExampleMFCDlg::OnBnClickedButtonBinding)
	ON_BN_CLICKED(IDC_BUTTON_CREATE_DUMP, &CExampleMFCDlg::OnBnClickedButtonCreateDump)
END_MESSAGE_MAP()


// CExampleMFCDlg �޽��� ó����
void CExampleMFCDlg::OnDestroy()
{
	delete m_pView;
}
BOOL CExampleMFCDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	m_pView = new CExampleView;
	m_pView->Create(NULL, _T(""), WS_CHILD | WS_BORDER | WS_VISIBLE, CRect(500, 500, 1200, 700), this, 50001);

	m_pView->OnInitialUpdate();
	// �ý��� �޴��� "����..." �޴� �׸��� �߰��մϴ�.

	// IDM_ABOUTBOX�� �ý��� ��� ������ �־�� �մϴ�.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	SetIcon(m_hIcon, TRUE);			// ū �������� �����մϴ�.
	SetIcon(m_hIcon, FALSE);		// ���� �������� �����մϴ�.

	return TRUE;  // ��Ŀ���� ��Ʈ�ѿ� �������� ������ TRUE�� ��ȯ�մϴ�.
}

void CExampleMFCDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}
void CExampleMFCDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // �׸��⸦ ���� ����̽� ���ؽ�Ʈ�Դϴ�.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Ŭ���̾�Ʈ �簢������ �������� ����� ����ϴ�.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// �������� �׸��ϴ�.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}
HCURSOR CExampleMFCDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}
void CExampleMFCDlg::OnBnClickedButtonCArrayTest() // Carray�׽�Ʈ
{
	/* ��ü�� ���������� �Ҹ�Ǹ鼭,
		 a->b->c->d �� ������ �Ҹ�ǰ� �޸𸮸��� ������ ����!
	*/

	CLJHChildA* pa = new CLJHChildA;
	CLJHChildB* pb = new CLJHChildB;
	CLJHChildC* pc = new CLJHChildC;
	CLJHChildD* pd = new CLJHChildD;

	pc->m_aItem.Add(pd);
	pa->m_aItem.Add(pc); // ����Ʈ�� ���� ����

	for (int i = 0; pa->m_aItem.GetSize(); ++i)
	{
		if (pa->m_aItem.GetAt(i)->m_nType == CLJHBase::C)
		{
			/* �Ѱ��� ���̽� ������ ����������,
				pc �� ������ ������쳪, ������ ���׹����̸� ���� ����� �޶���...
				��Ʈ�Ͽ��� ��� �׽�Ʈ �Ϸ� 20.12.15
			*/
			//CLJHBase* pItem = pa->m_aItem.ElementAt(i); // GetAt�� ������ ���
			CLJHBase* pItem = pa->m_aItem.GetAt(i);
			pa->m_aItem.RemoveAt(i);
			pa->m_aItem.Add(pb);
			pb->m_aItem.Add(pItem);
			break;
		}
	}
	delete pa;
}
void CExampleMFCDlg::OnBnClickedButtonFilePathOutput() // ������ ������ ��� ��� ����
{
	BROWSEINFO BrInfo;
	TCHAR szBuffer[512];                                      // ������� ���� 

	::ZeroMemory(&BrInfo, sizeof(BROWSEINFO));
	::ZeroMemory(szBuffer, 512);

	BrInfo.hwndOwner = GetSafeHwnd();
	BrInfo.lpszTitle = _T("������ ����� ������ �����ϼ���");
	BrInfo.ulFlags = BIF_NEWDIALOGSTYLE | BIF_EDITBOX | BIF_RETURNONLYFSDIRS;

	LPITEMIDLIST pItemIdList = ::SHBrowseForFolder(&BrInfo); // â�� ������°�

	::SHGetPathFromIDList(pItemIdList, szBuffer);
	AfxMessageBox(szBuffer);
}


void CExampleMFCDlg::OnBnClickedButtonThreadTest() // ������ �׽�Ʈ
{
	// ���� �������̽� ������� �ش�Dlg, App������ ���� �� �����带 ���ϰԵǸ�,
	// �۾��� ������� ���� �Լ��� �����ϴ� �����带 �ǹ��Ѵ�
	UINT n = 600;

	// ** ���� �߿�
	// �����带 ����Ѱ��!
	AfxBeginThread(ThreadFunc, (LPVOID)n);

	// �̰Ŵ� �����带 ������� �������!
	//ThreadFunc((LPVOID)n);

}
UINT CExampleMFCDlg::ThreadFunc(LPVOID pParam)
{
	UINT n = (UINT)pParam;
	UINT nSum = 0;
	for (UINT i = 1; i < n; ++i)
	{
		// ������� �����ϴ� ���� Ȯ���ϱ� ���ؼ�
		// 0.01�ʰ� ��� �ð��� �д�.

		nSum += i;
		Sleep(10);
	}

	//����� ���
	CString str;
	str.Format(_T("��� ��� = %d"), nSum);
	AfxMessageBox(str);

	return 0;
}


void CExampleMFCDlg::OnBnClickedButtonSmartPointer() // ����Ʈ ������
{
}
void CExampleMFCDlg::OnBnClickedButtonLamdaExpr() // ���� ǥ����
{
	CLamdaExpr lamda;                    
	lamda.testLamda();
}
bool CExampleMFCDlg::GetCurrentLogonUserName(/*[out]*/ LPTSTR& lpszAccountName, /*[out]*/ LPTSTR& lpszReferencedDomainName)
{
}

void CExampleMFCDlg::OnBnClickedButtonZip()
{
	// Jenkins WebHook Test
	// Jenkins WebHook Test...

	CLJHZip zip;
	zip.CreateZipFile();
	//CString strMessage = GetZipErrorMsg();
}
void CExampleMFCDlg::OnBnClickedButtonBinding() // ����, ���� ���ε�
{
	CLJHBase obase;
	CLJHChildA child;
	CLJHBase *pbase = new CLJHBase;
	CLJHBase &rbase = child;

	int nTest(0);
	nTest = obase.VirtualTest();				// ���� ���ε�
	nTest = child.VirtualTest();				// ���� ���ε�
	nTest = pbase->VirtualTest();				// ���� ���ε�
	nTest = rbase.VirtualTest();				// ���� ���ε�
}
void CExampleMFCDlg::OnBnClickedButtonCreateDump()
{
	/*	Begin ~ End �̺κп� ���ܰ� ���� �ڵ尡 ���� �˴ϴ�. */
	// 1. Visual Studio 2015 �������� �̴ϴ��� ���� ���� �׽�Ʈ
	//	- ����Ƽ�� �������� ����� �ɼ��� ����ϸ�, ���α׷��� �������� ���ܸ� �߻��� �κ��� �߰��Ҽ� �ֽ��ϴ�.
	// 2. �ҽ��ڵ忡 ��������� �������, ���� �����͸� ã���� ���Ե˴ϴ�.

	CCreateDump dump;
	//dump.Begin();
	//dump.TestDump1();
	//dump.TestDump2();
	//dump.TestDump3();
	//dump.End();
	int n(11);
	CCreateDump::Begin();

	//dump.TestDump1();
	//dump.TestDump3();
	dump.TestDump4();
	//dump.TestDump3();
	//CTestObject* m_obj = new CTestObject;
	//m_obj = NULL;
	//m_obj->m_bOpen = false;

	//CCreateDump::End();
}
