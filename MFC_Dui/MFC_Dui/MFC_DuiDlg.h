
// MFC_DuiDlg.h : ͷ�ļ�
//

#pragma once

#include "Dui_Dlg.h"

// CMFC_DuiDlg �Ի���
class CMFC_DuiDlg : public CDialogEx
{
// ����
public:
	CMFC_DuiDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_MFC_DUI_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

	CDuiFrameWndX m_duiFrame;
};
