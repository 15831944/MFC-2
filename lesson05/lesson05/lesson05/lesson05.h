
// lesson05.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// Clesson05App: 
// �йش����ʵ�֣������ lesson05.cpp
//

class Clesson05App : public CWinApp
{
public:
	Clesson05App();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
	void OnOK();
};

extern Clesson05App theApp;