
// lesson03-TestMeg.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// Clesson03TestMegApp: 
// �йش����ʵ�֣������ lesson03-TestMeg.cpp
//

class Clesson03TestMegApp : public CWinApp
{
public:
	Clesson03TestMegApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern Clesson03TestMegApp theApp;