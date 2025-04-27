
// ImgSampleView.cpp: CImgSampleView 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "ImgSample.h"
#endif

#include "ImgSampleDoc.h"
#include "ImgSampleView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#include "resource.h"


// CImgSampleView

IMPLEMENT_DYNCREATE(CImgSampleView, CView)

BEGIN_MESSAGE_MAP(CImgSampleView, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_PAINT()
END_MESSAGE_MAP()

// CImgSampleView 생성/소멸

CImgSampleView::CImgSampleView() noexcept
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CImgSampleView::~CImgSampleView()
{
}

BOOL CImgSampleView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CImgSampleView 그리기

void CImgSampleView::OnDraw(CDC* /*pDC*/)
{
	CImgSampleDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}


// CImgSampleView 인쇄

BOOL CImgSampleView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CImgSampleView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CImgSampleView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// CImgSampleView 진단

#ifdef _DEBUG
void CImgSampleView::AssertValid() const
{
	CView::AssertValid();
}

void CImgSampleView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CImgSampleDoc* CImgSampleView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CImgSampleDoc)));
	return (CImgSampleDoc*)m_pDocument;
}
#endif //_DEBUG


// CImgSampleView 메시지 처리기


void CImgSampleView::OnPaint()
{
	CPaintDC dc(this);

	CImage img;
	img.Load(_T("res//nullnull.jpg"));
	//img.LoadFromResource( AfxGetApp()->m_hInstance, IDR_JPG1);
	img.BitBlt(dc.m_hDC, 0, 0);

	CImageList list;
	list.Create(128, 128, ILC_COLOR32, 3, 0);
	list.Add(AfxGetApp()->LoadIcon(IDI_ICON2));
	list.Add(AfxGetApp()->LoadIcon(IDR_MAINFRAME));

	list.Draw(&dc, 0, CPoint(0, 0), ILD_TRANSPARENT);
	list.Draw(&dc, 1, CPoint(150, 0), ILD_TRANSPARENT);
}
