#pragma once


// CSummandPage �Ի���

class CSummandPage : public CPropertyPage
{
	DECLARE_DYNAMIC(CSummandPage)

public:
	CSummandPage();
	virtual ~CSummandPage();

// �Ի�������
	enum { IDD = IDD_SUMMAND_PAGE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnSetActive();
};
