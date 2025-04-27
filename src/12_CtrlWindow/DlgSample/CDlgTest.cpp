// CDlgTest.cpp: 구현 파일
//

#include "pch.h"
#include "DlgSample.h"
#include "afxdialogex.h"
#include "CDlgTest.h"


// CDlgTest 대화 상자

IMPLEMENT_DYNAMIC(CDlgTest, CDialog)

CDlgTest::CDlgTest(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_TEST, pParent)
	, m_strName(_T(""))
	, m_strPwd(_T(""))
	, m_nAge(0)
{

}

CDlgTest::~CDlgTest()
{
}

void CDlgTest::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_NAME, m_strName);
	DDV_MaxChars(pDX, m_strName, 10);
	DDX_Text(pDX, IDC_EDIT_PWD, m_strPwd);
	DDX_Text(pDX, IDC_EDIT_AGE, m_nAge);
	DDV_MinMaxInt(pDX, m_nAge, 0, 999);
	DDX_Text(pDX, IDC_EDIT_READONLY, m_strTest);
}


BEGIN_MESSAGE_MAP(CDlgTest, CDialog)
	ON_BN_CLICKED(IDOK, &CDlgTest::OnBnClickedOk)
	ON_EN_SETFOCUS(IDC_EDIT_NAME, &CDlgTest::OnEnSetfocusEditName)
	ON_EN_KILLFOCUS(IDC_EDIT_NAME, &CDlgTest::OnEnKillfocusEditName)
END_MESSAGE_MAP()


// CDlgTest 메시지 처리기


void CDlgTest::OnBnClickedOk()
{
	if(UpdateData(TRUE))
		CDialog::OnOK();
}


BOOL CDlgTest::OnInitDialog()
{
	CDialog::OnInitDialog();

	UpdateData(FALSE);
	return TRUE;
}



void CDlgTest::OnEnSetfocusEditName()
{
	m_strTest = _T("이름을 10자 이하로 입력하세요.");
	UpdateData(FALSE);
}


void CDlgTest::OnEnKillfocusEditName()
{
	m_strTest = _T("");
	UpdateData(FALSE);
}
