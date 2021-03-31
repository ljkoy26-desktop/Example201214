
// ExampleMFCDlg.cpp : 구현 파일
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


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

	// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
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


// CExampleMFCDlg 대화 상자



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


// CExampleMFCDlg 메시지 처리기
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
	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
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

	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
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
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
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
void CExampleMFCDlg::OnBnClickedButtonCArrayTest() // Carray테스트
{
	/* 객체가 정상적으로 소멸되면서,
		 a->b->c->d 의 순서로 소멸되고 메모리릭이 없으면 성공!
	*/

	CLJHChildA* pa = new CLJHChildA;
	CLJHChildB* pb = new CLJHChildB;
	CLJHChildC* pc = new CLJHChildC;
	CLJHChildD* pd = new CLJHChildD;

	pc->m_aItem.Add(pd);
	pa->m_aItem.Add(pc); // 리스트는 없는 상태

	for (int i = 0; pa->m_aItem.GetSize(); ++i)
	{
		if (pa->m_aItem.GetAt(i)->m_nType == CLJHBase::C)
		{
			/* 한개의 케이스 에서는 성공했지만,
				pc 가 여러개 있을경우나, 순서가 뒤죽박죽이면 조금 결과가 달라짐...
				노트북에서 출력 테스트 완료 20.12.15
			*/
			//CLJHBase* pItem = pa->m_aItem.ElementAt(i); // GetAt과 동일한 결과
			CLJHBase* pItem = pa->m_aItem.GetAt(i);
			pa->m_aItem.RemoveAt(i);
			pa->m_aItem.Add(pb);
			pb->m_aItem.Add(pItem);
			break;
		}
	}
	delete pa;
}
void CExampleMFCDlg::OnBnClickedButtonFilePathOutput() // 선택한 파일의 경로 출력 예제
{
	BROWSEINFO BrInfo;
	TCHAR szBuffer[512];                                      // 경로저장 버퍼 

	::ZeroMemory(&BrInfo, sizeof(BROWSEINFO));
	::ZeroMemory(szBuffer, 512);

	BrInfo.hwndOwner = GetSafeHwnd();
	BrInfo.lpszTitle = _T("파일이 저장될 폴더를 선택하세요");
	BrInfo.ulFlags = BIF_NEWDIALOGSTYLE | BIF_EDITBOX | BIF_RETURNONLYFSDIRS;

	LPITEMIDLIST pItemIdList = ::SHBrowseForFolder(&BrInfo); // 창의 띄워지는곳

	::SHGetPathFromIDList(pItemIdList, szBuffer);
	AfxMessageBox(szBuffer);
}


void CExampleMFCDlg::OnBnClickedButtonThreadTest() // 스레드 테스트
{
	// 유저 인터페이스 스레드는 해당Dlg, App실행한 메인 주 쓰레드를 말하게되며,
	// 작업자 스레드는 현재 함수에 존재하는 쓰레드를 의미한다
	UINT n = 600;

	// ** 완전 중요
	// 스레드를 사용한경우!
	AfxBeginThread(ThreadFunc, (LPVOID)n);

	// 이거는 스레드를 사용하지 않은경우!
	//ThreadFunc((LPVOID)n);

}
UINT CExampleMFCDlg::ThreadFunc(LPVOID pParam)
{
	UINT n = (UINT)pParam;
	UINT nSum = 0;
	for (UINT i = 1; i < n; ++i)
	{
		// 스레드로 동작하는 것을 확인하기 위해서
		// 0.01초간 대기 시간을 둔다.

		nSum += i;
		Sleep(10);
	}

	//계산결과 출력
	CString str;
	str.Format(_T("계산 결과 = %d"), nSum);
	AfxMessageBox(str);

	return 0;
}


void CExampleMFCDlg::OnBnClickedButtonSmartPointer() // 스마트 포인터
{
}
void CExampleMFCDlg::OnBnClickedButtonLamdaExpr() // 람다 표현식
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
void CExampleMFCDlg::OnBnClickedButtonBinding() // 정적, 동적 바인딩
{
	CLJHBase obase;
	CLJHChildA child;
	CLJHBase *pbase = new CLJHBase;
	CLJHBase &rbase = child;

	int nTest(0);
	nTest = obase.VirtualTest();				// 정적 바인딩
	nTest = child.VirtualTest();				// 정적 바인딩
	nTest = pbase->VirtualTest();				// 동적 바인딩
	nTest = rbase.VirtualTest();				// 동적 바인딩
}
void CExampleMFCDlg::OnBnClickedButtonCreateDump()
{
	/*	Begin ~ End 이부분에 예외가 생길 코드가 들어가면 됩니다. */
	// 1. Visual Studio 2015 버전에서 미니덤프 파일 생성 테스트
	//	- 네이티브 전용으로 디버그 옵션을 사용하면, 프로그램이 직접적인 예외를 발생한 부분을 발견할수 있습니다.
	// 2. 소스코드에 변경사항이 있을경우, 이전 데이터를 찾을수 없게됩니다.

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
