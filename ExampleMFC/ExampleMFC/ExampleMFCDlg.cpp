
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


class LJHChildA;
class LJHChildB;
class LJHChildC;
class LJHChildD;

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
	ON_BN_CLICKED(IDC_BUTTON1, &CExampleMFCDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CExampleMFCDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CExampleMFCDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CExampleMFCDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CExampleMFCDlg::OnBnClickedButton5)
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
	m_pView->Create(NULL, _T(""), WS_CHILD | WS_BORDER | WS_VISIBLE, CRect(500,500, 1200, 700), this, 50001);

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

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
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

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

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

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CExampleMFCDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CExampleMFCDlg::OnBnClickedButton1() // Carray테스트
{
	/* 객체가 정상적으로 소멸되면서, 
		 a->b->c->d 의 순서로 소멸되고 메모리릭이 없으면 성공!
	*/
	
	LJHChildA* pa = new LJHChildA; // 리스너
	LJHChildB* pb = new LJHChildB; // 디스크립션 리스트
	LJHChildC* pc = new LJHChildC; // 디스크립션
	//LJHChildC* pc1 = new LJHChildC; // 디스크립션
	//LJHChildC* pc2 = new LJHChildC; // 디스크립션
	LJHChildD* pd = new LJHChildD; // 
	
	pc->m_aItem.Add(pd);
	pa->m_aItem.Add(pc); // 리스트는 없는 상태
	
	for (int i = 0; pa->m_aItem.GetSize(); ++i)
	{
		if (pa->m_aItem.GetAt(i)->m_nType == LJHBase::C)
		{
			/* 한개의 케이스 에서는 성공했지만, 
				pc 가 여러개 있을경우나, 순서가 뒤죽박죽이면 조금 결과가 달라짐...
				노트북에서 출력 테스트 완료 20.12.15
			*/
			//LJHBase* pItem = pa->m_aItem.ElementAt(i); // GetAt과 동일한 결과
			LJHBase* pItem = pa->m_aItem.GetAt(i);
			pa->m_aItem.RemoveAt(i);
			pa->m_aItem.Add(pb);
			pb->m_aItem.Add(pItem);
			break;
		}
	}
	delete pa;
}


void CExampleMFCDlg::OnBnClickedButton2() // ZIP
{
 // ctrl + R 로 변수 및 함수명 일괄 변경 -> 좋은기능임
 // ctrl + - + 로 이전 이후 호출 위치 검색할수 있지만, 어떻게 쓰는지는 아직 잘 몰름 (좋은 기능인것 같다 ) -> 아닌거같음
 //https://www.clien.net/service/board/lecture/13375134

	
	ZRESULT zResult;

	// 하위 경로를 깃허브 바로위 디렉토리 까지 구하기 위해 호출한다 ( D:\GitHub\Example201214 ) 최종경로
	TCHAR szFolder[MAX_PATH];
	GetModuleFileName(NULL, szFolder, MAX_PATH); // D:\GitHub\Example201214\ExampleMFC\Debug\ExampleMFC.exe 실행 경로 반환

	PathRemoveFileSpec(szFolder);
	PathRemoveFileSpec(szFolder);
	PathRemoveFileSpec(szFolder);

	CString strFolder(szFolder);
	CString strZipPath(strFolder);
	CTime time = GetCurrentTime();
	TRACE(_T("%d : %d : %d\n"), time.GetHour(), time.GetMinute(), time.GetSecond());
	CString strTarget(_T("테스트.xlsx"));
	CString strTarget2(_T("테스트.txt"));

	CString strTargetPath(strFolder);
	CString strTargetPath2(strFolder);

	CString strRes(_T(""));
#ifdef UNICODE
	strZipPath += _T("\\테스트 알집(유니코드).zip");
#else 
	strZipPath += _T("\\테스트 알집(멀티바이트).zip");
#endif
	// 바탕화면 경로에 알집 파일을 생성한다.
	m_hZip = CreateZip(strZipPath, NULL); // 2번쨰 인자는 패스워드
	
	if (m_hZip == NULL)
	{
		AfxMessageBox(_T("Error: Failed to create Zip"));
		return;
	}	
	
	// 한글 파일명에 대한 처리 필요 ( 경로에 한글에 들어가도 문제될수 있다 )
	strTargetPath = strFolder + _T("\\") + strTarget;
	zResult = ZipAdd(m_hZip, strTarget, strTargetPath);
	if (ZR_OK != zResult)
	{
		strRes = GetZipErrorMsg(zResult);
		AfxMessageBox(strRes);
		return;
	}

	strTargetPath2 = strFolder + _T("\\") + strTarget2;
	zResult = ZipAdd(m_hZip, strTarget2,strTargetPath2);
	if (ZR_OK != zResult)
	{
		strRes = GetZipErrorMsg(zResult);
		AfxMessageBox(strRes);
		return;
	}

	/* fn : ZipAdd */
	// 1 : zip 객체
	// 2 : 생성하려는 파일명 3번으로 추가한 파일의 패스명
	// 3 : 추가하려는 파일의 풀 Path명 

	GetZipErrorMsg(CloseZip(m_hZip));
	time = GetCurrentTime();
	TRACE(_T("%d : %d : %d\n"), time.GetHour(), time.GetMinute(), time.GetSecond());


	//if (DeleteFile(strTargetPath2) == TRUE)
	//	AfxMessageBox(_T("삭제함"));
}
CString CExampleMFCDlg::GetZipErrorMsg(ZRESULT zResult)
{
	CString sReturn(_T(""));

	TCHAR szMsg[256];
	FormatZipMessage(zResult, szMsg, 256);
	sReturn = szMsg;
	return sReturn;
}
BOOL CExampleMFCDlg::AddFile(CString strFileName, CString strTargetPath)
{
	BOOL bReturn(true);
	ZRESULT zResult = ZipAdd(m_hZip, strFileName, strTargetPath);
	if (ZR_OK != zResult)
	{	
		AfxMessageBox(GetZipErrorMsg(zResult));
		bReturn = false;
	}
	return bReturn;
}


void CExampleMFCDlg::OnBnClickedButton3() // unzip
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




//Data::Data() // 생성자 매개변수가 없는 기본 생성자 입니다.
//{
//}
//
//Data::Data(int _width, int _height) // 기본 생성자가 아닌 2개의 매개변수를 갖는 생성자 입니다.
//{
//	setData(_width, _height);
//}
//
//Shape::Shape(Data elements)
//{
//}
//


void CExampleMFCDlg::OnBnClickedButton4()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CExampleMFCDlg::OnBnClickedButton5() // 스레드 테스트
{
	// 작업자 스레드

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


	UINT sum = 0;
	for (UINT i = 1; i < n; ++i)
	{
		// 스레드로 동작하는 것을 확인하기 위해서
		// 0.01초간 대기 시간을 둔다.

		sum += i;
		Sleep(10);
	}

	//계산결과 출력
	CString str;
	str.Format(_T("계산 결과 = %d"), sum);
	AfxMessageBox(str);

	return 0;
}
