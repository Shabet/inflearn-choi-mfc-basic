
// MapModeSampleView.cpp: CMapModeSampleView 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "MapModeSample.h"
#endif

#include "MapModeSampleDoc.h"
#include "MapModeSampleView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMapModeSampleView

IMPLEMENT_DYNCREATE(CMapModeSampleView, CView)

BEGIN_MESSAGE_MAP(CMapModeSampleView, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_PAINT()
END_MESSAGE_MAP()

// CMapModeSampleView 생성/소멸

CMapModeSampleView::CMapModeSampleView() noexcept
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CMapModeSampleView::~CMapModeSampleView()
{
}

BOOL CMapModeSampleView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CMapModeSampleView 그리기

void CMapModeSampleView::OnDraw(CDC* /*pDC*/)
{
	CMapModeSampleDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}


// CMapModeSampleView 인쇄

BOOL CMapModeSampleView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CMapModeSampleView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CMapModeSampleView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// CMapModeSampleView 진단

#ifdef _DEBUG
void CMapModeSampleView::AssertValid() const
{
	CView::AssertValid();
}

void CMapModeSampleView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMapModeSampleDoc* CMapModeSampleView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMapModeSampleDoc)));
	return (CMapModeSampleDoc*)m_pDocument;
}
#endif //_DEBUG


// CMapModeSampleView 메시지 처리기


void CMapModeSampleView::OnPaint()
{
	CPaintDC dc(this);
	CRect rect;
	GetClientRect(&rect);

	dc.SetMapMode(MM_ANISOTROPIC);
	//논리적 크기
	dc.SetWindowExt(1024, 768);
	
	//물리적 크기
	//dc.SetViewportExt(1024, 720);
	//dc.SetViewportExt(1024 / 2, 720 / 2);
	//dc.SetViewportExt(1024 * 2, 720);
	dc.SetViewportExt(rect.Width(), rect.Height()); //

	//기준점 변경
	dc.SetViewportOrg(100, 100);

	CImageList list;
	list.Create(128, 128, ILC_COLOR32, 1, 0);
	list.Add(AfxGetApp()->LoadIcon(IDR_MAINFRAME));
	list.Draw(&dc, 0, CPoint(50, 50), ILD_TRANSPARENT);


	CPoint ptTest(10, 10);
	dc.LPtoDP(&ptTest);

	CString tmp;
	tmp.Format(_T("X:%d, Y:%d"), ptTest.x, ptTest.y);
	dc.TextOut(30, 10, tmp);

	CPen penBlack(PS_SOLID, 3, RGB(0, 0, 0));
	dc.SelectObject(&penBlack);
	dc.MoveTo(-1024, 0);
	dc.LineTo(1024, 0);
	dc.MoveTo(0, -768);
	dc.LineTo(0, 768);

	CPen penGray(PS_SOLID, 1, RGB(192, 192, 192));
	dc.SelectObject(&penGray);
	dc.MoveTo(-1024 / 2, 10);
	dc.LineTo(1024 / 2, 10);
	dc.MoveTo(10, -768 / 2);
	dc.LineTo(10, 768 / 2);

	CPen pen(PS_SOLID, 5, RGB(192, 0, 0));
	dc.SelectObject(&pen);
	dc.MoveTo(0, 0);
	dc.LineTo(200, 200);
}
