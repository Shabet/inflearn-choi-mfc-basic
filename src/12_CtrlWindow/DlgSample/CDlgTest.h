#pragma once
#include "afxdialogex.h"


// CDlgTest 대화 상자

class CDlgTest : public CDialog
{
	DECLARE_DYNAMIC(CDlgTest)

public:
	CDlgTest(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CDlgTest();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TEST };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	virtual BOOL OnInitDialog();
	CString m_strName;
	CString m_strPwd;
	int m_nAge = 0;
	CString m_strTest = _T("Test string");
	afx_msg void OnEnSetfocusEditName();
	afx_msg void OnEnKillfocusEditName();
};
