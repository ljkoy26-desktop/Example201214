// ExampleView.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "ExampleMFC.h"
#include "ExampleView.h"


// CExampleView

IMPLEMENT_DYNCREATE(CExampleView, CView)

CExampleView::CExampleView()
{

}

CExampleView::~CExampleView()
{
}

BEGIN_MESSAGE_MAP(CExampleView, CView)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()


// CExampleView 그리기입니다.

void CExampleView::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	// TODO: 여기에 그리기 코드를 추가합니다.
}


// CExampleView 진단입니다.

#ifdef _DEBUG
void CExampleView::AssertValid() const
{
	CView::AssertValid();
}

#ifndef _WIN32_WCE
void CExampleView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}
#endif
#endif //_DEBUG


// CExampleView 메시지 처리기입니다.
UINT CExampleView::ThreadFunc(LPVOID arg)
{
	ThreadParams *pArg = (ThreadParams*)arg;


	CDC dc;
	HDC hdc = ::GetDC(pArg->hwnd);

	dc.Attach(hdc);


	int i, x, y;
	x = 100;
	y = pArg->posY;

	CBrush brush(pArg->color);
	dc.SelectObject(&brush);

	for (i = 0; i < 100000; i++)
	{
		int inc = i / 200;
		dc.Rectangle(x, y, x + inc, y + 20);
	}
	dc.Detach();
	::ReleaseDC(pArg->hwnd, hdc);
	return 0;
}

void CExampleView::OnLButtonDown(UINT nFlags, CPoint point)
{
	CClientDC dc(this);
	dc.SelectStockObject(WHITE_PEN);
	dc.SelectStockObject(WHITE_BRUSH);

	CRect rect;
	GetClientRect(&rect);
	dc.Rectangle(&rect);


	// 첫번째 스레드 생성(정지상태로)
	arg1.hwnd = this->m_hWnd;
	arg1.posY = 10;
	arg1.color = RGB(255, 0, 0);

	// 아래 세문장도 동일한 표현으로 실행됩니다.
	pThread1 = AfxBeginThread(ThreadFunc, &arg1, THREAD_PRIORITY_NORMAL, 0, CREATE_SUSPENDED);
	
	//pThread1 = AfxBeginThread(&ThreadFunc, &arg1, THREAD_PRIORITY_NORMAL, 0, CREATE_SUSPENDED);
	//pThread1 = AfxBeginThread(&CExampleView::ThreadFunc, &arg1, THREAD_PRIORITY_NORMAL, 0, CREATE_SUSPENDED);
	//pThread1 = AfxBeginThread(CExampleView::ThreadFunc, &arg1, THREAD_PRIORITY_NORMAL, 0, CREATE_SUSPENDED);

	// 두번째 스레드 생성(정지상태로)
	arg2.hwnd = this->m_hWnd;
	arg2.posY = 50;
	arg2.color = RGB(0, 255, 0);
	pThread2 = AfxBeginThread(ThreadFunc, &arg2, THREAD_PRIORITY_NORMAL, 0, CREATE_SUSPENDED);

	// 세번째 스레드 생성(정지상태로)
	arg3.hwnd = this->m_hWnd;
	arg3.posY = 90;
	arg3.color = RGB(0, 0, 255);
	pThread3 = AfxBeginThread(ThreadFunc, &arg3, THREAD_PRIORITY_NORMAL, 0, CREATE_SUSPENDED);

	pThread1->ResumeThread();
	pThread2->ResumeThread();
	pThread3->ResumeThread();

	// 아래 부분을 주석처리 하여 우선순위를 동일하게 주면, 옥신각신 하면서 비슷한 속도로 막대기가 증가한다.
	// 근데나는 그런거 없었다.
	//pThread2->SetThreadPriority(THREAD_PRIORITY_ABOVE_NORMAL);
	CView::OnLButtonDown(nFlags, point);
}
