#pragma once


// CSumPage �Ի���

class CSumPage : public CPropertyPage
{
	DECLARE_DYNAMIC(CSumPage)

public:
	CSumPage();
	virtual ~CSumPage();

// �Ի�������
	enum { IDD = IDD_SUM_PAGE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	//virtual BOOL OnSetActive();
	//virtual BOOL OnWizardFinish();
};
