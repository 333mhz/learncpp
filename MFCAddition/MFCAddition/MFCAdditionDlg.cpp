
// MFCAdditionDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFCAddition.h"
#include "MFCAdditionDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMFCAdditionDlg �Ի���
CMFCAdditionDlg::CMFCAdditionDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMFCAdditionDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

CMFCAdditionDlg::~CMFCAdditionDlg()
{
	if (m_cdlg)
	{
		delete m_cdlg;
	}
}

void CMFCAdditionDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);

	DDX_Text(pDX, IDC_SUMMAND_EDIT, m_editSummand);
	DDX_Text(pDX, IDC_ADDEND_EDIT, m_editAddend);
	DDX_Text(pDX, IDC_SUM_EDIT, m_editSum);
}



BEGIN_MESSAGE_MAP(CMFCAdditionDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_ADD, &CMFCAdditionDlg::OnBnClickedAdd)
	ON_BN_CLICKED(IDC_INSTRUCT_BUTTON, &CMFCAdditionDlg::OnBnClickedInstructButton)
END_MESSAGE_MAP()


// CMFCAdditionDlg ��Ϣ�������

BOOL CMFCAdditionDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	UpdateData(TRUE);
	m_editSummand = 0;
	m_editAddend = 0;
	m_editSum = 0;
	UpdateData(FALSE);
	m_cdlg = NULL;

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CMFCAdditionDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CMFCAdditionDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CMFCAdditionDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCAdditionDlg::OnBnClickedAdd()
{
	//INT_PTR nRes;
	//ConfirmDlg cdlg;
	//nRes = cdlg.DoModal();
	//if (IDCANCEL == nRes)
	//{
	//	return;
	//}
	// TODO: Add your control notification handler code here   
	// �����ؼ��е����ݱ��浽��Ӧ�ı���  

	if (!m_cdlg)
	{
		m_cdlg = new ConfirmDlg();
		m_cdlg->Create(IDD_CONFIRM_DIALOG, this);
	}
	m_cdlg->ShowWindow(SW_SHOW);
	//nRes = m_cdlg->DoModal();
	//if (IDCANCEL == nRes)
	//	{
	//		return;
	//	}
	UpdateData(TRUE);

	// ���������ͼ����ļӺ͸�ֵ��m_editSum   
	m_editSum = (m_editSummand + m_editAddend);

	// ���ݸ�������ֵ������Ӧ�Ŀؼ����͵ı༭�����ʾm_editSum��ֵ   
	UpdateData(FALSE);
}

void CMFCAdditionDlg::OnBnClickedInstructButton()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CSumSheet sheet(_T(""));

	sheet.SetWizardMode();

	sheet.DoModal();
}
