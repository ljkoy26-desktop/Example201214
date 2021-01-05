// ExampleView.cpp : ���� �����Դϴ�.
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


// CExampleView �׸����Դϴ�.

void CExampleView::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	// TODO: ���⿡ �׸��� �ڵ带 �߰��մϴ�.
}


// CExampleView �����Դϴ�.

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


// CExampleView �޽��� ó�����Դϴ�.
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


	// ù��° ������ ����(�������·�)
	arg1.hwnd = this->m_hWnd;
	arg1.posY = 10;
	arg1.color = RGB(255, 0, 0);

	// �Ʒ� �����嵵 ������ ǥ������ ����˴ϴ�.
	pThread1 = AfxBeginThread(ThreadFunc, &arg1, THREAD_PRIORITY_NORMAL, 0, CREATE_SUSPENDED);
	
	//pThread1 = AfxBeginThread(&ThreadFunc, &arg1, THREAD_PRIORITY_NORMAL, 0, CREATE_SUSPENDED);
	//pThread1 = AfxBeginThread(&CExampleView::ThreadFunc, &arg1, THREAD_PRIORITY_NORMAL, 0, CREATE_SUSPENDED);
	//pThread1 = AfxBeginThread(CExampleView::ThreadFunc, &arg1, THREAD_PRIORITY_NORMAL, 0, CREATE_SUSPENDED);

	// �ι�° ������ ����(�������·�)
	arg2.hwnd = this->m_hWnd;
	arg2.posY = 50;
	arg2.color = RGB(0, 255, 0);
	pThread2 = AfxBeginThread(ThreadFunc, &arg2, THREAD_PRIORITY_NORMAL, 0, CREATE_SUSPENDED);

	// ����° ������ ����(�������·�)
	arg3.hwnd = this->m_hWnd;
	arg3.posY = 90;
	arg3.color = RGB(0, 0, 255);
	pThread3 = AfxBeginThread(ThreadFunc, &arg3, THREAD_PRIORITY_NORMAL, 0, CREATE_SUSPENDED);

	pThread1->ResumeThread();
	pThread2->ResumeThread();
	pThread3->ResumeThread();

	// �Ʒ� �κ��� �ּ�ó�� �Ͽ� �켱������ �����ϰ� �ָ�, ���Ű��� �ϸ鼭 ����� �ӵ��� ����Ⱑ �����Ѵ�.
	// �ٵ����� �׷��� ������.
	//pThread2->SetThreadPriority(THREAD_PRIORITY_ABOVE_NORMAL);
	CView::OnLButtonDown(nFlags, point);
}
