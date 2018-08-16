#include "stdafx.h"
#include "Works.h"
#include "InputDlg.h"
#include "afxdialogex.h"

IMPLEMENT_DYNAMIC(CInputDlg, CDialogEx)

CInputDlg::CInputDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_INPUT_DLG, pParent)
{

}

CInputDlg::~CInputDlg()
{
}

void CInputDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CInputDlg, CDialogEx)
END_MESSAGE_MAP()

/*******************************************
part 1 table按键转换下个方框
	1) NextDlgCtrl();
*******************************************/
/*******************************************
part 2 关闭按钮的table
	1) 属性TabStop->false
*******************************************/
void CInputDlg::OnOK()
{
	NextDlgCtrl();
	CWnd *p = GetFocus();
	if (p->GetDlgCtrlID() == IDOK)
	{

	}
	free(p);
}
