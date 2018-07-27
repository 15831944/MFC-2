
#include <Windows.h>
#include "resource.h"

#include <tchar.h>
#include <atlstr.h>

/*********************************************************
part 8 全局变量
	资源总管:
*********************************************************/
HINSTANCE g_inst;


void OninitDialog(_In_ HWND hwndDlg)
{
/*********************************************************
	part 9 窗口初始化设置
		1) 窗口居中
*********************************************************/
	RECT rect;
	GetWindowRect(hwndDlg, &rect);
	//SM_CXSCREEN X SM_CYSCREEN: 1880 X 1800 -> is screen boundary
	//SM_CXFUKKSCREEN X SM_CYFUKKSCREEN: 2791 X 1776 -> is content boundary

	//GetSystemMetrics can get many Metrics, for example: cursor with is ? -> GetSystemMetrics(SM_CXCURSOR)
	int sy = GetSystemMetrics(SM_CYFULLSCREEN);
	int sx = GetSystemMetrics(SM_CXFULLSCREEN);
	int wide = rect.right - rect.left;
	int hight = rect.bottom - rect.top;
	int x = (sx - wide) / 2;
	int y = (sy - hight) / 2;
	MoveWindow(hwndDlg, x, y, wide, hight, true);

/*********************************************************
	part 10 窗口初始化设置
		1) 窗口图标设置
*********************************************************/
	HICON hIcon = LoadIcon(g_inst, MAKEINTRESOURCE(IDI_ICON));
	SendMessage(hwndDlg, WM_SETICON, TRUE, (LPARAM)hIcon);

}




/*********************************************************
	part 5 消息分类:
		1) 系统消息: 范围是从0~1024
			WM_NULL~WM_USER
		2) 用户(自定义)消息: 
			WM_USER+1以后的所有消息都是用户自定义的消息
*********************************************************/
/*********************************************************
	part 6 SendMessage()调用消息
*********************************************************/
/*********************************************************
	part 7 PostMessage()调用消息
*********************************************************/
enum
{
	UM_ADD = WM_USER + 100
};
INT_PTR CALLBACK DLGCallBack(_In_ HWND   hwndDlg, _In_ UINT   uMsg, _In_ WPARAM wParam, _In_ LPARAM lParam)
{	//回调函数,
	switch (uMsg)
	{
/*********************************************************
	part 4 switch case
	如果case里面有临时变量的定义就要加case xxx:{}
*********************************************************/
	case UM_ADD:
	{
		CString str;
		str.Format(_T("%d"), wParam + lParam);
		MessageBox(hwndDlg, str, _T("Prompt Message!\n"), MB_OK);

	}
	
		break;
	case WM_INITDIALOG:
	{
		OninitDialog(hwndDlg);
		return FALSE;
	}
	break;
/*********************************************************
	part 1 return FALSE;和 return TRUE 的区别
*********************************************************/
	case WM_CLOSE:
		ShowWindow(hwndDlg, SW_MINIMIZE);
		//MessageBox(hwndDlg, _T("CLOSE!\n"), _T("Prompt Message!\n"), MB_OK);
		//return FALSE; FALSE代表该命令继续执行
		return TRUE;//TRUE代表该命令执行到这里停
	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK)
		{
			//OnCalc(hwndDlg);
			return true;
		}
		if (LOWORD(wParam) == IDCANCEL)
		{
			EndDialog(hwndDlg, IDCANCEL);
			return true;
		}
/*********************************************************
	part 2 SendMessage给其他窗口发信号(同步)
		HWND hwnd = FindWindow(_T("Notepad"), NULL);
		SendMessage(hwnd, WM_CLOSE, 0, 0);
		如果"Notepad"进行柱塞,SwndMessage就要卡在这里等待
*********************************************************/
		if (LOWORD(wParam) == IDC_SEND)
		{
			SendMessage(hwndDlg, UM_ADD, 123, -123);//发送自己定义的消息
			//HWND hwnd = FindWindow(_T("Notepad"), NULL);
			//SendMessage(hwnd, WM_CLOSE, 0, 0);
			return true;
		}
/*********************************************************
	part 3 PostMessage给其他窗口发信号(异步)
		HWND hwnd = FindWindow(_T("Notepad"), NULL);
		PostMessage(hwnd, WM_CLOSE, 0, 0);
		如果"Notepad"进行柱塞,PostMessage不会卡在这,不等待
*********************************************************/
		if (LOWORD(wParam) == IDC_POST)
		{
			PostMessage(hwndDlg, WM_CLOSE, 0, 0);
			return true;
		}
		break;
	}
	return false;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrev, LPSTR lpCmd, int nCmdShow)	
{
	g_inst = hInstance;
	DialogBox(hInstance, (LPCTSTR)IDD_MAIN_DLG, NULL, DLGCallBack);
	return 0;
}
