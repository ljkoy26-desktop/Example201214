
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

#include "unzip.h"
#include "zip.h"

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
END_MESSAGE_MAP()


// CExampleMFCDlg 메시지 처리기

BOOL CExampleMFCDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

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
		//	// 다음은 결과 코드입니다.
		//    #define ZR_OK 0x00000000 // nb. 의사 코드 zr-recent는 반환되지 않습니다.
		//    #define ZR_RECENT 0x00000001 //하지만 FormatZipMessage에 전달할 수 있습니다.
		//    	// 다음은 일반적인 시스템 관련 항목 (예 : 파일을 열 수 없음)
		//    #define ZR_GENMASK 0x0000FF00
		//    #define ZR_NODUPH 0x00000100 // 핸들을 복제 할 수 없습니다.
		//    #define ZR_NOFILE 0x00000200 // 파일을 만들거나 열 수 없습니다.
		//    #define ZR_NOALLOC 0x00000300 // 일부 리소스 할당 실패
		//    #define ZR_WRITE 0x00000400 // 파일에 쓰는 일반적인 오류
		//    #define ZR_NOTFOUND 0x00000500 // zip에서 해당 파일을 찾을 수 없습니다.
		//    #define ZR_MORE 0x00000600 // 압축을 풀 데이터가 더 있습니다.
		//    #define ZR_CORRUPT 0x00000700 // zip 파일이 손상되었거나 zip 파일이 아닙니다.
		//    #define ZR_READ 0x00000800 // 파일 읽기 일반 오류
		//    	// 다음은 호출자의 실수로 인한 것입니다.
		//    #define ZR_CALLERMASK 0x00FF0000
		//    #define ZR_ARGS 0x00010000 // 인수에 대한 일반적인 실수
		//    #define ZR_NOTMMAP 0x00020000 // ZipGetMemory를 시도했지만 mmap zip 파일에서만 작동합니다.
		//    #define ZR_MEMSIZE 0x00030000 // 메모리 크기가 너무 작습니다.
		//    #define ZR_FAILED 0x00040000 //이 함수를 호출했을 때 이미 실패했습니다.
		//    #define ZR_ENDED 0x00050000 // zip 생성이 이미 종료되었습니다.
		//    #define ZR_MISSIZE 0x00060000 // 표시된 입력 파일 크기가 잘못되었습니다.
		//    #define ZR_PARTIALUNZ 0x00070000 // 파일이 이미 부분적으로 압축 해제되었습니다.
		//    #define ZR_ZMODE 0x00080000 // zip 생성 / 열기 혼합 시도
		//    	// 다음은 zip 라이브러리 자체의 버그에서 비롯됩니다.
		//    #define ZR_BUGMASK 0xFF000000
		//    #define ZR_NOTINITED 0x01000000 // 초기화가 작동하지 않았습니다.
		//    #define ZR_SEEK 0x02000000 // 검색 할 수없는 파일을 찾으려고합니다.
		//    #define ZR_NOCHANGE 0x04000000 // 저장에 대한 마음이 바뀌었지만 허용되지 않음
		//    #define ZR_FLATE 0x05000000 // 디 / 인플레이션 코드의 내부 오류
	
	HZIP hZip;
	ZRESULT zResult;

	// 바탕 화면의 경로로 테스트 진행
	TCHAR szDesktop[MAX_PATH];
	SHGetSpecialFolderPath(NULL, szDesktop, CSIDL_DESKTOP, FALSE);

	CString strPathZip = (CString)szDesktop;
	CString strPathIni = (CString)szDesktop;
	CString strPathTxt = (CString)szDesktop;
	CString strTargetFile = (CString)szDesktop;

	strPathZip += _T("\\알집.zip");
	strPathIni += _T("\\이닛.ini");
	strPathTxt += _T("\\텍스트.txt");
	strTargetFile += _T("\\Orange FAQ 정리.xlsx");

	// 바탕화면 경로에 알집 파일을 생성한다.
	CreateDirectory(szDesktop, NULL);
	//hZip = CreateZip(strPathZip, _T("tiger"));  // 1 : path , 2 : password 
	hZip = CreateZip(strPathZip, NULL);

	//zip파일 생성 실패시 처리
	if (hZip == NULL)
	{
		AfxMessageBox("Error: Failed to create Zip");
		return;
	}

	// 아래와 같이 ini 파일이 생성된다. (WritePrivateProfileString)
	//[생성경로]
	//킷값 = C:\Users\Warevalley\Desktop\텍스트.txt
	// 3 : 경로
	// 4 : 생성할 파일
	// 반드시 필요한 내용은 아닙니다. (ini)파일에 관한 샘플임
	//bool bReturn = ::WritePrivateProfileString(_T("생성경로"), _T("킷값"), szDesktop, strPathTxt); 

	// strPathIni 이 파일의 내용이 압축된다. 	
	// 추가하기 전에 해당경로에 파일이 존재해야 한다.
	// 3번 매개변수 위치에 파일이 존재하지 않으면 에러반환 -> 만들어진 excel 파일 및 데이터 Src를 구해 사용해볼 예정


	CString strSRC(_T("안녕하세요 이재현 입니다"));
	zResult = ZipAdd(hZip, _T("테스트.txt"), (void*)(LPCTSTR)strSRC, strSRC.GetLength());

	//zResult = ZipAdd(hZip, _T("테스트.txt"), (void*)fp, );
	//zResult = ZipAdd(hZip, _T("압축할 내용물.ini"), strTargetFile); // 2 : 압축할 파일명.포맷 ,  3 : 압축할 파일
	//zResult = ZipAdd(hZip, _T("테스트.txt"), strTargetFile);
	//zResult = ZipAdd(hZip, _T("엑셀.xlsx"), strTargetFile);

	//ZipAdd 명령 실패시 처리  
	if (zResult != ZR_OK)
	{
		AfxMessageBox("Error: Failed to add Zip");
		zResult = CloseZip(hZip);
		return;
	}
	zResult = CloseZip(hZip);
}


void CExampleMFCDlg::OnBnClickedButton3() // unzip
{



}
