// ABOUT.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "non-modalDlg.h"
#include "ABOUT.h"
#include "afxdialogex.h"


// ABOUT �Ի���

IMPLEMENT_DYNAMIC(ABOUT, CDialogEx)

ABOUT::ABOUT(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_ABOUT, pParent)
{

}

ABOUT::~ABOUT()
{
}

void ABOUT::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(ABOUT, CDialogEx)
END_MESSAGE_MAP()


// ABOUT ��Ϣ�������
