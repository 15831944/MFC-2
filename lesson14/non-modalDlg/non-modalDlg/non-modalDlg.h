
// non-modalDlg.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CnonmodalDlgApp: 
// �йش����ʵ�֣������ non-modalDlg.cpp
//

class CnonmodalDlgApp : public CWinApp
{
public:
	CnonmodalDlgApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CnonmodalDlgApp theApp;