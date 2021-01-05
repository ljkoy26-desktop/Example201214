#pragma once


// CExampleView ���Դϴ�.

class CExampleView : public CView
{
	DECLARE_DYNCREATE(CExampleView)

public:
	CExampleView();           // ���� ����⿡ ���Ǵ� protected �������Դϴ�.
	virtual ~CExampleView();
protected:


public:
	virtual void OnDraw(CDC* pDC);      // �� �並 �׸��� ���� �����ǵǾ����ϴ�.
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif




public:
	struct ThreadParams
	{
		COLORREF color;
		HWND hwnd;
		int posY;
	};

	CWinThread* pThread1, *pThread2, *pThread3;
	ThreadParams arg1, arg2, arg3;


	static UINT ThreadFunc(LPVOID pParam);
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};


