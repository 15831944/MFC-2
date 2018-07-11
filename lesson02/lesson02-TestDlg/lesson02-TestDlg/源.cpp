#include <Windows.h>
#include <stdio.h>

#include <tchar.h>

#include "resource.h"

/******************************************************
part 1
	类视图->对应项目右键->添加资源->Dialog->新建

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrev, LPSTR lpCmd, int nCmdShow)
{
	//第一个是资源总管, 第二个是自己的DLG_ID, 第三个是父窗口, 第四个是回调函数
	//第四个参数, 窗口的一系列操作都由回调函数去执行
	DialogBox(hInstance, (LPCTSTR)IDD_MAIN_DLG, NULL, NULL);

	return 0;
}
******************************************************/

/******************************************************
part 2 窗口内的任何操作都由回调函数执行

INT_PTR CALLBACK DLGCallBack(_In_ HWND   hwndDlg, _In_ UINT   uMsg, _In_ WPARAM wParam, _In_ LPARAM lParam)
{	//回调函数,
	switch (uMsg)
	{
	case WM_COMMAND://命令消息
		if (LOWORD(wParam) == IDOK)
		{
			//最后一个参数:是否支持负数
			int nLeft = GetDlgItemInt(hwndDlg, IDC_LADD, NULL, true);
			int nRight = GetDlgItemInt(hwndDlg, IDC_RADD, NULL, true);
			SetDlgItemInt(hwndDlg, IDC_ADDSUM, nLeft + nRight, true);
		}
		if (LOWORD(wParam) == IDCANCEL)
		{
			EndDialog(hwndDlg, IDCANCEL);
		}
		break;
	}
	return 0;
}
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrev, LPSTR lpCmd, int nCmdShow)
{
	//第一个是资源总管, 第二个是自己的DLG_ID, 第三个是父窗口, 第四个是回调函数 
	//第四个参数, 窗口的一系列操作都由回调函数去执行
	DialogBox(hInstance, (LPCTSTR)IDD_MAIN_DLG, NULL, DLGCallBack);

	return 0;
}
******************************************************/

/******************************************************
part 3 窗口导入图片
	类视图->对应项目右键->添加资源->Bitmap->新建
	资源视图->Bitmap->右键->添加资源->导入*.bmp->修改*.bmp的ID
	工具箱->picture control->右键属性->杂项->type->bitmap
											->Image->选择导入的*.bmpID

part 4 菜单栏
	类视图->对应项目右键->添加资源->Menu->新建
	资源视图->可对Menu进行编辑(想要编辑的字体有下划线,在字体前加入&)
	资源视图->Dialog->属性->杂项->选择menu的ID

INT_PTR CALLBACK DLGCallBack(_In_ HWND   hwndDlg, _In_ UINT   uMsg, _In_ WPARAM wParam, _In_ LPARAM lParam)
{	//回调函数,
	switch (uMsg)
	{
	case WM_COMMAND://命令消息
		if (LOWORD(wParam) == IDOK)
		{
			//最后一个参数:是否支持负数
			int nLeft = GetDlgItemInt(hwndDlg, IDC_LADD, NULL, true);
			int nRight = GetDlgItemInt(hwndDlg, IDC_RADD, NULL, true);
			SetDlgItemInt(hwndDlg, IDC_ADDSUM, nLeft + nRight, true);

			nLeft = GetDlgItemInt(hwndDlg, IDC_LSUB, NULL, true);
			nRight = GetDlgItemInt(hwndDlg, IDC_RSUB, NULL, true);
			SetDlgItemInt(hwndDlg, IDC_SUBSUM, nLeft - nRight, true);

			nLeft = GetDlgItemInt(hwndDlg, IDC_LMUL, NULL, true);
			nRight = GetDlgItemInt(hwndDlg, IDC_RMUL, NULL, true);
			SetDlgItemInt(hwndDlg, IDC_MULSUM, nLeft * nRight, true);

			nRight = GetDlgItemInt(hwndDlg, IDC_RDIVI, NULL, true);
			if (0 == nRight)
			{
				SetDlgItemText(hwndDlg, IDC_DIVISUM, _T("被除数不能为 0"));
			}
			nLeft = GetDlgItemInt(hwndDlg, IDC_LDIVI, NULL, true);
			SetDlgItemInt(hwndDlg, IDC_DIVISUM, nLeft / nRight, true);

			return true;
		}
		if (LOWORD(wParam) == IDCANCEL)
		{
			//按钮才做
			EndDialog(hwndDlg, IDCANCEL);
			return true;
		}
		if (LOWORD(wParam) == ID_EXIT)
		{
			//菜单操作
			EndDialog(hwndDlg, ID_EXIT);
			return true;
		}
		break;
	}
	return false;
}
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrev, LPSTR lpCmd, int nCmdShow)
{
	//第一个是资源总管, 第二个是自己的DLG_ID, 第三个是父窗口, 第四个是回调函数 
	//第四个参数, 窗口的一系列操作都由回调函数去执行
	DialogBox(hInstance, (LPCTSTR)IDD_MAIN_DLG, NULL, DLGCallBack);

	return 0;
}
******************************************************/

