
// CtrlSampleView.cpp: CCtrlSampleView 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "CtrlSample.h"
#endif

#include "CtrlSampleDoc.h"
#include "CtrlSampleView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#include "resource.h"

// CCtrlSampleView

IMPLEMENT_DYNCREATE(CCtrlSampleView, CFormView)

BEGIN_MESSAGE_MAP(CCtrlSampleView, CFormView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CFormView::OnFilePrintPreview)
	ON_BN_CLICKED(IDC_BTN_ADD, &CCtrlSampleView::OnBnClickedBtnAdd)
	ON_BN_CLICKED(IDC_CHECK_TRIM, &CCtrlSampleView::OnBnClickedCheckTrim)
	ON_LBN_SELCHANGE(IDC_LIST_USERNAME, &CCtrlSampleView::OnLbnSelchangeListUsername)
	ON_BN_CLICKED(IDC_BTN_INPUT, &CCtrlSampleView::OnBnClickedBtnInput)
	ON_WM_SIZE()
END_MESSAGE_MAP()

// CCtrlSampleView 생성/소멸

CCtrlSampleView::CCtrlSampleView() noexcept
	: CFormView(IDD_CTRLSAMPLE_FORM)
	, m_strData(_T(""))
	, m_bTrim(FALSE)
	, m_nUpdate(0)
	, m_strInput(_T(""))
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CCtrlSampleView::~CCtrlSampleView()
{
}

void CCtrlSampleView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_DATA, m_strData);
	DDX_Check(pDX, IDC_CHECK_TRIM, m_bTrim);
	DDX_Radio(pDX, IDC_RADIO_UPDATE, m_nUpdate);
	DDX_Control(pDX, IDC_LIST_USERNAME, m_wndList);
	DDX_Text(pDX, IDC_STATIC_SELECTED, m_strSelected);
	DDX_CBString(pDX, IDC_COMBO_INPUT, m_strInput);
	DDX_Control(pDX, IDC_COMBO_INPUT, m_wndInput);
	DDX_Control(pDX, IDC_BTN_INPUT, m_btnInput);
}

BOOL CCtrlSampleView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CFormView::PreCreateWindow(cs);
}

void CCtrlSampleView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

	//AfxMessageBox(_T("OnInitialUpdate()"));
	m_wndList.AddString(_T("nullnull"));
	m_wndList.AddString(_T("ho-sung"));
	m_wndList.AddString(_T("Hong"));
}


// CCtrlSampleView 인쇄

BOOL CCtrlSampleView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CCtrlSampleView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CCtrlSampleView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}

void CCtrlSampleView::OnPrint(CDC* pDC, CPrintInfo* /*pInfo*/)
{
	// TODO: 여기에 사용자 지정 인쇄 코드를 추가합니다.
}


// CCtrlSampleView 진단

#ifdef _DEBUG
void CCtrlSampleView::AssertValid() const
{
	CFormView::AssertValid();
}

void CCtrlSampleView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CCtrlSampleDoc* CCtrlSampleView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CCtrlSampleDoc)));
	return (CCtrlSampleDoc*)m_pDocument;
}
#endif //_DEBUG


// CCtrlSampleView 메시지 처리기


void CCtrlSampleView::OnBnClickedBtnAdd()
{
	UpdateData(TRUE);

	if (m_bTrim)
		m_strData.Trim();

	CString tmp;
	tmp.Format(_T("Length: %d, %s"),
		m_strData.GetLength(), m_strData);

	switch (m_nUpdate)
	{
	case 0:
		tmp += _T("\n업데이트 하지 않음");
		break;

	case 1:
		tmp += _T("\n수동 업데이트");
		break;

	case 2:
		tmp += _T("\n자동 업데이트");
		break;
	}

	AfxMessageBox(tmp);
}


void CCtrlSampleView::OnBnClickedCheckTrim()
{
	//AfxMessageBox(_T("OnBnClickedCheckTrim()"));
}


void CCtrlSampleView::OnLbnSelchangeListUsername()
{
	int index = m_wndList.GetCurSel();
	if (index >= 0)
	{
		m_wndList.GetText(index, m_strSelected);
		UpdateData(FALSE);
	}
}


void CCtrlSampleView::OnBnClickedBtnInput()
{
	UpdateData(TRUE);
	m_wndInput.AddString(m_strInput);
	m_wndList.AddString(m_strInput);
}




void CCtrlSampleView::OnSize(UINT nType, int cx, int cy)
{
	CFormView::OnSize(nType, cx, cy);

	if (m_wndList.GetSafeHwnd() == NULL)
		return;
	m_wndList.MoveWindow(10, 300, cx - 10, 150);

	if (m_btnInput.GetSafeHwnd() == NULL)
		return;
	m_btnInput.MoveWindow(cx - 170, 250, 150, 30);
}
