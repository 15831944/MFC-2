
// lesson04-MFC������.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// Clesson04MFC������App: 
// �йش����ʵ�֣������ lesson04-MFC������.cpp
//

class Clesson04MFC������App : public CWinApp
{
public:
	Clesson04MFC������App();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern Clesson04MFC������App theApp;