
#include <Windows.h>
#include "resource.h"

#include <tchar.h>
#include <atlstr.h>
#include <Commctrl.h>

/*********************************************************
	part 0 ȫ�ֱ���
		��Դ�ܹ�:
*********************************************************/
HINSTANCE g_inst;

/*********************************************************
	part 5 LIST �б������
		��MFC����F11��ȥ,�Ѵ���۳���,�������Ӧ�Ĳ���
*********************************************************/
int InsertColumn(HWND hwndDlg, int nCol, LPCTSTR lpszColumnHeading, int nFormat, int nWidth)
{
	LVCOLUMN column;
	column.mask = LVCF_TEXT | LVCF_FMT;
	column.pszText = (LPTSTR)lpszColumnHeading;
	column.fmt = nFormat;
	if (nWidth != -1)
	{
		column.mask |= LVCF_WIDTH;
		column.cx = nWidth;
	}

	return (int) ::SendMessage(hwndDlg, LVM_INSERTCOLUMN, nCol, (LPARAM)&column);
}


/*********************************************************
	part 6 LIST �ж������
		1)��MFC����F11��ȥ,�Ѵ���۳���,�������Ӧ�Ĳ���
*********************************************************/
int InsertItem(HWND hwndDlg, UINT nMask, int nItem, LPCTSTR lpszItem)
{

	LVITEM item;
	item.mask = nMask;
	item.iItem = nItem;
	item.iSubItem = 0;
	item.pszText = (LPTSTR)lpszItem;
	//item.state = nState;
	//item.stateMask = nStateMask;
	//item.iImage = nImage;
	//item.lParam = lParam;
	return (int) ::SendMessage(hwndDlg, LVM_INSERTITEM, 0, (LPARAM)&item);
}


/*********************************************************
	part 7 LIST �ж�������в���
		1)��MFC����F11��ȥ,�Ѵ���۳���,�������Ӧ�Ĳ���
*********************************************************/
BOOL SetItemText(HWND hwndDlg, int nItem, int nSubItem, LPCTSTR lpszText)
{
	LVITEM lvi;
	lvi.iSubItem = nSubItem;
	lvi.pszText = (LPTSTR)lpszText;
	return (BOOL) ::SendMessage(hwndDlg, LVM_SETITEMTEXT, nItem, (LPARAM)&lvi);
}


/*********************************************************
	part 1 ���ڳ�ʼ������
	
*********************************************************/
void CWindows(_In_ HWND hwndDlg)
{
	/*********************************************************
	part 2 ���ڳ�ʼ������
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
}
void Icon(_In_ HWND hwndDlg)
{
	/*********************************************************
	part 3 ���ڳ�ʼ������
	1) ����ͼ������
	*********************************************************/
	HICON hIcon = LoadIcon(g_inst, MAKEINTRESOURCE(IDI_ICON));
	SendMessage(hwndDlg, WM_SETICON, TRUE, (LPARAM)hIcon);
}
void ListInit(_In_ HWND hwndDlg)
{

	/*********************************************************
	part 4 �б�ռ�����
	1) �б���
	2) �б�����ɫ,���屳����ɫ
	3) �б���
	*********************************************************/
	HWND hWnd = GetDlgItem(hwndDlg, IDC_LIST);
	InsertColumn(hWnd, 0, _T("����"), LVCFMT_LEFT, 150);
	InsertColumn(hWnd, 1, _T("����"), LVCFMT_LEFT, 150);
	InsertColumn(hWnd, 2, _T("����"), LVCFMT_LEFT, 150);
	InsertColumn(hWnd, 3, _T("��ְ����"), LVCFMT_LEFT, 246);
	SendMessage(hWnd, LVM_SETBKCOLOR, 0, RGB(205, 226, 252));
	SendMessage(hWnd, LVM_SETTEXTBKCOLOR, 0, RGB(205, 226, 252));
	SendMessage(hWnd, LVM_SETTEXTCOLOR, 0, RGB(0, 0, 255));
	SendMessage(hWnd, LVM_SETEXTENDEDLISTVIEWSTYLE, 0, LVS_EX_AUTOCHECKSELECT | LVS_EX_CHECKBOXES | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES | LVS_EX_DOUBLEBUFFER);
	/*
	pList->SetBkColor(RGB(205, 226, 252));
	pList->SetTextBkColor(RGB(205, 226, 252));
	pList->SetTextColor(RGB(0, 0, 255));
	pList->SetExtendedStyle(LVS_EX_AUTOCHECKSELECT | LVS_EX_CHECKBOXES | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES | LVS_EX_DOUBLEBUFFER);
	*/
}
void OninitDialog(_In_ HWND hwndDlg)
{

	CWindows(hwndDlg);

	Icon(hwndDlg);

	ListInit(hwndDlg);
}

/*********************************************************
	part 8 �б��������
	
*********************************************************/
void WorkADD(_In_ HWND hwndDlg)
{
	CString nub, name, wage, date;
	TCHAR *str = (TCHAR *)malloc(50);
	HWND hWnd = GetDlgItem(hwndDlg, IDC_LIST);

	GetDlgItemText(hwndDlg, IDC_WORK_NUB, str, 50);
	int nItem = SendMessage(hWnd, LVM_GETITEMCOUNT, 0, 0L);
	InsertItem(hWnd, LVIF_TEXT, nItem, str);



	GetDlgItemText(hwndDlg, IDC_WORK_NAME, str, 50);
	SetItemText(hWnd, nItem, 1, str);

	GetDlgItemText(hwndDlg, IDC_WORK_WAGE, str, 50);
	SetItemText(hWnd, nItem, 2, str);

	GetDlgItemText(hwndDlg, IDC_WORK_DATE, str, 50);
	SetItemText(hWnd, nItem, 3, str);

	free(str);
}

enum
{
	UM_ADD = WM_USER + 100
};
INT_PTR CALLBACK DLGCallBack(_In_ HWND   hwndDlg, _In_ UINT   uMsg, _In_ WPARAM wParam, _In_ LPARAM lParam)
{	//�ص�����,
	switch (uMsg)
	{
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

	case WM_CLOSE:
		break;
	case WM_COMMAND:
		if (LOWORD(wParam) == IDCANCEL)
		{
			EndDialog(hwndDlg, IDCANCEL);
			return true;
		}
		if (LOWORD(wParam) == IDC_WORK_ADD)
		{
			WorkADD(hwndDlg);
			return true;
		}
		if (LOWORD(wParam) == IDC_WORK_LOOKUP)
		{

			return true;
		}
		if (LOWORD(wParam) == IDC_WORK_DELE)
		{

			return true;
		}
		if (LOWORD(wParam) == IDC_WORK_MODIFY)
		{

			return true;
		}
		if (LOWORD(wParam) == IDC_WORK_SAVE)
		{

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
