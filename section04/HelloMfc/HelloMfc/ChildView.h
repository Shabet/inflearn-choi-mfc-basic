
// ChildView.h: CChildView Å¬·¡½ºÀÇ ÀÎÅÍÆäÀÌ½º
//


#pragma once


// CChildView Ã¢

class CChildView : public CWnd
{
// »ý¼ºÀÔ´Ï´Ù.
public:
	CChildView();

// Æ¯¼ºÀÔ´Ï´Ù.
public:

// ÀÛ¾÷ÀÔ´Ï´Ù.
public:

// ÀçÁ¤ÀÇÀÔ´Ï´Ù.
	protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// ±¸ÇöÀÔ´Ï´Ù.
public:
	virtual ~CChildView();

	// »ý¼ºµÈ ¸Þ½ÃÁö ¸Ê ÇÔ¼ö
protected:
	afx_msg void OnPaint();
	DECLARE_MESSAGE_MAP()
};

