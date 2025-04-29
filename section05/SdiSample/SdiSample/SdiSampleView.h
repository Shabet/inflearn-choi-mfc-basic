
// SdiSampleView.h : interface of the CSdiSampleView class
//

#pragma once


class CSdiSampleView : public CView
{
protected: // create from serialization only
	CSdiSampleView() noexcept;
	DECLARE_DYNCREATE(CSdiSampleView)

// Attributes
public:
	CSdiSampleDoc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implementation
public:
	virtual ~CSdiSampleView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in SdiSampleView.cpp
inline CSdiSampleDoc* CSdiSampleView::GetDocument() const
   { return reinterpret_cast<CSdiSampleDoc*>(m_pDocument); }
#endif

