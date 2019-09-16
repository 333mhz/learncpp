// SummandPage.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCAddition.h"
#include "SummandPage.h"
#include "afxdialogex.h"


// CSummandPage 对话框

IMPLEMENT_DYNAMIC(CSummandPage, CPropertyPage)

CSummandPage::CSummandPage()
	: CPropertyPage(CSummandPage::IDD)
{

}

CSummandPage::~CSummandPage()
{
}

void CSummandPage::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CSummandPage, CPropertyPage)
END_MESSAGE_MAP()


// CSummandPage 消息处理程序


//BOOL CSummandPage::OnSetActive()
//{
//	// TODO:  在此添加专用代码和/或调用基类
//
//	// 获得父窗口，即属性表CPropertySheet类   
//	CPropertySheet* psheet = (CPropertySheet*)GetParent();
//	// 设置属性表只有“下一步”按钮   
//	psheet->SetWizardButtons(PSWIZB_NEXT);
//	return CPropertyPage::OnSetActive();
//}


