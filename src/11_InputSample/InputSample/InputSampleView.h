
// InputSampleView.h: CInputSampleView 클래스의 인터페이스
//

#pragma once


class CInputSampleView : public CView
{
protected: // serialization에서만 만들어집니다.
	CInputSampleView() noexcept;
	DECLARE_DYNCREATE(CInputSampleView)

// 특성입니다.
public:
	CInputSampleDoc* GetDocument() const;

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
	virtual ~CInputSampleView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	char m_char = 0;
	CPoint m_ptMove;

	CRect m_rtIcon = CRect(10, 100, 110, 200);
	BOOL m_bDrag = FALSE;
	CSize m_offset;

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnPaint();
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg BOOL OnMouseWheel(UINT nFlags, short zDelta, CPoint pt);
};

#ifndef _DEBUG  // InputSampleView.cpp의 디버그 버전
inline CInputSampleDoc* CInputSampleView::GetDocument() const
   { return reinterpret_cast<CInputSampleDoc*>(m_pDocument); }
#endif

