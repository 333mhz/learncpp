
// MFC_Dui.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CMFC_DuiApp:
// �йش����ʵ�֣������ MFC_Dui.cpp
//

class CMFC_DuiApp : public CWinApp
{
public:
	CMFC_DuiApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CMFC_DuiApp theApp;