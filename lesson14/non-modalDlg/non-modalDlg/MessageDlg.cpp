// MessageDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "non-modalDlg.h"
#include "MessageDlg.h"
#include "afxdialogex.h"


// MessageDlg �Ի���

IMPLEMENT_DYNAMIC(MessageDlg, CDialogEx)

MessageDlg::MessageDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MSGDLG, pParent)
{

}

MessageDlg::~MessageDlg()
{
}

void MessageDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(MessageDlg, CDialogEx)
END_MESSAGE_MAP()


// MessageDlg ��Ϣ�������
