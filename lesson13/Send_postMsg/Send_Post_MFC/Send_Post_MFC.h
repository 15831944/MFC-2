
// Send_Post_MFC.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CSend_Post_MFCApp: 
// �йش����ʵ�֣������ Send_Post_MFC.cpp
//

class CSend_Post_MFCApp : public CWinApp
{
public:
	CSend_Post_MFCApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CSend_Post_MFCApp theApp;