/******************************************************
part 5 获取空间文字,使文字转换成double类型

		由字符串转化为整数: atoi, 转化为浮点数: atof
		由整数转化为字符串: itoa
		sprintf函数能将各种类型的数字转化为字符串: 格式化函数


double GetDlgItemDouble(HWND hwnd, UINT nID)
{
	TCHAR tmp[256] = { 0 };
	GetDlgItemText(hwnd, nID, tmp, sizeof(tmp));
#ifdef UNICODE
	return _wtof(tmp);
#else
	return atof(tmp);
#endif
}
void SetDlgItemDouble(HWND hwnd, UINT nID, double data)
{
	TCHAR tmp[256] = { 0 };
#ifdef UNICODE
	swprintf(tmp, 256, _T("%lf"), data);
	SetDlgItemText(hwnd, nID, tmp);
#else
	sprintf(tmp, sizeof(tmp), _T("%lf"), data);
	SetDlgItemText(hwnd, nID, tmp);
#endif

}
INT_PTR CALLBACK DLGCallBack(_In_ HWND   hwndDlg, _In_ UINT   uMsg, _In_ WPARAM wParam, _In_ LPARAM lParam)
{	//回调函数,
	switch (uMsg)
	{
	case WM_COMMAND://命令消息
		if (LOWORD(wParam) == IDOK)
		{
			//最后一个参数:是否支持负数
			double nLeft = GetDlgItemDouble(hwndDlg, IDC_LADD);
			double nRight = GetDlgItemDouble(hwndDlg, IDC_RADD);
			SetDlgItemDouble(hwndDlg, IDC_ADDSUM, nLeft + nRight);

			nLeft = GetDlgItemDouble(hwndDlg, IDC_LSUB);
			nRight = GetDlgItemDouble(hwndDlg, IDC_RSUB);
			SetDlgItemDouble(hwndDlg, IDC_SUBSUM, nLeft - nRight);

			nLeft = GetDlgItemDouble(hwndDlg, IDC_LMUL);
			nRight = GetDlgItemDouble(hwndDlg, IDC_RMUL);
			SetDlgItemDouble(hwndDlg, IDC_MULSUM, nLeft * nRight);

			nRight = GetDlgItemDouble(hwndDlg, IDC_RDIVI);
			if (0 == nRight)
			{
				SetDlgItemText(hwndDlg, IDC_DIVISUM, _T("被除数不能为 0"));
			}
			nLeft = GetDlgItemDouble(hwndDlg, IDC_LDIVI);
			SetDlgItemDouble(hwndDlg, IDC_DIVISUM, nLeft / nRight);

			return true;
		}
		if (LOWORD(wParam) == IDCANCEL)
		{
			//按钮才做
			EndDialog(hwndDlg, IDCANCEL);
			return true;
		}
			if (LOWORD(wParam) == ID_EXIT)
		{
			//菜单操作
			EndDialog(hwndDlg, ID_EXIT);
			return true;
		}
	break;
	}
	return false;
}
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrev, LPSTR lpCmd, int nCmdShow)
{
	//第一个是资源总管, 第二个是自己的DLG_ID, 第三个是父窗口, 第四个是回调函数
	//第四个参数, 窗口的一系列操作都由回调函数去执行
	DialogBox(hInstance, (LPCTSTR)IDD_MAIN_DLG, NULL, DLGCallBack);

	return 0;
}
******************************************************/

