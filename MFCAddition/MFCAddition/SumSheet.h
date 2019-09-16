#pragma once



// CSumSheet

#include "SummandPage.h"
#include "AddendPage.h"
#include "SumPage.h"

class CSumSheet : public CPropertySheet
{
	DECLARE_DYNAMIC(CSumSheet)

public:
	CSumSheet(UINT nIDCaption, CWnd* pParentWnd = NULL, UINT iSelectPage = 0);
	CSumSheet(LPCTSTR pszCaption, CWnd* pParentWnd = NULL, UINT iSelectPage = 0);
	virtual ~CSumSheet();

protected:
	DECLARE_MESSAGE_MAP()

private:
	CSummandPage    m_summandPage;
	CAddendPage     m_addendPage;
	CSumPage        m_sumPage;
};


