#pragma once
#include "afxdialogex.h"


// CDlgML 대화 상자

class CDlgML : public CDialog
{
	DECLARE_DYNAMIC(CDlgML)

public:
	CDlgML(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CDlgML();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MODELESS };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnNcDestroy();
	virtual void PostNcDestroy();
};
