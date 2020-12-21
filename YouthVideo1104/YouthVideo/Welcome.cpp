// Welcome.cpp : 实现文件
//

#include "stdafx.h"
#include "YouthVideo.h"
#include "Welcome.h"


// CWelcome

IMPLEMENT_DYNAMIC(CWelcome, CWnd)

CWelcome::CWelcome()
{

}

CWelcome::~CWelcome()
{
}


BEGIN_MESSAGE_MAP(CWelcome, CWnd)
	ON_WM_PAINT()
	ON_WM_TIMER()
END_MESSAGE_MAP()



// CWelcome 消息处理程序


void CWelcome::Create(UINT nBitmapID)   
{   
	m_bitmap.LoadBitmap(nBitmapID);   
	BITMAP bitmap;   
	m_bitmap.GetBitmap(&bitmap);   
	//CreateEx(0,AfxRegisterWndClass(0),"",WS_POPUP|WS_VISIBLE|WS_BORDER,0,0,bitmap.bmWidth,bitmap.bmHeight,NULL,0);   
	CreateEx(0,   
		AfxRegisterWndClass(0, AfxGetApp()->LoadStandardCursor(IDC_ARROW)),   
		NULL, WS_POPUP | WS_VISIBLE, 0, 0, bitmap.bmWidth, bitmap.bmHeight, NULL , NULL);   
}   

void CWelcome::OnPaint()
{
	CPaintDC dc(this); 
	BITMAP bitmap;
	m_bitmap.GetBitmap(&bitmap);
	CDC dcComp;
	dcComp.CreateCompatibleDC(&dc);
	dcComp.SelectObject(&m_bitmap);
	dc.BitBlt(0,0,bitmap.bmWidth,bitmap.bmHeight,&dcComp,0,0,SRCCOPY);
}


void CWelcome::OnTimer(UINT_PTR nIDEvent)
{
	DestroyWindow();
	//CWnd::OnTimer(nIDEvent);
}
