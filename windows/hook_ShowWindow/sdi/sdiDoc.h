// sdiDoc.h : interface of the CsdiDoc class
//


#pragma once


class CsdiDoc : public CDocument
{
protected: // create from serialization only
	CsdiDoc();
	DECLARE_DYNCREATE(CsdiDoc)

// Attributes
public:

// Operations
public:

// Overrides
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);

// Implementation
public:
	virtual ~CsdiDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
};