/******************************************************
part 6  Interface Initialization

*WM_xxx	: Windows Message
*MB_xxx	: Message Box
*SM_xxx	: System Message

*GetWindowRect		: get dialog screen wide, hight, top, bottom
*GetSystemMetrics	: get System Metrics , for example: get screen resolution 2880 X 1800
*MoveWindow			: move dialog



double GetDlgItemDouble(HWND hwnd, UINT nID)
{
	TCHAR tmp[256] = { 0 };
	GetDlgItemText(hwnd, nID, tmp, sizeof(tmp));
#ifdef UNICODE
	return _wtof(tmp);
#else
	return atof(tmp);
#endif
}
void SetDlgItemDouble(HWND hwnd, UINT nID, double data)
{
	TCHAR tmp[256] = { 0 };
#ifdef UNICODE
	swprintf(tmp, 256, _T("%lf"), data);
	SetDlgItemText(hwnd, nID, tmp);
#else
	sprintf(tmp, sizeof(tmp), _T("%lf"), data);
	SetDlgItemText(hwnd, nID, tmp);
#endif

}

void OninitDialog(_In_ HWND hwndDlg)
{
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

}
void OnCalc(_In_ HWND hwndDlg)
{
	//最后一个参数:是否支持负数
	double nLeft = GetDlgItemDouble(hwndDlg, IDC_LADD);
	double nRight = GetDlgItemDouble(hwndDlg, IDC_RADD);
	SetDlgItemDouble(hwndDlg, IDC_ADDSUM, nLeft + nRight);

	nLeft = GetDlgItemDouble(hwndDlg, IDC_LSUB);
	nRight = GetDlgItemDouble(hwndDlg, IDC_RSUB);
	SetDlgItemDouble(hwndDlg, IDC_SUBSUM, nLeft - nRight);

	nLeft = GetDlgItemDouble(hwndDlg, IDC_LMUL);
	nRight = GetDlgItemDouble(hwndDlg, IDC_RMUL);
	SetDlgItemDouble(hwndDlg, IDC_MULSUM, nLeft * nRight);

	nRight = GetDlgItemDouble(hwndDlg, IDC_RDIVI);
	if (0 == nRight)
	{
		SetDlgItemText(hwndDlg, IDC_DIVISUM, _T("被除数不能为 0"));
		return;
	}
	nLeft = GetDlgItemDouble(hwndDlg, IDC_LDIVI);
	SetDlgItemDouble(hwndDlg, IDC_DIVISUM, nLeft / nRight);
}
INT_PTR CALLBACK DLGCallBack(_In_ HWND   hwndDlg, _In_ UINT   uMsg, _In_ WPARAM wParam, _In_ LPARAM lParam)
{	//回调函数,
	switch (uMsg)
	{
	case WM_INITDIALOG:
	{
		OninitDialog(hwndDlg);
		return true;
	}
		break;
	case WM_COMMAND://命令消息
		if (LOWORD(wParam) == IDOK)
		{
			OnCalc(hwndDlg);
			return true;
		}
		if (LOWORD(wParam) == IDCANCEL)
		{
			//按钮才做
			EndDialog(hwndDlg, IDCANCEL);
			return true;
		}
		if (LOWORD(wParam) == ID_EXIT)
		{
			//菜单操作
			EndDialog(hwndDlg, ID_EXIT);
			return true;
		}
		break;
	}
	return false;
}
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrev, LPSTR lpCmd, int nCmdShow)
{
	//第一个是资源总管, 第二个是自己的DLG_ID, 第三个是父窗口, 第四个是回调函数
	//第四个参数, 窗口的一系列操作都由回调函数去执行
	DialogBox(hInstance, (LPCTSTR)IDD_MAIN_DLG, NULL, DLGCallBack);

	return 0;
}
******************************************************/


/******************************************************
part 7  The second Dialog -> Login Dialog


*void OnLogin(_In_ HWND   hwndDlg)
*INT_PTR WINAPI LoginCallBack(_In_ HWND   hwndDlg, _In_ UINT   uMsg, _In_ WPARAM wParam, _In_ LPARAM lParam)
*
******************************************************/


double GetDlgItemDouble(HWND hwnd, UINT nID)
{
	TCHAR tmp[256] = { 0 };
	GetDlgItemText(hwnd, nID, tmp, sizeof(tmp));
#ifdef UNICODE
	return _wtof(tmp);
#else
	return atof(tmp);
#endif
}
void SetDlgItemDouble(HWND hwnd, UINT nID, double data)
{
	TCHAR tmp[256] = { 0 };
#ifdef UNICODE
	swprintf(tmp, 256, _T("%lf"), data);
	SetDlgItemText(hwnd, nID, tmp);
#else
	sprintf(tmp, sizeof(tmp), _T("%lf"), data);
	SetDlgItemText(hwnd, nID, tmp);
#endif

}

