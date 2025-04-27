// CDlgML.cpp: 구현 파일
//

#include "pch.h"
#include "DlgSample.h"
#include "afxdialogex.h"
#include "CDlgML.h"


// CDlgML 대화 상자

IMPLEMENT_DYNAMIC(CDlgML, CDialog)

CDlgML::CDlgML(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_MODELESS, pParent)
{

}

CDlgML::~CDlgML()
{
}

void CDlgML::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlgML, CDialog)
	ON_WM_NCDESTROY()
END_MESSAGE_MAP()


// CDlgML 메시지 처리기


void CDlgML::OnNcDestroy()
{
	//AfxMessageBox(_T("OnNcDestroy()"));
	CDialog::OnNcDestroy();
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
}


void CDlgML::PostNcDestroy()
{
	AfxMessageBox(_T("PostNcDestroy()"));
	delete this;
	//CDialog::PostNcDestroy();
}
