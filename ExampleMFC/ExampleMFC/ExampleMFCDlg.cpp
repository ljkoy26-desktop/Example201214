
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


class LJHChildA;
class LJHChildB;
class LJHChildC;
class LJHChildD;

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
	ON_BN_CLICKED(IDC_BUTTON1, &CExampleMFCDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CExampleMFCDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CExampleMFCDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CExampleMFCDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CExampleMFCDlg::OnBnClickedButton5)
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
	m_pView->Create(NULL, _T(""), WS_CHILD | WS_BORDER | WS_VISIBLE, CRect(500,500, 1200, 700), this, 50001);

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

	// �� ��ȭ ������ �������� �����մϴ�.  ���� ���α׷��� �� â�� ��ȭ ���ڰ� �ƴ� ��쿡��
	//  �����ӿ�ũ�� �� �۾��� �ڵ����� �����մϴ�.
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

// ��ȭ ���ڿ� �ּ�ȭ ���߸� �߰��� ��� �������� �׸�����
//  �Ʒ� �ڵ尡 �ʿ��մϴ�.  ����/�� ���� ����ϴ� MFC ���� ���α׷��� ��쿡��
//  �����ӿ�ũ���� �� �۾��� �ڵ����� �����մϴ�.

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

// ����ڰ� �ּ�ȭ�� â�� ���� ���ȿ� Ŀ���� ǥ�õǵ��� �ý��ۿ���
//  �� �Լ��� ȣ���մϴ�.
HCURSOR CExampleMFCDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CExampleMFCDlg::OnBnClickedButton1() // Carray�׽�Ʈ
{
	/* ��ü�� ���������� �Ҹ�Ǹ鼭, 
		 a->b->c->d �� ������ �Ҹ�ǰ� �޸𸮸��� ������ ����!
	*/
	
	LJHChildA* pa = new LJHChildA; // ������
	LJHChildB* pb = new LJHChildB; // ��ũ���� ����Ʈ
	LJHChildC* pc = new LJHChildC; // ��ũ����
	//LJHChildC* pc1 = new LJHChildC; // ��ũ����
	//LJHChildC* pc2 = new LJHChildC; // ��ũ����
	LJHChildD* pd = new LJHChildD; // 
	
	pc->m_aItem.Add(pd);
	pa->m_aItem.Add(pc); // ����Ʈ�� ���� ����
	
	for (int i = 0; pa->m_aItem.GetSize(); ++i)
	{
		if (pa->m_aItem.GetAt(i)->m_nType == LJHBase::C)
		{
			/* �Ѱ��� ���̽� ������ ����������, 
				pc �� ������ ������쳪, ������ ���׹����̸� ���� ����� �޶���...
				��Ʈ�Ͽ��� ��� �׽�Ʈ �Ϸ� 20.12.15
			*/
			//LJHBase* pItem = pa->m_aItem.ElementAt(i); // GetAt�� ������ ���
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
 // ctrl + R �� ���� �� �Լ��� �ϰ� ���� -> ���������
 // ctrl + - + �� ���� ���� ȣ�� ��ġ �˻��Ҽ� ������, ��� �������� ���� �� ���� (���� ����ΰ� ���� ) -> �ƴѰŰ���
 //https://www.clien.net/service/board/lecture/13375134

	
	ZRESULT zResult;

	// ���� ��θ� ����� �ٷ��� ���丮 ���� ���ϱ� ���� ȣ���Ѵ� ( D:\GitHub\Example201214 ) �������
	TCHAR szFolder[MAX_PATH];
	GetModuleFileName(NULL, szFolder, MAX_PATH); // D:\GitHub\Example201214\ExampleMFC\Debug\ExampleMFC.exe ���� ��� ��ȯ

	PathRemoveFileSpec(szFolder);
	PathRemoveFileSpec(szFolder);
	PathRemoveFileSpec(szFolder);

	CString strFolder(szFolder);
	CString strZipPath(strFolder);
	CTime time = GetCurrentTime();
	TRACE(_T("%d : %d : %d\n"), time.GetHour(), time.GetMinute(), time.GetSecond());
	CString strTarget(_T("�׽�Ʈ.xlsx"));
	CString strTarget2(_T("�׽�Ʈ.txt"));

	CString strTargetPath(strFolder);
	CString strTargetPath2(strFolder);

	CString strRes(_T(""));
#ifdef UNICODE
	strZipPath += _T("\\�׽�Ʈ ����(�����ڵ�).zip");
#else 
	strZipPath += _T("\\�׽�Ʈ ����(��Ƽ����Ʈ).zip");
#endif
	// ����ȭ�� ��ο� ���� ������ �����Ѵ�.
	m_hZip = CreateZip(strZipPath, NULL); // 2���� ���ڴ� �н�����
	
	if (m_hZip == NULL)
	{
		AfxMessageBox(_T("Error: Failed to create Zip"));
		return;
	}	
	
	// �ѱ� ���ϸ� ���� ó�� �ʿ� ( ��ο� �ѱۿ� ���� �����ɼ� �ִ� )
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
	// 1 : zip ��ü
	// 2 : �����Ϸ��� ���ϸ� 3������ �߰��� ������ �н���
	// 3 : �߰��Ϸ��� ������ Ǯ Path�� 

	GetZipErrorMsg(CloseZip(m_hZip));
	time = GetCurrentTime();
	TRACE(_T("%d : %d : %d\n"), time.GetHour(), time.GetMinute(), time.GetSecond());


	//if (DeleteFile(strTargetPath2) == TRUE)
	//	AfxMessageBox(_T("������"));
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




//Data::Data() // ������ �Ű������� ���� �⺻ ������ �Դϴ�.
//{
//}
//
//Data::Data(int _width, int _height) // �⺻ �����ڰ� �ƴ� 2���� �Ű������� ���� ������ �Դϴ�.
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
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}


void CExampleMFCDlg::OnBnClickedButton5() // ������ �׽�Ʈ
{
	// �۾��� ������

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


	UINT sum = 0;
	for (UINT i = 1; i < n; ++i)
	{
		// ������� �����ϴ� ���� Ȯ���ϱ� ���ؼ�
		// 0.01�ʰ� ��� �ð��� �д�.

		sum += i;
		Sleep(10);
	}

	//����� ���
	CString str;
	str.Format(_T("��� ��� = %d"), sum);
	AfxMessageBox(str);

	return 0;
}
