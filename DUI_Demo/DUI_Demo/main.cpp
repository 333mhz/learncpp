
#define WIN32_LEAN_AND_MEAN	
#define _CRT_SECURE_NO_DEPRECATE

#include <windows.h>
#include <objbase.h>

//#include <tchar.h>

#include "..\DuiLib\UIlib.h"
//using namespace DuiLib;

//#define _debug
#ifdef _DEBUG
#   ifdef _unicode
#       pragma comment(lib, "..\\lib\\duilib_ud.lib")
#   else
#       pragma comment(lib, "..\\lib\\duilib_d.lib")
#   endif
#else
#   ifdef _unicode
#       pragma comment(lib, "..\\lib\\duilib_u.lib")
#   else
#       pragma comment(lib, "..\\lib\\duilib_static.lib")
#   endif
#endif

// 窗口实例及消息响应部分
//class CDuiFrameWnd : public DuiLib::CWindowWnd, public DuiLib::INotifyUI
//{
//protected:
//	DuiLib::CPaintManagerUI m_pm;
//
//public:
//	CDuiFrameWnd() { };
//
//	virtual LPCTSTR GetWindowClassName() const { return _T("DUIMainFrame"); };
//
//	UINT GetClassStyle() const { return UI_CLASSSTYLE_FRAME | CS_DBLCLKS; };
//
//	void OnFinalMessage(HWND /*hWnd*/) { delete this; };
//
//	virtual void Notify(DuiLib::TNotifyUI& msg)
//	{
//		if (msg.sType == _T("click")) {
//			if (msg.pSender->GetName() == _T("btnHello")) {
//				::MessageBox(NULL, _T("Button Pressed"), _T("Button"), NULL);
//				Close();
//			}
//		}
//	}
//
//	LRESULT HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam)
//	{
//
//		if (uMsg == WM_CREATE)//启动UI绘制
//		{
//			m_pm.Init(m_hWnd);
//			
//			DuiLib::CDialogBuilder bud;
//			DuiLib::CControlUI *pRoot = bud.Create(_T("ui.xml"),(UINT)0,NULL,&m_pm);//new DuiLib::CButtonUI;
//			ASSERT(pRoot && "Fail to parse XML");
//
//			//pButton->SetText(_T("Hello_World"));
//			//pButton->SetName(_T("closebtn"));
//			//pButton->SetBkColor(0xFF00FF00);
//
//			
//			m_pm.AttachDialog(pRoot);
//			m_pm.AddNotifier(this);
//
//			return 0;
//		}
//		else if (uMsg == WM_DESTROY) //释放,资源退出
//		{
//			::PostQuitMessage(0);
//		}
//		else if (uMsg == WM_NCACTIVATE)//非激活状态去边框
//		{
//			if (!::IsIconic(m_hWnd)) 
//			{
//				return (wParam == 0) ? TRUE : FALSE;
//			}
//		}
//		else if (uMsg == WM_NCCALCSIZE)//去边框
//		{
//			return 0;
//		}
//		else if (uMsg == WM_NCPAINT)//边缘倒角
//		{
//			return 0;
//		}
//
//		LRESULT lRes = 0;
//
//		if (m_pm.MessageHandler(uMsg, wParam, lParam, lRes))
//			return lRes;
//		
//		//return CWindowWnd::HandleMessage(uMsg, wParam, lParam);
//		return __super::HandleMessage(uMsg, wParam, lParam);
//	}
//};

class CDuiFrameWndX : public DuiLib::WindowImplBase
{
	//DuiLib::CPaintManagerUI m_pm;
public:
	virtual LPCTSTR GetWindowClassName()const  { return _T("DUIMainFrame"); }
	virtual DuiLib::CDuiString GetSkinFile()   { return _T("ui.xml"); }
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
				pWebBrowser->Navigate(L"http://www.baidu.com/", NULL, NULL, NULL, NULL);

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


int APIENTRY WinMain(HINSTANCE hInstance, 
					 HINSTANCE hPrevInstance, 
					 LPTSTR lpCmdLine, 
					 int nCmdShow)
{
	//::MessageBox(NULL, _T("Hello World !"), _T("Demo!"), NULL);
	DuiLib::CPaintManagerUI::SetInstance(hInstance);

	HRESULT hr = ::CoInitialize(NULL);
	if (FAILED(hr)) return 0;
	//DuiLib::CPaintManagerUI::SetResourcePath(DuiLib::CPaintManagerUI::GetInstancePath());

	CDuiFrameWndX* pFrame = new CDuiFrameWndX();

	if (pFrame == NULL) return 0;

	pFrame->Create(NULL, _T("DuiLib_Demo"), UI_WNDSTYLE_FRAME, WS_EX_WINDOWEDGE);
	pFrame->CenterWindow();
	pFrame->ShowModal();

	delete pFrame;
	::CoUninitialize();
	//pFrame->ShowWindow(true);
	//DuiLib::CPaintManagerUI::MessageLoop();
	return 0;
}