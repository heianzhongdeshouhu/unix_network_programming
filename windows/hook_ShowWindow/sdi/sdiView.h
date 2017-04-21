// sdiView.h : interface of the CsdiView class
//


#pragma once


class CsdiView : public CView
{
protected: // create from serialization only
	CsdiView();
	DECLARE_DYNCREATE(CsdiView)

// Attributes
public:
	CsdiDoc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implementation
public:
	virtual ~CsdiView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in sdiView.cpp
inline CsdiDoc* CsdiView::GetDocument() const
   { return reinterpret_cast<CsdiDoc*>(m_pDocument); }
#endif

