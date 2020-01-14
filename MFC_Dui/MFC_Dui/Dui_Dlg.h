#pragma once

#include <windows.h>
#include <objbase.h>

#include "..\\DuiLib\\UIlib.h"


#pragma comment(lib, "..\\Lib\\DuiLibA.lib")


class CDuiFrameWndX : public DuiLib::WindowImplBase
{
	DuiLib::CPaintManagerUI m_PaintManager;
public:
	virtual LPCTSTR GetWindowClassName()const { return _T("DUIMainFrame"); }
	virtual DuiLib::CDuiString GetSkinFile() { return _T("ui.xml"); }
	virtual DuiLib::CDuiString GetSkinFolder() { return _T(""); }

	virtual void Notify(DuiLib::TNotifyUI& msg)
	{
		if (msg.sType == _T("selectchanged"))
		{
			DuiLib::CDuiString    strName = msg.pSender->GetName();
			DuiLib::CTabLayoutUI* pControl = static_cast<DuiLib::CTabLayoutUI*>(m_PaintManager.FindControl(_T("tabTest")));

			if (strName == _T("OptionDemo1"))
				pControl->SelectItem(0);
			else if (strName == _T("OptionDemo2"))
				pControl->SelectItem(1);
			else if (strName == _T("OptionDemo3"))
				pControl->SelectItem(2);
		}

		__super::Notify(msg);
	}
	virtual void InitWindow()
	{
		DuiLib::CActiveXUI* pActiveXUI = static_cast<DuiLib::CActiveXUI*>(m_PaintManager.FindControl(_T("ActiveXDemo1")));
		if (pActiveXUI)
		{
			DuiLib::CProgressUI* pProgress = static_cast<DuiLib::CProgressUI*>(m_PaintManager.FindControl(_T("ProgressDemo1")));
			pProgress->SetValue(50);

			DuiLib::CSliderUI* pSlider = static_cast<DuiLib::CSliderUI*>(m_PaintManager.FindControl(_T("SliderDemo1")));
			pSlider->SetValue(50);

			DuiLib::CComboUI* pCombo = static_cast<DuiLib::CComboUI*>(m_PaintManager.FindControl(_T("ComboDemo1")));
			IWebBrowser2* pWebBrowser = NULL;

			pActiveXUI->SetDelayCreate(false);
			pActiveXUI->CreateControl(CLSID_WebBrowser);
			pActiveXUI->GetControl(IID_IWebBrowser, (void**)&pWebBrowser);

			if (pWebBrowser != NULL)
			{
				//pWebBrowser->Navigate(L"http://search.chongbuluo.com/", NULL, NULL, NULL, NULL);
				//pWebBrowser->Navigate(L"http://www.baidu.com/", NULL, NULL, NULL, NULL);

				pWebBrowser->Release();
			}

			DuiLib::CDuiString str;
			DuiLib::CListUI* pList = static_cast<DuiLib::CListUI*>(m_PaintManager.FindControl(_T("ListDemo1")));
			// 添加List列表内容，必须先Add(pListElement)，再SetText
			for (int i = 0; i < 100; i++)
			{
				DuiLib::CListTextElementUI* pListElement = new DuiLib::CListTextElementUI;
				pListElement->SetTag(i);
				pList->Add(pListElement);

				str.Format(_T("%d"), i);
				pListElement->SetText(0, str);
				pListElement->SetText(1, _T("haha"));
			}

		}
	}
};