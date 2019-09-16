// SumPage.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCAddition.h"
#include "SumPage.h"
#include "afxdialogex.h"


// CSumPage 对话框

IMPLEMENT_DYNAMIC(CSumPage, CPropertyPage)

CSumPage::CSumPage()
	: CPropertyPage(CSumPage::IDD)
{

}

CSumPage::~CSumPage()
{
}

void CSumPage::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CSumPage, CPropertyPage)
END_MESSAGE_MAP()


// CSumPage 消息处理程序


//BOOL CSumPage::OnSetActive()
//{
//	// TODO:  在此添加专用代码和/或调用基类
//
//	// 获得父窗口，即属性表CPropertySheet类   
//	CPropertySheet* psheet = (CPropertySheet*)GetParent();
//	//设置属性表只有“完成”按钮   
//	psheet->SetFinishText(_T("完成"));
//	return CPropertyPage::OnSetActive();
//}

//BOOL CSumPage::OnWizardFinish()
//{
//	// TODO: Add your specialized code here and/or call the base class  
//
//	// 提示向导完成   
//	MessageBox(_T("使用说明向导已阅读完！"));
//
//	return CPropertyPage::OnWizardFinish();
//}