void OninitDialog(_In_ HWND hwndDlg)
{
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

}
void OnCalc(_In_ HWND hwndDlg)
{
	//最后一个参数:是否支持负数
	double nLeft = GetDlgItemDouble(hwndDlg, IDC_LADD);
	double nRight = GetDlgItemDouble(hwndDlg, IDC_RADD);
	SetDlgItemDouble(hwndDlg, IDC_ADDSUM, nLeft + nRight);

	nLeft = GetDlgItemDouble(hwndDlg, IDC_LSUB);
	nRight = GetDlgItemDouble(hwndDlg, IDC_RSUB);
	SetDlgItemDouble(hwndDlg, IDC_SUBSUM, nLeft - nRight);

	nLeft = GetDlgItemDouble(hwndDlg, IDC_LMUL);
	nRight = GetDlgItemDouble(hwndDlg, IDC_RMUL);
	SetDlgItemDouble(hwndDlg, IDC_MULSUM, nLeft * nRight);

	nRight = GetDlgItemDouble(hwndDlg, IDC_RDIVI);
	if (0 == nRight)
	{
		SetDlgItemText(hwndDlg, IDC_DIVISUM, _T("被除数不能为 0"));
		return;
	}
	nLeft = GetDlgItemDouble(hwndDlg, IDC_LDIVI);
	SetDlgItemDouble(hwndDlg, IDC_DIVISUM, nLeft / nRight);
}
INT_PTR CALLBACK DLGCallBack(_In_ HWND   hwndDlg, _In_ UINT   uMsg, _In_ WPARAM wParam, _In_ LPARAM lParam)
{	//回调函数,
	switch (uMsg)
	{
	case WM_INITDIALOG:
	{
		OninitDialog(hwndDlg);
		return true;
	}
	break;
	case WM_COMMAND://命令消息
		if (LOWORD(wParam) == IDOK)
		{
			OnCalc(hwndDlg);
			return true;
		}
		if (LOWORD(wParam) == IDCANCEL)
		{
			//按钮才做
			EndDialog(hwndDlg, IDCANCEL);
			return true;
		}
		if (LOWORD(wParam) == ID_EXIT)
		{
			//菜单操作
			EndDialog(hwndDlg, ID_EXIT);
			return true;
		}
		break;
	}
	return false;
}
void OnLogin(_In_ HWND   hwndDlg)
{
	TCHAR tmp_name[32] = { 0 };
	TCHAR tmp_key[32] = { 0 };
	GetDlgItemText(hwndDlg, IDC_ACCOUNT, tmp_name, sizeof(tmp_name));
	GetDlgItemText(hwndDlg, IDC_KEY, tmp_key, sizeof(tmp_key));
	if (0 != _tcscmp(tmp_key, _T("admin")) && 0 != _tcscmp(tmp_name, _T("admin")))
	{
		MessageBox(hwndDlg, _T(" Accounts errors!"), _T("Error"), NULL);
	}
	EndDialog(hwndDlg, ID_EXIT);
}
INT_PTR WINAPI LoginCallBack(_In_ HWND   hwndDlg, _In_ UINT   uMsg, _In_ WPARAM wParam, _In_ LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_INITDIALOG:
	{
		OninitDialog(hwndDlg);
		return true;
	}
	break;
	case WM_COMMAND:
		if (wParam == IDOK)
		{
			OnLogin(hwndDlg);
			return true;
		}
		if (wParam == IDCANCEL)
		{
			EndDialog(hwndDlg, ID_EXIT);
			return true;
		}
		break;
	default:
		break;
	}
	return false;
}
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrev, LPSTR lpCmd, int nCmdShow)
{
	//第一个是资源总管, 第二个是自己的DLG_ID, 第三个是父窗口, 第四个是回调函数
	//第四个参数, 窗口的一系列操作都由回调函数去执行

	if (ID_EXIT == DialogBox(hInstance, (LPCTSTR)IDD_LOGIN_DIALOG, NULL, LoginCallBack))
	{
		return 0;
	}
	DialogBox(hInstance, (LPCTSTR)IDD_MAIN_DLG, NULL, DLGCallBack);

	return 0;
}