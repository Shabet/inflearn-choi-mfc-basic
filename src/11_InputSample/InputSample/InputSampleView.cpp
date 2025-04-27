
// InputSampleView.cpp: CInputSampleView 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "InputSample.h"
#endif

#include "InputSampleDoc.h"
#include "InputSampleView.h"
#include "BufferDC.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CInputSampleView

IMPLEMENT_DYNCREATE(CInputSampleView, CView)

BEGIN_MESSAGE_MAP(CInputSampleView, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_KEYDOWN()
	ON_WM_CHAR()
	ON_WM_PAINT()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_ERASEBKGND()
	ON_WM_MOUSEWHEEL()
END_MESSAGE_MAP()

// CInputSampleView 생성/소멸

CInputSampleView::CInputSampleView() noexcept
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CInputSampleView::~CInputSampleView()
{
}

BOOL CInputSampleView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CInputSampleView 그리기

void CInputSampleView::OnDraw(CDC* /*pDC*/)
{
	CInputSampleDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}


// CInputSampleView 인쇄

BOOL CInputSampleView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CInputSampleView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CInputSampleView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// CInputSampleView 진단

#ifdef _DEBUG
void CInputSampleView::AssertValid() const
{
	CView::AssertValid();
}

void CInputSampleView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CInputSampleDoc* CInputSampleView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CInputSampleDoc)));
	return (CInputSampleDoc*)m_pDocument;
}
#endif //_DEBUG


// CInputSampleView 메시지 처리기


void CInputSampleView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	//OutputDebugString(_T("OnKeyDown()\n"));
	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}


void CInputSampleView::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	CClientDC dc(this);
	m_char = nChar;
	/*CString tmp;
	tmp.Format(_T("%c"), nChar);
	dc.TextOut(10, 10, tmp);*/
	RedrawWindow();

	CView::OnChar(nChar, nRepCnt, nFlags);
}


void CInputSampleView::OnPaint()
{
	//CPaintDC dc(this);
	CBufferDC dc(this);
	CRect rect;
	GetClientRect(&rect);
	dc.FillSolidRect(&rect, RGB(255, 255, 255));

	//Key, Mouse info
	dc.SetBkMode(OPAQUE);
	dc.SetBkColor(RGB(255, 255, 255));

	CString tmp;
	if (m_char != 0)
	{
		tmp.Format(_T("%c"), m_char);
		if (::GetKeyState(VK_SHIFT) & 0x8000)
			tmp += _T(" [SHIFT]");
		dc.TextOut(10, 10, tmp);
	}

	if (m_ptMove.x > 0 && m_ptMove.y > 0)
	{
		tmp.Format(_T("X:%d, Y:%d"), m_ptMove.x, m_ptMove.y);
		dc.TextOut(10, 30, tmp);
	}

	dc.FillSolidRect(&m_rtIcon, RGB(192, 192, 192));
	CImageList list;
	list.Create(128, 128, ILC_COLOR32, 1, 0);
	list.Add(AfxGetApp()->LoadIcon(IDR_MAINFRAME));
	list.Draw(&dc, 0, m_rtIcon.TopLeft(), ILD_TRANSPARENT);
}

void CInputSampleView::OnMouseMove(UINT nFlags, CPoint point)
{
	m_ptMove = point;

	if (m_bDrag)
	{
		m_rtIcon.TopLeft() = point - m_offset;
		m_rtIcon.BottomRight() = m_rtIcon.TopLeft() + CSize(100, 100);
	}

	RedrawWindow();
	CView::OnMouseMove(nFlags, point);
}



void CInputSampleView::OnLButtonDown(UINT nFlags, CPoint point)
{
	if (m_rtIcon.PtInRect(point))
	{
		m_bDrag = TRUE;
		m_offset = point - m_rtIcon.TopLeft();
		//RedrawWindow();
		SetCapture();
	}
	CView::OnLButtonDown(nFlags, point);
}


void CInputSampleView::OnLButtonUp(UINT nFlags, CPoint point)
{
	if (m_bDrag)
	{
		m_rtIcon.TopLeft() = point - m_offset;
		m_rtIcon.BottomRight() = m_rtIcon.TopLeft() + CSize(100, 100);
		RedrawWindow();
		ReleaseCapture();
	}

	m_bDrag = FALSE;
	CView::OnLButtonUp(nFlags, point);
}


BOOL CInputSampleView::OnEraseBkgnd(CDC* pDC)
{
	return TRUE;
	//return CView::OnEraseBkgnd(pDC);
}


BOOL CInputSampleView::OnMouseWheel(UINT nFlags, short zDelta, CPoint pt)
{
	if (::GetKeyState(VK_SHIFT) & 0x8000)
		m_rtIcon.TopLeft().x += -zDelta;
	else
		m_rtIcon.TopLeft().y += -zDelta;

	m_rtIcon.BottomRight() = m_rtIcon.TopLeft() + CSize(100, 100);
	RedrawWindow();

	return CView::OnMouseWheel(nFlags, zDelta, pt);
}
