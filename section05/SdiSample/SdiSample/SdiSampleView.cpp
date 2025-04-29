
// SdiSampleView.cpp : implementation of the CSdiSampleView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "SdiSample.h"
#endif

#include "SdiSampleDoc.h"
#include "SdiSampleView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSdiSampleView

IMPLEMENT_DYNCREATE(CSdiSampleView, CView)

BEGIN_MESSAGE_MAP(CSdiSampleView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CSdiSampleView construction/destruction

CSdiSampleView::CSdiSampleView() noexcept
{
	// TODO: add construction code here

}

CSdiSampleView::~CSdiSampleView()
{
}

BOOL CSdiSampleView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CSdiSampleView drawing

void CSdiSampleView::OnDraw(CDC* /*pDC*/)
{
	CSdiSampleDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CSdiSampleView printing

BOOL CSdiSampleView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CSdiSampleView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CSdiSampleView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CSdiSampleView diagnostics

#ifdef _DEBUG
void CSdiSampleView::AssertValid() const
{
	CView::AssertValid();
}

void CSdiSampleView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CSdiSampleDoc* CSdiSampleView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSdiSampleDoc)));
	return (CSdiSampleDoc*)m_pDocument;
}
#endif //_DEBUG


// CSdiSampleView message handlers
