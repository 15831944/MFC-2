#include <Windows.h>
#include <stdio.h>
#include <tchar.h>

#include "resource.h"

INT_PTR WINAPI msgProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{

	switch (uMsg)
	{
	case WM_CREATE:
		MessageBox(hWnd, _T("WM_CREWTE"), _T("Test"), 0);
		break;
	case WM_INITDIALOG:
	{
		RECT rect;
		GetWindowRect(hWnd, &rect);
		//200,100 is screen resolution size
		MoveWindow(hWnd, 200, 100, rect.right - rect.left, rect.bottom - rect.top, false);
		SetWindowText(hWnd, _T("Test Text"));
		MessageBox(hWnd, _T("WM_INITDIALOG"), _T("Test"), 0);
	}
		break;
	case WM_CLOSE:
		//Control + F4 and windows'close touch WM_CLOSE
		MessageBox(hWnd, _T("WM_CLOSE"), _T("Test"), 0);
		EndDialog(hWnd, IDCANCEL);
		break;
	case WM_LBUTTONDOWN:
	{
		int x = LOWORD(lParam);
		int y = HIWORD(lParam);
		TCHAR tmp[256] = { 0 };
		_stprintf_s(tmp, 256, _T("WM_LBUTTONDOWN size: %d,%d"), x, y);
		SetWindowText(hWnd, tmp);
	}
		break;
	case WM_RBUTTONDOWN:
	{
		int x = LOWORD(lParam);
		int y = HIWORD(lParam);
		TCHAR tmp[256] = { 0 };
		_stprintf_s(tmp, 256, _T("WM_RBUTTONDOWN size: %d,%d"), x, y);
		SetWindowText(hWnd, tmp);
	}
		break;
	case WM_MOUSEMOVE:
	{
		//combination of bit flags: wParam = MK_RBUTTON | MK_SHIFT
		//judgement of bit flags: wPraram = MK_RBUTTON & MK_SHIFT
		//separation of bit flags: wPraram &= ~MK_RBUTTON
		int x = LOWORD(lParam);
		int y = HIWORD(lParam);
		TCHAR tmp[256] = { 0 };
		int nub = _stprintf_s(tmp, 256, _T("WM_MOUSEMOVE size: %d,%d"), x, y);
		if (wParam & MK_RBUTTON)
			nub += _stprintf_s(tmp + nub, 256 - nub, _T("Press MK_RBUTTON"));
		if (wParam & MK_LBUTTON)
			nub += _stprintf_s(tmp + nub, 256 - nub, _T("Press MK_LBUTTON"));
		if (wParam & MK_SHIFT)
			nub += _stprintf_s(tmp + nub, 256 - nub, _T("Press MK_SHIFT"));
		if (wParam & MK_CONTROL)
			nub += _stprintf_s(tmp + nub, 256 - nub, _T("Press MK_CONTROL"));
		SetWindowText(hWnd, tmp);
	}
	break;
	case WM_RBUTTONUP:
	{
		int x = LOWORD(lParam);
		int y = HIWORD(lParam);
		TCHAR tmp[256] = { 0 };
		_stprintf_s(tmp, 256, _T("WM_RBUTTONUP size: %d,%d"), x, y);
		SetWindowText(hWnd, tmp);
	}
	break;
	case WM_LBUTTONUP:
	{
		POINT point;
		point.x = LOWORD(lParam);
		point.y = HIWORD(lParam);
		TCHAR tmp[256] = { 0 };
		_stprintf_s(tmp, 256, _T("WM_LBUTTONUP size: %d,%d"), point.x, point.y);
		SetWindowText(hWnd, tmp);
	}
	break;
	default:
		break;
	}
	return 0;
}
int WINAPI WinMain(HINSTANCE hInstancce, HINSTANCE hPrev, LPSTR lpCmd, int nCmdShow)
{
	DialogBox(hInstancce, (LPCTSTR)IDD_MSG_DLG, NULL, msgProc);
	return 0;
}