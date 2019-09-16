// ConfirmDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCAddition.h"
#include "ConfirmDlg.h"
#include "afxdialogex.h"


// ConfirmDlg 对话框

IMPLEMENT_DYNAMIC(ConfirmDlg, CDialogEx)

ConfirmDlg::ConfirmDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(ConfirmDlg::IDD, pParent)
{

}

ConfirmDlg::~ConfirmDlg()
{

}

void ConfirmDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(ConfirmDlg, CDialogEx)
END_MESSAGE_MAP()


// ConfirmDlg 消息处理程序
