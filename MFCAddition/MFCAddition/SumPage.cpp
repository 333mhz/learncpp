// SumPage.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFCAddition.h"
#include "SumPage.h"
#include "afxdialogex.h"


// CSumPage �Ի���

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


// CSumPage ��Ϣ�������


//BOOL CSumPage::OnSetActive()
//{
//	// TODO:  �ڴ����ר�ô����/����û���
//
//	// ��ø����ڣ������Ա�CPropertySheet��   
//	CPropertySheet* psheet = (CPropertySheet*)GetParent();
//	//�������Ա�ֻ�С���ɡ���ť   
//	psheet->SetFinishText(_T("���"));
//	return CPropertyPage::OnSetActive();
//}

//BOOL CSumPage::OnWizardFinish()
//{
//	// TODO: Add your specialized code here and/or call the base class  
//
//	// ��ʾ�����   
//	MessageBox(_T("ʹ��˵�������Ķ��꣡"));
//
//	return CPropertyPage::OnWizardFinish();
//}