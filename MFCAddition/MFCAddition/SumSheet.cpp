// SumSheet.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCAddition.h"
#include "SumSheet.h"


// CSumSheet

IMPLEMENT_DYNAMIC(CSumSheet, CPropertySheet)

CSumSheet::CSumSheet(UINT nIDCaption, CWnd* pParentWnd, UINT iSelectPage)
	:CPropertySheet(nIDCaption, pParentWnd, iSelectPage)
{
	AddPage(&m_summandPage);
	AddPage(&m_addendPage);
	AddPage(&m_sumPage);
}

CSumSheet::CSumSheet(LPCTSTR pszCaption, CWnd* pParentWnd, UINT iSelectPage)
	:CPropertySheet(pszCaption, pParentWnd, iSelectPage)
{
	AddPage(&m_summandPage);
	AddPage(&m_addendPage);
	AddPage(&m_sumPage);
}

CSumSheet::~CSumSheet()
{
}


BEGIN_MESSAGE_MAP(CSumSheet, CPropertySheet)
END_MESSAGE_MAP()


// CSumSheet 消息处理程序
