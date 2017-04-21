// sdiView.cpp : implementation of the CsdiView class
//

#include "stdafx.h"
#include "sdi.h"

#include "sdiDoc.h"
#include "sdiView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CsdiView

IMPLEMENT_DYNCREATE(CsdiView, CView)

BEGIN_MESSAGE_MAP(CsdiView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CsdiView construction/destruction

CsdiView::CsdiView()
{
	// TODO: add construction code here

}

CsdiView::~CsdiView()
{
}

BOOL CsdiView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CsdiView drawing

void CsdiView::OnDraw(CDC* /*pDC*/)
{
	CsdiDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CsdiView printing

BOOL CsdiView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CsdiView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CsdiView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CsdiView diagnostics

#ifdef _DEBUG
void CsdiView::AssertValid() const
{
	CView::AssertValid();
}

void CsdiView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CsdiDoc* CsdiView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CsdiDoc)));
	return (CsdiDoc*)m_pDocument;
}
#endif //_DEBUG


// CsdiView message handlers
