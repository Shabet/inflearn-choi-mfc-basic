
// MenuSampleView.h: CMenuSampleView 클래스의 인터페이스
//

#pragma once


class CMenuSampleView : public CView
{
protected: // serialization에서만 만들어집니다.
	CMenuSampleView() noexcept;
	DECLARE_DYNCREATE(CMenuSampleView)

// 특성입니다.
public:
	CMenuSampleDoc* GetDocument() const;

// 작업입니다.
public:

// 재정의입니다.
public:
	virtual void OnDraw(CDC* pDC);  // 이 뷰를 그리기 위해 재정의되었습니다.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 구현입니다.
public:
	virtual ~CMenuSampleView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnTestStart();
	afx_msg void OnTestStop();
	afx_msg void OnTestDup();
	afx_msg void OnTestPostMessage();
	afx_msg void OnTestOption01();
	afx_msg void OnUpdateTestOption01(CCmdUI* pCmdUI);
	afx_msg void OnUpdateTestStart(CCmdUI* pCmdUI);
	afx_msg void OnUpdateTestStop(CCmdUI* pCmdUI);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnPopupTest02();
};

#ifndef _DEBUG  // MenuSampleView.cpp의 디버그 버전
inline CMenuSampleDoc* CMenuSampleView::GetDocument() const
   { return reinterpret_cast<CMenuSampleDoc*>(m_pDocument); }
#endif

