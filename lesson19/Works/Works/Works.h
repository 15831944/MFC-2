
// Works.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CWorksApp: 
// �йش����ʵ�֣������ Works.cpp
//

class CWorksApp : public CWinApp
{
public:
	CWorksApp();
	SAdmin m_Admin;

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CWorksApp theApp;