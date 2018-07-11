#include <Windows.h>
#include <stdio.h>

#include <tchar.h>

#include "resource.h"

/******************************************************
part 1
	����ͼ->��Ӧ��Ŀ�Ҽ�->�����Դ->Dialog->�½�

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrev, LPSTR lpCmd, int nCmdShow)
{
	//��һ������Դ�ܹ�, �ڶ������Լ���DLG_ID, �������Ǹ�����, ���ĸ��ǻص�����
	//���ĸ�����, ���ڵ�һϵ�в������ɻص�����ȥִ��
	DialogBox(hInstance, (LPCTSTR)IDD_MAIN_DLG, NULL, NULL);

	return 0;
}
******************************************************/

/******************************************************
part 2 �����ڵ��κβ������ɻص�����ִ��

INT_PTR CALLBACK DLGCallBack(_In_ HWND   hwndDlg, _In_ UINT   uMsg, _In_ WPARAM wParam, _In_ LPARAM lParam)
{	//�ص�����,
	switch (uMsg)
	{
	case WM_COMMAND://������Ϣ
		if (LOWORD(wParam) == IDOK)
		{
			//���һ������:�Ƿ�֧�ָ���
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
	//��һ������Դ�ܹ�, �ڶ������Լ���DLG_ID, �������Ǹ�����, ���ĸ��ǻص����� 
	//���ĸ�����, ���ڵ�һϵ�в������ɻص�����ȥִ��
	DialogBox(hInstance, (LPCTSTR)IDD_MAIN_DLG, NULL, DLGCallBack);

	return 0;
}
******************************************************/

/******************************************************
part 3 ���ڵ���ͼƬ
	����ͼ->��Ӧ��Ŀ�Ҽ�->�����Դ->Bitmap->�½�
	��Դ��ͼ->Bitmap->�Ҽ�->�����Դ->����*.bmp->�޸�*.bmp��ID
	������->picture control->�Ҽ�����->����->type->bitmap
											->Image->ѡ�����*.bmpID

part 4 �˵���
	����ͼ->��Ӧ��Ŀ�Ҽ�->�����Դ->Menu->�½�
	��Դ��ͼ->�ɶ�Menu���б༭(��Ҫ�༭���������»���,������ǰ����&)
	��Դ��ͼ->Dialog->����->����->ѡ��menu��ID

INT_PTR CALLBACK DLGCallBack(_In_ HWND   hwndDlg, _In_ UINT   uMsg, _In_ WPARAM wParam, _In_ LPARAM lParam)
{	//�ص�����,
	switch (uMsg)
	{
	case WM_COMMAND://������Ϣ
		if (LOWORD(wParam) == IDOK)
		{
			//���һ������:�Ƿ�֧�ָ���
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
				SetDlgItemText(hwndDlg, IDC_DIVISUM, _T("����������Ϊ 0"));
			}
			nLeft = GetDlgItemInt(hwndDlg, IDC_LDIVI, NULL, true);
			SetDlgItemInt(hwndDlg, IDC_DIVISUM, nLeft / nRight, true);

			return true;
		}
		if (LOWORD(wParam) == IDCANCEL)
		{
			//��ť����
			EndDialog(hwndDlg, IDCANCEL);
			return true;
		}
		if (LOWORD(wParam) == ID_EXIT)
		{
			//�˵�����
			EndDialog(hwndDlg, ID_EXIT);
			return true;
		}
		break;
	}
	return false;
}
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrev, LPSTR lpCmd, int nCmdShow)
{
	//��һ������Դ�ܹ�, �ڶ������Լ���DLG_ID, �������Ǹ�����, ���ĸ��ǻص����� 
	//���ĸ�����, ���ڵ�һϵ�в������ɻص�����ȥִ��
	DialogBox(hInstance, (LPCTSTR)IDD_MAIN_DLG, NULL, DLGCallBack);

	return 0;
}
******************************************************/

