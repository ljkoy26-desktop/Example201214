
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

#include "unzip.h"
#include "zip.h"

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
END_MESSAGE_MAP()


// CExampleMFCDlg �޽��� ó����

BOOL CExampleMFCDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

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
		//	// ������ ��� �ڵ��Դϴ�.
		//    #define ZR_OK 0x00000000 // nb. �ǻ� �ڵ� zr-recent�� ��ȯ���� �ʽ��ϴ�.
		//    #define ZR_RECENT 0x00000001 //������ FormatZipMessage�� ������ �� �ֽ��ϴ�.
		//    	// ������ �Ϲ����� �ý��� ���� �׸� (�� : ������ �� �� ����)
		//    #define ZR_GENMASK 0x0000FF00
		//    #define ZR_NODUPH 0x00000100 // �ڵ��� ���� �� �� �����ϴ�.
		//    #define ZR_NOFILE 0x00000200 // ������ ����ų� �� �� �����ϴ�.
		//    #define ZR_NOALLOC 0x00000300 // �Ϻ� ���ҽ� �Ҵ� ����
		//    #define ZR_WRITE 0x00000400 // ���Ͽ� ���� �Ϲ����� ����
		//    #define ZR_NOTFOUND 0x00000500 // zip���� �ش� ������ ã�� �� �����ϴ�.
		//    #define ZR_MORE 0x00000600 // ������ Ǯ �����Ͱ� �� �ֽ��ϴ�.
		//    #define ZR_CORRUPT 0x00000700 // zip ������ �ջ�Ǿ��ų� zip ������ �ƴմϴ�.
		//    #define ZR_READ 0x00000800 // ���� �б� �Ϲ� ����
		//    	// ������ ȣ������ �Ǽ��� ���� ���Դϴ�.
		//    #define ZR_CALLERMASK 0x00FF0000
		//    #define ZR_ARGS 0x00010000 // �μ��� ���� �Ϲ����� �Ǽ�
		//    #define ZR_NOTMMAP 0x00020000 // ZipGetMemory�� �õ������� mmap zip ���Ͽ����� �۵��մϴ�.
		//    #define ZR_MEMSIZE 0x00030000 // �޸� ũ�Ⱑ �ʹ� �۽��ϴ�.
		//    #define ZR_FAILED 0x00040000 //�� �Լ��� ȣ������ �� �̹� �����߽��ϴ�.
		//    #define ZR_ENDED 0x00050000 // zip ������ �̹� ����Ǿ����ϴ�.
		//    #define ZR_MISSIZE 0x00060000 // ǥ�õ� �Է� ���� ũ�Ⱑ �߸��Ǿ����ϴ�.
		//    #define ZR_PARTIALUNZ 0x00070000 // ������ �̹� �κ������� ���� �����Ǿ����ϴ�.
		//    #define ZR_ZMODE 0x00080000 // zip ���� / ���� ȥ�� �õ�
		//    	// ������ zip ���̺귯�� ��ü�� ���׿��� ��Ե˴ϴ�.
		//    #define ZR_BUGMASK 0xFF000000
		//    #define ZR_NOTINITED 0x01000000 // �ʱ�ȭ�� �۵����� �ʾҽ��ϴ�.
		//    #define ZR_SEEK 0x02000000 // �˻� �� ������ ������ ã�������մϴ�.
		//    #define ZR_NOCHANGE 0x04000000 // ���忡 ���� ������ �ٲ������ ������ ����
		//    #define ZR_FLATE 0x05000000 // �� / ���÷��̼� �ڵ��� ���� ����
	
	HZIP hZip;
	ZRESULT zResult;

	// ���� ȭ���� ��η� �׽�Ʈ ����
	TCHAR szDesktop[MAX_PATH];
	SHGetSpecialFolderPath(NULL, szDesktop, CSIDL_DESKTOP, FALSE);

	CString strPathZip = (CString)szDesktop;
	CString strPathIni = (CString)szDesktop;
	CString strPathTxt = (CString)szDesktop;
	CString strTargetFile = (CString)szDesktop;

	strPathZip += _T("\\����.zip");
	strPathIni += _T("\\�̴�.ini");
	strPathTxt += _T("\\�ؽ�Ʈ.txt");
	strTargetFile += _T("\\Orange FAQ ����.xlsx");

	// ����ȭ�� ��ο� ���� ������ �����Ѵ�.
	CreateDirectory(szDesktop, NULL);
	//hZip = CreateZip(strPathZip, _T("tiger"));  // 1 : path , 2 : password 
	hZip = CreateZip(strPathZip, NULL);

	//zip���� ���� ���н� ó��
	if (hZip == NULL)
	{
		AfxMessageBox("Error: Failed to create Zip");
		return;
	}

	// �Ʒ��� ���� ini ������ �����ȴ�. (WritePrivateProfileString)
	//[�������]
	//Ŷ�� = C:\Users\Warevalley\Desktop\�ؽ�Ʈ.txt
	// 3 : ���
	// 4 : ������ ����
	// �ݵ�� �ʿ��� ������ �ƴմϴ�. (ini)���Ͽ� ���� ������
	//bool bReturn = ::WritePrivateProfileString(_T("�������"), _T("Ŷ��"), szDesktop, strPathTxt); 

	// strPathIni �� ������ ������ ����ȴ�. 	
	// �߰��ϱ� ���� �ش��ο� ������ �����ؾ� �Ѵ�.
	// 3�� �Ű����� ��ġ�� ������ �������� ������ ������ȯ -> ������� excel ���� �� ������ Src�� ���� ����غ� ����


	CString strSRC(_T("�ȳ��ϼ��� ������ �Դϴ�"));
	zResult = ZipAdd(hZip, _T("�׽�Ʈ.txt"), (void*)(LPCTSTR)strSRC, strSRC.GetLength());

	//zResult = ZipAdd(hZip, _T("�׽�Ʈ.txt"), (void*)fp, );
	//zResult = ZipAdd(hZip, _T("������ ���빰.ini"), strTargetFile); // 2 : ������ ���ϸ�.���� ,  3 : ������ ����
	//zResult = ZipAdd(hZip, _T("�׽�Ʈ.txt"), strTargetFile);
	//zResult = ZipAdd(hZip, _T("����.xlsx"), strTargetFile);

	//ZipAdd ��� ���н� ó��  
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
