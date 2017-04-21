// sdiDoc.cpp : implementation of the CsdiDoc class
//

#include "stdafx.h"
#include "sdi.h"

#include "sdiDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CsdiDoc

IMPLEMENT_DYNCREATE(CsdiDoc, CDocument)

BEGIN_MESSAGE_MAP(CsdiDoc, CDocument)
END_MESSAGE_MAP()


// CsdiDoc construction/destruction

CsdiDoc::CsdiDoc()
{
	// TODO: add one-time construction code here

}

CsdiDoc::~CsdiDoc()
{
}

BOOL CsdiDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}




// CsdiDoc serialization

void CsdiDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}


// CsdiDoc diagnostics

#ifdef _DEBUG
void CsdiDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CsdiDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CsdiDoc commands
