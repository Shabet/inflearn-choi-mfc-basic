
// MainFrm.cpp: CMainFrame Å¬·¡½ºÀÇ ±¸Çö
//

#include "pch.h"
#include "framework.h"
#include "HelloMfc.h"

#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMainFrame

IMPLEMENT_DYNAMIC(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	ON_WM_CREATE()
	ON_WM_SETFOCUS()
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // »óÅÂ ÁÙ Ç¥½Ã±â
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

// CMainFrame »ý¼º/¼Ò¸ê

CMainFrame::CMainFrame() noexcept
{
	// TODO: ¿©±â¿¡ ¸â¹ö ÃÊ±âÈ­ ÄÚµå¸¦ Ãß°¡ÇÕ´Ï´Ù.
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	// ÇÁ·¹ÀÓÀÇ Å¬¶óÀÌ¾ðÆ® ¿µ¿ªÀ» Â÷ÁöÇÏ´Â ºä¸¦ ¸¸µì´Ï´Ù.
	if (!m_wndView.Create(nullptr, nullptr, AFX_WS_DEFAULT_VIEW, CRect(0, 0, 0, 0), this, AFX_IDW_PANE_FIRST, nullptr))
	{
		TRACE0("ºä Ã¢À» ¸¸µéÁö ¸øÇß½À´Ï´Ù.\n");
		return -1;
	}

	if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP | CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_wndToolBar.LoadToolBar(IDR_MAINFRAME))
	{
		TRACE0("µµ±¸ ¸ðÀ½À» ¸¸µéÁö ¸øÇß½À´Ï´Ù.\n");
		return -1;      // ¸¸µéÁö ¸øÇß½À´Ï´Ù.
	}

	if (!m_wndStatusBar.Create(this))
	{
		TRACE0("»óÅÂ Ç¥½ÃÁÙÀ» ¸¸µéÁö ¸øÇß½À´Ï´Ù.\n");
		return -1;      // ¸¸µéÁö ¸øÇß½À´Ï´Ù.
	}
	m_wndStatusBar.SetIndicators(indicators, sizeof(indicators)/sizeof(UINT));

	// TODO: µµ±¸ ¸ðÀ½À» µµÅ·ÇÒ ¼ö ¾ø°Ô ÇÏ·Á¸é ÀÌ ¼¼ ÁÙÀ» »èÁ¦ÇÏ½Ê½Ã¿À.
	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_wndToolBar);


	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: CREATESTRUCT cs¸¦ ¼öÁ¤ÇÏ¿© ¿©±â¿¡¼­
	//  Window Å¬·¡½º ¶Ç´Â ½ºÅ¸ÀÏÀ» ¼öÁ¤ÇÕ´Ï´Ù.

	cs.dwExStyle &= ~WS_EX_CLIENTEDGE;
	cs.lpszClass = AfxRegisterWndClass(0);
	return TRUE;
}

// CMainFrame Áø´Ü

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}
#endif //_DEBUG


// CMainFrame ¸Þ½ÃÁö Ã³¸®±â

void CMainFrame::OnSetFocus(CWnd* /*pOldWnd*/)
{
	// ºä Ã¢À¸·Î Æ÷Ä¿½º¸¦ ÀÌµ¿ÇÕ´Ï´Ù.
	m_wndView.SetFocus();
}

BOOL CMainFrame::OnCmdMsg(UINT nID, int nCode, void* pExtra, AFX_CMDHANDLERINFO* pHandlerInfo)
{
	// ºä¿¡¼­ Ã¹Â° Å©·¢ÀÌ ÇØ´ç ¸í·É¿¡ ³ªÅ¸³ªµµ·Ï ÇÕ´Ï´Ù.
	if (m_wndView.OnCmdMsg(nID, nCode, pExtra, pHandlerInfo))
		return TRUE;

	// ±×·¸Áö ¾ÊÀ¸¸é ±âº» Ã³¸®ÇÕ´Ï´Ù.
	return CFrameWnd::OnCmdMsg(nID, nCode, pExtra, pHandlerInfo);
}

