
// ExampleMFCDlg.h : 헤더 파일
//

#pragma once
#include "afxwin.h"

#include "unzip.h"
#include "zip.h"


#include "ExampleView.h"
// CExampleMFCDlg 대화 상자
class CExampleMFCDlg : public CDialogEx
{
// 생성입니다.
public:
	CExampleMFCDlg(CWnd* pParent = NULL);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_EXAMPLEMFC_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.

		
// 구현입니다.
protected:

	// 생성된 메시지 맵 함수
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

