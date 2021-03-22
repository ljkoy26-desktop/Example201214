#pragma once
#include "afxwin.h"
#include "ExampleView.h"

class CTestObject
{
public:
	BOOL m_bOpen;
};

class CExampleMFCDlg : public CDialogEx
{
public:
	CExampleMFCDlg(CWnd* pParent = NULL);

#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_EXAMPLEMFC_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);


protected:
	virtual BOOL OnInitDialog();	
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();

protected:	
	HICON m_hIcon;
	CExampleView* m_pView;
	CButton m_ctrlButton;
public:
	virtual void OnDestroy();

	bool GetCurrentLogonUserName(/*[out]*/ LPTSTR& lpszAccountName, /*[out]*/ LPTSTR& lpszReferencedDomainName);
	static UINT ThreadFunc(LPVOID pParam);

	DECLARE_MESSAGE_MAP()
	afx_msg void OnBnClickedButtonCArrayTest();
	afx_msg void OnBnClickedButtonFilePathOutput();
	afx_msg void OnBnClickedButtonThreadTest();
	afx_msg void OnBnClickedButtonZip();
	afx_msg void OnBnClickedButtonSmartPointer();
	afx_msg void OnBnClickedButtonLamdaExpr();
	afx_msg void OnBnClickedButtonBinding();
	afx_msg void OnBnClickedButtonCreateDump();
};

