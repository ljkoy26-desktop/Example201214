
// ExampleMFCDlg.h : ��� ����
//

#pragma once
#include "afxwin.h"

#include "unzip.h"
#include "zip.h"

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
	HICON m_hIcon;
	HZIP m_hZip;
	// ������ �޽��� �� �Լ�
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	CButton m_ctrlButton;
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();

	CString GetZipErrorMsg(ZRESULT zResult);
	BOOL AddFile(CString strFileName, CString strTargetPath);
};

//class Data
//{
//private:
//	int width, height;
//public:
//	Data();
//	Data(int _width, int _height);
//	void setData(int _width, int _height);
//	int getWidth();
//	int getHeight();
//	void displayData();
//};
//
//
//
//class Shape
//{
//private:
////	Data elements; // �Ʒ�
//public:
//	Shape(Data elements);
//	int computeTriangle();
//	int computeRectangle();
//	void displayArea();
//};
//
