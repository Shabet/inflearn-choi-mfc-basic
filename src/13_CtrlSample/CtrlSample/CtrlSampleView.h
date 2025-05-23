﻿
// CtrlSampleView.h: CCtrlSampleView 클래스의 인터페이스
//

#pragma once


class CCtrlSampleView : public CFormView
{
protected: // serialization에서만 만들어집니다.
	CCtrlSampleView() noexcept;
	DECLARE_DYNCREATE(CCtrlSampleView)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_CTRLSAMPLE_FORM };
#endif

// 특성입니다.
public:
	CCtrlSampleDoc* GetDocument() const;

// 작업입니다.
public:

// 재정의입니다.
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.
	virtual void OnInitialUpdate(); // 생성 후 처음 호출되었습니다.
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnPrint(CDC* pDC, CPrintInfo* pInfo);

// 구현입니다.
public:
	virtual ~CCtrlSampleView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()
public:
	CString m_strData;
	afx_msg void OnBnClickedBtnAdd();
	BOOL m_bTrim;
	afx_msg void OnBnClickedCheckTrim();
	int m_nUpdate;
	CListBox m_wndList;
	CString m_strSelected;
	afx_msg void OnLbnSelchangeListUsername();
	CString m_strInput;
	afx_msg void OnBnClickedBtnInput();
	CComboBox m_wndInput;
	afx_msg void OnSize(UINT nType, int cx, int cy);
	CButton m_btnInput;
};

#ifndef _DEBUG  // CtrlSampleView.cpp의 디버그 버전
inline CCtrlSampleDoc* CCtrlSampleView::GetDocument() const
   { return reinterpret_cast<CCtrlSampleDoc*>(m_pDocument); }
#endif

