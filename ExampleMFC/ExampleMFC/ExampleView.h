#pragma once


// CExampleView 뷰입니다.

class CExampleView : public CView
{
	DECLARE_DYNCREATE(CExampleView)

public:
	CExampleView();           // 동적 만들기에 사용되는 protected 생성자입니다.
	virtual ~CExampleView();
protected:


public:
	virtual void OnDraw(CDC* pDC);      // 이 뷰를 그리기 위해 재정의되었습니다.
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


