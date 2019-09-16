
// MFCAdditionDlg.h : ͷ�ļ�
//

#pragma once
#include "ConfirmDlg.h"
#include "SumSheet.h"

// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

	// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

// CMFCAdditionDlg �Ի���
class CMFCAdditionDlg : public CDialogEx
{
// ����
public:
	CMFCAdditionDlg(CWnd* pParent = NULL);	// ��׼���캯��
	~CMFCAdditionDlg();
// �Ի�������
	enum { IDD = IDD_MFCADDITION_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
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
