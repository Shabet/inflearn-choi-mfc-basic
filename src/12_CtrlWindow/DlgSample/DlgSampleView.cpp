
// DlgSampleView.cpp: CDlgSampleView 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "DlgSample.h"
#endif

#include "DlgSampleDoc.h"
#include "DlgSampleView.h"

#include "CDlgTest.h"
#include "CDlgML.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDlgSampleView

IMPLEMENT_DYNCREATE(CDlgSampleView, CView)

BEGIN_MESSAGE_MAP(CDlgSampleView, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_TEST_TEST, &CDlgSampleView::OnTestTest)
	ON_COMMAND(ID_TEST_MODELESS, &CDlgSampleView::OnTestModeless)
END_MESSAGE_MAP()

// CDlgSampleView 생성/소멸

CDlgSampleView::CDlgSampleView() noexcept
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CDlgSampleView::~CDlgSampleView()
{
}

BOOL CDlgSampleView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CDlgSampleView 그리기

void CDlgSampleView::OnDraw(CDC* /*pDC*/)
{
	CDlgSampleDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}


// CDlgSampleView 인쇄

BOOL CDlgSampleView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CDlgSampleView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CDlgSampleView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// CDlgSampleView 진단

#ifdef _DEBUG
void CDlgSampleView::AssertValid() const
{
	CView::AssertValid();
}

void CDlgSampleView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CDlgSampleDoc* CDlgSampleView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDlgSampleDoc)));
	return (CDlgSampleDoc*)m_pDocument;
}
#endif //_DEBUG


// CDlgSampleView 메시지 처리기


void CDlgSampleView::OnTestTest()
{
	CDlgTest dlg;
	if (dlg.DoModal() == IDOK)
		;
	else
		;
}


void CDlgSampleView::OnTestModeless()
{
	//static CDlgML dlg;

	//if(dlg.GetSafeHwnd() == NULL)
	//	dlg.Create(IDD_MODELESS);

	//dlg.ShowWindow(SW_SHOW);

	CDlgML* pDlg = new CDlgML;
	pDlg->Create(IDD_MODELESS);
	pDlg->ShowWindow(SW_SHOW);
}
