#pragma once


// CSumPage 对话框

class CSumPage : public CPropertyPage
{
	DECLARE_DYNAMIC(CSumPage)

public:
	CSumPage();
	virtual ~CSumPage();

// 对话框数据
	enum { IDD = IDD_SUM_PAGE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	//virtual BOOL OnSetActive();
	//virtual BOOL OnWizardFinish();
};
