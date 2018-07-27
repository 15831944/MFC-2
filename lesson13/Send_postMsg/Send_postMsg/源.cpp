
#include <Windows.h>
#include "resource.h"

#include <tchar.h>
#include <atlstr.h>

/*********************************************************
part 8 ȫ�ֱ���
	��Դ�ܹ�:
*********************************************************/
HINSTANCE g_inst;


void OninitDialog(_In_ HWND hwndDlg)
{
/*********************************************************
	part 9 ���ڳ�ʼ������
		1) ���ھ���
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
	part 10 ���ڳ�ʼ������
		1) ����ͼ������
*********************************************************/
	HICON hIcon = LoadIcon(g_inst, MAKEINTRESOURCE(IDI_ICON));
	SendMessage(hwndDlg, WM_SETICON, TRUE, (LPARAM)hIcon);

}




/*********************************************************
	part 5 ��Ϣ����:
		1) ϵͳ��Ϣ: ��Χ�Ǵ�0~1024
			WM_NULL~WM_USER
		2) �û�(�Զ���)��Ϣ: 
			WM_USER+1�Ժ��������Ϣ�����û��Զ������Ϣ
*********************************************************/
/*********************************************************
	part 6 SendMessage()������Ϣ
*********************************************************/
/*********************************************************
	part 7 PostMessage()������Ϣ
*********************************************************/
enum
{
	UM_ADD = WM_USER + 100
};
INT_PTR CALLBACK DLGCallBack(_In_ HWND   hwndDlg, _In_ UINT   uMsg, _In_ WPARAM wParam, _In_ LPARAM lParam)
{	//�ص�����,
	switch (uMsg)
	{
/*********************************************************
	part 4 switch case
	���case��������ʱ�����Ķ����Ҫ��case xxx:{}
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
	part 1 return FALSE;�� return TRUE ������
*********************************************************/
	case WM_CLOSE:
		ShowWindow(hwndDlg, SW_MINIMIZE);
		//MessageBox(hwndDlg, _T("CLOSE!\n"), _T("Prompt Message!\n"), MB_OK);
		//return FALSE; FALSE������������ִ��
		return TRUE;//TRUE���������ִ�е�����ͣ
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
	part 2 SendMessage���������ڷ��ź�(ͬ��)
		HWND hwnd = FindWindow(_T("Notepad"), NULL);
		SendMessage(hwnd, WM_CLOSE, 0, 0);
		���"Notepad"��������,SwndMessage��Ҫ��������ȴ�
*********************************************************/
		if (LOWORD(wParam) == IDC_SEND)
		{
			SendMessage(hwndDlg, UM_ADD, 123, -123);//�����Լ��������Ϣ
			//HWND hwnd = FindWindow(_T("Notepad"), NULL);
			//SendMessage(hwnd, WM_CLOSE, 0, 0);
			return true;
		}
/*********************************************************
	part 3 PostMessage���������ڷ��ź�(�첽)
		HWND hwnd = FindWindow(_T("Notepad"), NULL);
		PostMessage(hwnd, WM_CLOSE, 0, 0);
		���"Notepad"��������,PostMessage���Ῠ����,���ȴ�
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
