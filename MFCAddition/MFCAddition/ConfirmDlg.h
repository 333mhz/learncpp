#pragma once


// ConfirmDlg �Ի���

class ConfirmDlg : public CDialogEx
{
	DECLARE_DYNAMIC(ConfirmDlg)

public:
	ConfirmDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~ConfirmDlg();

// �Ի�������
	enum { IDD = IDD_CONFIRM_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
