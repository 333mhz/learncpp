#pragma once


// CAddendPage 对话框

class CAddendPage : public CPropertyPage
{
	DECLARE_DYNAMIC(CAddendPage)

public:
	CAddendPage();
	virtual ~CAddendPage();

// 对话框数据
	enum { IDD = IDD_ADDEND_PAGE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnSetActive();
};
