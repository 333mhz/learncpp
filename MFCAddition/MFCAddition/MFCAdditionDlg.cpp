
// MFCAdditionDlg.cpp : 实现文件
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


// CMFCAdditionDlg 对话框
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


// CMFCAdditionDlg 消息处理程序

BOOL CMFCAdditionDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
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

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	UpdateData(TRUE);
	m_editSummand = 0;
	m_editAddend = 0;
	m_editSum = 0;
	UpdateData(FALSE);
	m_cdlg = NULL;

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMFCAdditionDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
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
	// 将各控件中的数据保存到相应的变量  

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

	// 将被加数和加数的加和赋值给m_editSum   
	m_editSum = (m_editSummand + m_editAddend);

	// 根据各变量的值更新相应的控件。和的编辑框会显示m_editSum的值   
	UpdateData(FALSE);
}

void CMFCAdditionDlg::OnBnClickedInstructButton()
{
	// TODO:  在此添加控件通知处理程序代码
	CSumSheet sheet(_T(""));

	sheet.SetWizardMode();

	sheet.DoModal();
}
