
// MenuSampleView.cpp: CMenuSampleView 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "MenuSample.h"
#endif

#include "MenuSampleDoc.h"
#include "MenuSampleView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#include "resource.h"

// CMenuSampleView

IMPLEMENT_DYNCREATE(CMenuSampleView, CView)

BEGIN_MESSAGE_MAP(CMenuSampleView, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_TEST_START, &CMenuSampleView::OnTestStart)
	ON_COMMAND(ID_TEST_STOP, &CMenuSampleView::OnTestStop)
	ON_COMMAND(ID_TEST_DUP, &CMenuSampleView::OnTestDup)
	ON_COMMAND(ID_TEST_POSTMESSAGE, &CMenuSampleView::OnTestPostMessage)
	ON_COMMAND(ID_TEST_OPTION01, &CMenuSampleView::OnTestOption01)
	ON_UPDATE_COMMAND_UI(ID_TEST_OPTION01, &CMenuSampleView::OnUpdateTestOption01)
	ON_UPDATE_COMMAND_UI(ID_TEST_START, &CMenuSampleView::OnUpdateTestStart)
	ON_UPDATE_COMMAND_UI(ID_TEST_STOP, &CMenuSampleView::OnUpdateTestStop)
	ON_WM_RBUTTONDOWN()
	ON_COMMAND(ID_POPUP_TEST02, &CMenuSampleView::OnPopupTest02)
END_MESSAGE_MAP()

// CMenuSampleView 생성/소멸

CMenuSampleView::CMenuSampleView() noexcept
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CMenuSampleView::~CMenuSampleView()
{
}

BOOL CMenuSampleView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CMenuSampleView 그리기

void CMenuSampleView::OnDraw(CDC* /*pDC*/)
{
	CMenuSampleDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}


// CMenuSampleView 인쇄

BOOL CMenuSampleView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CMenuSampleView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CMenuSampleView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// CMenuSampleView 진단

#ifdef _DEBUG
void CMenuSampleView::AssertValid() const
{
	CView::AssertValid();
}

void CMenuSampleView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMenuSampleDoc* CMenuSampleView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMenuSampleDoc)));
	return (CMenuSampleDoc*)m_pDocument;
}
#endif //_DEBUG


// CMenuSampleView 메시지 처리기


void CMenuSampleView::OnTestStart()
{
	AfxMessageBox(_T("Start"));
	CAppOption::bRunning = TRUE;
}


void CMenuSampleView::OnTestStop()
{
	AfxMessageBox(_T("Stop"));
	CAppOption::bRunning = FALSE;
}


void CMenuSampleView::OnTestDup()
{
	AfxMessageBox(_T("CMenuSampleView::OnTestDup()"));
}


void CMenuSampleView::OnTestPostMessage()
{
	this->PostMessage(WM_COMMAND, ID_TEST_START);
	//::PostMessage(this->m_hWnd, WM_COMMAND, ID_TEST_START, 0);
}


void CMenuSampleView::OnTestOption01()
{
	CAppOption::bOption01 = !CAppOption::bOption01;
}

void CMenuSampleView::OnUpdateTestOption01(CCmdUI* pCmdUI)
{
	pCmdUI->SetCheck(CAppOption::bOption01);
}


void CMenuSampleView::OnUpdateTestStart(CCmdUI* pCmdUI)
{
	pCmdUI->Enable(!CAppOption::bRunning);
}


void CMenuSampleView::OnUpdateTestStop(CCmdUI* pCmdUI)
{
	pCmdUI->Enable(CAppOption::bRunning);
}


void CMenuSampleView::OnRButtonDown(UINT nFlags, CPoint point)
{
	CMenu menu;
	menu.LoadMenu(IDR_MENU_POPUP);

	CPoint ptPopup = point;
	this->ClientToScreen(&ptPopup);

	CMenu *pSubMenu = menu.GetSubMenu(0);

	//pSubMenu->EnableMenuItem(ID_POPUP_TEST01, MF_DISABLED);

	pSubMenu->TrackPopupMenu(
		TPM_LEFTBUTTON | TPM_LEFTALIGN,
		ptPopup.x, ptPopup.y,
		this);
	
	CView::OnRButtonDown(nFlags, point);
}


void CMenuSampleView::OnPopupTest02()
{
	AfxMessageBox(_T("OnPopupTest02()"));
}
