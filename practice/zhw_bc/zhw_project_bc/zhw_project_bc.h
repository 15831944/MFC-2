
// zhw_project_bc.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// Czhw_project_bcApp: 
// �йش����ʵ�֣������ zhw_project_bc.cpp
//

class Czhw_project_bcApp : public CWinApp
{
public:
	Czhw_project_bcApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern Czhw_project_bcApp theApp;