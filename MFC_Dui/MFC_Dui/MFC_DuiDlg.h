
// MFC_DuiDlg.h : 头文件
//

#pragma once

#include "Dui_Dlg.h"

// CMFC_DuiDlg 对话框
class CMFC_DuiDlg : public CDialogEx
{
// 构造
public:
	CMFC_DuiDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_MFC_DUI_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

	CDuiFrameWndX m_duiFrame;
};
