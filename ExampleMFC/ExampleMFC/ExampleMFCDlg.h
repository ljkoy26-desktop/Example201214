
// ExampleMFCDlg.h : ��� ����
//

#pragma once
#include "afxwin.h"

#include "unzip.h"
#include "zip.h"


#include "ExampleView.h"
// CExampleMFCDlg ��ȭ ����
class CExampleMFCDlg : public CDialogEx
{
// �����Դϴ�.
public:
	CExampleMFCDlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_EXAMPLEMFC_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV �����Դϴ�.

		
// �����Դϴ�.
protected:

	// ������ �޽��� �� �Լ�
	virtual BOOL OnInitDialog();	
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
public:
	HICON m_hIcon;
	HZIP m_hZip;
	CExampleView* m_pView;
	CButton m_ctrlButton;
public:
	virtual void OnDestroy();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();

	BOOL AddFile(CString strFileName, CString strTargetPath);
	CString GetZipErrorMsg(ZRESULT zResult);
	static UINT ThreadFunc(LPVOID pParam);

	DECLARE_MESSAGE_MAP()
};

