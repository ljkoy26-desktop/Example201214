
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
	HZIP hz;
	ZRESULT zr;
	CString strPathZip = _T("D:\\ziptest\\test.zip");
	CString strPathIni = _T("D:\\ziptest\\test.ini");

	//D:\ZIP\ ��ο� test.zip�̶� ������ �����Ѵ�.

	CreateDirectory(_T("D:\\ZIP"), NULL); // 1 : 
	hz = CreateZip(strPathZip, _T("tiger"));  // 1 : path , 2 : password
	
	//zip���� ���� ���н� ó��
	if (hz == 0)
	{
		AfxMessageBox("Error: Failed to create Zip");
		return;
	}

	int i(0), nLen(0);
	CString strTmp(_T("")), strTmpPath(_T("")), strTmpName(_T(""));

	//INI ������ Ȱ���Ͽ� ������ ���� ������ �����Ѵ�.
	//D����̺꿡 test.ini�� �����̸����� �����Ѵ�.
	//FTP�� ���ǿ� Total Ű���� ���� ����, �� ���ĺ��ʹ� ������� ���� �̸��� �ִ´�.
	//INI������ D����̺꿡 test.ini�� �����̸����� �����Ѵ�.
	::WritePrivateProfileString("FTP", "Total", "1", strPathIni);
	::WritePrivateProfileString("FTP", "1", "D:\\ziptest\\test.txt", strPathIni);

	//ZipAdd ������� D:\test.ini�� idx.ini�� �ٲپ� D:\ZIP\test.zip ���Ͽ� �߰��Ѵ�.
	zr = ZipAdd(hz, "idx.ini", strPathIni); //������ ���� ��"idx.ini"

	//ZipAdd ��� ���н� ó��  
	if (zr != ZR_OK)
	{
		AfxMessageBox("Error: Failed to add Zip");
		zr = CloseZip(hz);
		return;
	}

	//ZipAdd ������� �ٸ� ������ �߰��Ѵ�.
	{
		strTmpName = "test.txt";      //Zip���Ͽ� ������ �����̸�
		strTmpPath = "D:\\ziptest\\test.txt";  //������ ���� ��ġ
		zr = ZipAdd(hz, strTmpName, strTmpPath);

		if (zr != ZR_OK)
		{
			AfxMessageBox("Error: Failed to add Zip22");
			zr = CloseZip(hz);
			return;
		}
	}
	zr = CloseZip(hz);




}


void CExampleMFCDlg::OnBnClickedButton3() // unzip
{



}
