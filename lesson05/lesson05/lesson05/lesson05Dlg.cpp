
// lesson05Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "lesson05.h"
#include "lesson05Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Clesson05Dlg �Ի���



Clesson05Dlg::Clesson05Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_LESSON05_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void Clesson05Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(Clesson05Dlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_ADD, &Clesson05Dlg::OnBnClickedAdd)
	ON_BN_CLICKED(IDC_SUB, &Clesson05Dlg::OnBnClickedSub)
	ON_BN_CLICKED(IDC_MUL, &Clesson05Dlg::OnBnClickedMul)
	ON_BN_CLICKED(IDC_DIVI, &Clesson05Dlg::OnBnClickedDivi)
	ON_COMMAND(ID_MENU_CANCEL, &Clesson05Dlg::OnMenuCancel)
END_MESSAGE_MAP()


/*****************************************************
	part 3 ϵͳ�Զ��ӹ���Щ��Ϣ
	1)	WM_INITDIALG
	2)	WM_COMMAND
	3)	IDOK
	4)	IDCANCEL
*****************************************************/
void Clesson05Dlg::OnOK()
{
}
void Clesson05Dlg::OnCancel()
{
	CDialog::OnCancel();
}
BOOL Clesson05Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void Clesson05Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

HCURSOR Clesson05Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void Clesson05Dlg::OnBnClickedAdd()
{
	CString tmp;
	GetDlgItemText(IDC_LPARAM1, tmp);
	double fleft = _tstof(tmp);
	GetDlgItemText(IDC_RPARAM1, tmp);
	double fright = _tstof(tmp);
	tmp.Format(_T("%lf"), fleft + fright);
	SetDlgItemText(IDC_RESULT1, tmp);
}


void Clesson05Dlg::OnBnClickedSub()
{
	CString tmp;
	GetDlgItemText(IDC_LPARAM2, tmp);
	double fleft = _tstof(tmp);
	GetDlgItemText(IDC_RPARAM2, tmp);
	double fright = _tstof(tmp);
	tmp.Format(_T("%lf"), fleft - fright);
	SetDlgItemText(IDC_RESULT2, tmp);
}


void Clesson05Dlg::OnBnClickedMul()
{
	CString tmp;
	GetDlgItemText(IDC_LPARAM3, tmp);
	double fleft = _tstof(tmp);
	GetDlgItemText(IDC_RPARAM3, tmp);
	double fright = _tstof(tmp);
	tmp.Format(_T("%lf"), fleft * fright);
	SetDlgItemText(IDC_RESULT3, tmp);
}


void Clesson05Dlg::OnBnClickedDivi()
{
	CString tmp;//, tmp_right, tmp_result;
	GetDlgItemText(IDC_LPARAM4, tmp);
	double fleft = _tstof(tmp);
	GetDlgItemText(IDC_RPARAM4, tmp);
	double fright = _tstof(tmp);
	if (0 == fright)
	{
		SetDlgItemText(IDC_RESULT4, _T("����������Ϊ0��Ϊ��"));
		return;
	}
	tmp.Format(_T("%lf"), fleft / fright);
	SetDlgItemText(IDC_RESULT4, tmp);
}


void Clesson05Dlg::OnMenuCancel()
{
	CDialog::OnCancel();
}
