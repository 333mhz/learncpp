#pragma once


// ConfirmDlg 对话框

class ConfirmDlg : public CDialogEx
{
	DECLARE_DYNAMIC(ConfirmDlg)

public:
	ConfirmDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~ConfirmDlg();

// 对话框数据
	enum { IDD = IDD_CONFIRM_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
