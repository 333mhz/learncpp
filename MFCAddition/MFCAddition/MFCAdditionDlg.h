
// MFCAdditionDlg.h : 头文件
//

#pragma once
#include "ConfirmDlg.h"
#include "SumSheet.h"

// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

	// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

// CMFCAdditionDlg 对话框
class CMFCAdditionDlg : public CDialogEx
{
// 构造
public:
	CMFCAdditionDlg(CWnd* pParent = NULL);	// 标准构造函数
	~CMFCAdditionDlg();
// 对话框数据
	enum { IDD = IDD_MFCADDITION_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

	ConfirmDlg *m_cdlg;
public:
	afx_msg void OnBnClickedAdd();

private:
	double m_editSummand;
	double m_editAddend;
	double m_editSum;
public:
	afx_msg void OnBnClickedInstructButton();
};