/******************************************************
part 5 ��ȡ�ռ�����,ʹ����ת����double����

		���ַ���ת��Ϊ����: atoi, ת��Ϊ������: atof
		������ת��Ϊ�ַ���: itoa
		sprintf�����ܽ��������͵�����ת��Ϊ�ַ���: ��ʽ������


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
{	//�ص�����,
	switch (uMsg)
	{
	case WM_COMMAND://������Ϣ
		if (LOWORD(wParam) == IDOK)
		{
			//���һ������:�Ƿ�֧�ָ���
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
				SetDlgItemText(hwndDlg, IDC_DIVISUM, _T("����������Ϊ 0"));
			}
			nLeft = GetDlgItemDouble(hwndDlg, IDC_LDIVI);
			SetDlgItemDouble(hwndDlg, IDC_DIVISUM, nLeft / nRight);

			return true;
		}
		if (LOWORD(wParam) == IDCANCEL)
		{
			//��ť����
			EndDialog(hwndDlg, IDCANCEL);
			return true;
		}
			if (LOWORD(wParam) == ID_EXIT)
		{
			//�˵�����
			EndDialog(hwndDlg, ID_EXIT);
			return true;
		}
	break;
	}
	return false;
}
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrev, LPSTR lpCmd, int nCmdShow)
{
	//��һ������Դ�ܹ�, �ڶ������Լ���DLG_ID, �������Ǹ�����, ���ĸ��ǻص�����
	//���ĸ�����, ���ڵ�һϵ�в������ɻص�����ȥִ��
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
	//���һ������:�Ƿ�֧�ָ���
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
		SetDlgItemText(hwndDlg, IDC_DIVISUM, _T("����������Ϊ 0"));
		return;
	}
	nLeft = GetDlgItemDouble(hwndDlg, IDC_LDIVI);
	SetDlgItemDouble(hwndDlg, IDC_DIVISUM, nLeft / nRight);
}
INT_PTR CALLBACK DLGCallBack(_In_ HWND   hwndDlg, _In_ UINT   uMsg, _In_ WPARAM wParam, _In_ LPARAM lParam)
{	//�ص�����,
	switch (uMsg)
	{
	case WM_INITDIALOG:
	{
		OninitDialog(hwndDlg);
		return true;
	}
		break;
	case WM_COMMAND://������Ϣ
		if (LOWORD(wParam) == IDOK)
		{
			OnCalc(hwndDlg);
			return true;
		}
		if (LOWORD(wParam) == IDCANCEL)
		{
			//��ť����
			EndDialog(hwndDlg, IDCANCEL);
			return true;
		}
		if (LOWORD(wParam) == ID_EXIT)
		{
			//�˵�����
			EndDialog(hwndDlg, ID_EXIT);
			return true;
		}
		break;
	}
	return false;
}
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrev, LPSTR lpCmd, int nCmdShow)
{
	//��һ������Դ�ܹ�, �ڶ������Լ���DLG_ID, �������Ǹ�����, ���ĸ��ǻص�����
	//���ĸ�����, ���ڵ�һϵ�в������ɻص�����ȥִ��
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
	//���һ������:�Ƿ�֧�ָ���
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
		SetDlgItemText(hwndDlg, IDC_DIVISUM, _T("����������Ϊ 0"));
		return;
	}
	nLeft = GetDlgItemDouble(hwndDlg, IDC_LDIVI);
	SetDlgItemDouble(hwndDlg, IDC_DIVISUM, nLeft / nRight);
}
INT_PTR CALLBACK DLGCallBack(_In_ HWND   hwndDlg, _In_ UINT   uMsg, _In_ WPARAM wParam, _In_ LPARAM lParam)
{	//�ص�����,
	switch (uMsg)
	{
	case WM_INITDIALOG:
	{
		OninitDialog(hwndDlg);
		return true;
	}
	break;
	case WM_COMMAND://������Ϣ
		if (LOWORD(wParam) == IDOK)
		{
			OnCalc(hwndDlg);
			return true;
		}
		if (LOWORD(wParam) == IDCANCEL)
		{
			//��ť����
			EndDialog(hwndDlg, IDCANCEL);
			return true;
		}
		if (LOWORD(wParam) == ID_EXIT)
		{
			//�˵�����
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
	//��һ������Դ�ܹ�, �ڶ������Լ���DLG_ID, �������Ǹ�����, ���ĸ��ǻص�����
	//���ĸ�����, ���ڵ�һϵ�в������ɻص�����ȥִ��

	if (ID_EXIT == DialogBox(hInstance, (LPCTSTR)IDD_LOGIN_DIALOG, NULL, LoginCallBack))
	{
		return 0;
	}
	DialogBox(hInstance, (LPCTSTR)IDD_MAIN_DLG, NULL, DLGCallBack);

	return 0;
}