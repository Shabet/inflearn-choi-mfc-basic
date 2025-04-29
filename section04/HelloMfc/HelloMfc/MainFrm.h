
// MainFrm.h: CMainFrame Å¬·¡½ºÀÇ ÀÎÅÍÆäÀÌ½º
//

#pragma once
#include "ChildView.h"

class CMainFrame : public CFrameWnd
{
	
public:
	CMainFrame() noexcept;
protected: 
	DECLARE_DYNAMIC(CMainFrame)

// Æ¯¼ºÀÔ´Ï´Ù.
public:

// ÀÛ¾÷ÀÔ´Ï´Ù.
public:

// ÀçÁ¤ÀÇÀÔ´Ï´Ù.
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual BOOL OnCmdMsg(UINT nID, int nCode, void* pExtra, AFX_CMDHANDLERINFO* pHandlerInfo);

// ±¸ÇöÀÔ´Ï´Ù.
public:
	virtual ~CMainFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:  // ÄÁÆ®·Ñ ¸ðÀ½ÀÌ Æ÷ÇÔµÈ ¸â¹öÀÔ´Ï´Ù.
	CToolBar          m_wndToolBar;
	CStatusBar        m_wndStatusBar;
	CChildView    m_wndView;

// »ý¼ºµÈ ¸Þ½ÃÁö ¸Ê ÇÔ¼ö
protected:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSetFocus(CWnd *pOldWnd);
	DECLARE_MESSAGE_MAP()

};


