
// TestCWinApp.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CTestCWinAppApp: 
// �йش����ʵ�֣������ TestCWinApp.cpp
//

class CTestCWinAppApp : public CWinApp
{
public:
	CTestCWinAppApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CTestCWinAppApp theApp;