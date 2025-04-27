
// BmpSampleView.cpp: CBmpSampleView 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "BmpSample.h"
#endif

#include "BmpSampleDoc.h"
#include "BmpSampleView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#include "resource.h"


// CBmpSampleView

IMPLEMENT_DYNCREATE(CBmpSampleView, CView)

BEGIN_MESSAGE_MAP(CBmpSampleView, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_PAINT()
END_MESSAGE_MAP()

// CBmpSampleView 생성/소멸

CBmpSampleView::CBmpSampleView() noexcept
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CBmpSampleView::~CBmpSampleView()
{
}

BOOL CBmpSampleView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CBmpSampleView 그리기

void CBmpSampleView::OnDraw(CDC* /*pDC*/)
{
	CBmpSampleDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}


// CBmpSampleView 인쇄

BOOL CBmpSampleView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CBmpSampleView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CBmpSampleView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// CBmpSampleView 진단

#ifdef _DEBUG
void CBmpSampleView::AssertValid() const
{
	CView::AssertValid();
}

void CBmpSampleView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CBmpSampleDoc* CBmpSampleView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CBmpSampleDoc)));
	return (CBmpSampleDoc*)m_pDocument;
}
#endif //_DEBUG


// CBmpSampleView 메시지 처리기


void CBmpSampleView::OnPaint()
{
	CPaintDC dc(this);

	CDC memdc;
	memdc.CreateCompatibleDC(&dc);

	CBitmap bmp;
	bmp.LoadBitmap(IDB_NULLNULL);
	BITMAP info = { 0 };
	bmp.GetBitmap(&info);

	CBitmap *pOldBmp = memdc.SelectObject(&bmp);

	memdc.MoveTo(100, 100);
	memdc.LineTo(200, 200);

	dc.BitBlt(0, 0, info.bmWidth, info.bmHeight,
		&memdc, 0, 0, SRCCOPY);

	//dc.MoveTo(100, 100);
	//dc.LineTo(200, 200);

	memdc.SelectObject(pOldBmp);
}
