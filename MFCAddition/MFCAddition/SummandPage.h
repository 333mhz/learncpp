#pragma once


// CSummandPage 对话框

class CSummandPage : public CPropertyPage
{
	DECLARE_DYNAMIC(CSummandPage)

public:
	CSummandPage();
	virtual ~CSummandPage();

// 对话框数据
	enum { IDD = IDD_SUMMAND_PAGE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnSetActive();
};
