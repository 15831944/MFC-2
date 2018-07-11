
// lesson04-MFC������Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "lesson04-MFC������.h"
#include "lesson04-MFC������Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Clesson04MFC������Dlg �Ի���



Clesson04MFC������Dlg::Clesson04MFC������Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_LESSON04MFC_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void Clesson04MFC������Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(Clesson04MFC������Dlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDRESULT1, &Clesson04MFC������Dlg::OnBnClickedResult1)
	ON_BN_CLICKED(IDRESULT2, &Clesson04MFC������Dlg::OnBnClickedResult2)
	ON_BN_CLICKED(IDRESULT3, &Clesson04MFC������Dlg::OnBnClickedResult3)
	ON_BN_CLICKED(IDRESULT4, &Clesson04MFC������Dlg::OnBnClickedResult4)
END_MESSAGE_MAP()


// Clesson04MFC������Dlg ��Ϣ�������

BOOL Clesson04MFC������Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void Clesson04MFC������Dlg::OnPaint()
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

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR Clesson04MFC������Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void Clesson04MFC������Dlg::OnBnClickedResult1()
{
	CString tmp;
	GetDlgItemText(IDC_LPARAM1, tmp);
	double fleft = _tstof(tmp);
	GetDlgItemText(IDC_RPARAM1, tmp);
	double fright = _tstof(tmp);
	tmp.Format(_T("%lf"), fleft + fright);
	SetDlgItemText(IDC_RESULT1, tmp);
}


void Clesson04MFC������Dlg::OnBnClickedResult2()
{
	CString tmp;
	GetDlgItemText(IDC_LPARAM2, tmp);
	double fleft = _tstof(tmp);
	GetDlgItemText(IDC_RPARAM2, tmp);
	double fright = _tstof(tmp);
	tmp.Format(_T("%lf"), fleft - fright);
	SetDlgItemText(IDC_RESULT2, tmp);

}


void Clesson04MFC������Dlg::OnBnClickedResult3()
{
	CString tmp;
	GetDlgItemText(IDC_LPARAM3, tmp);
	double fleft = _tstof(tmp);
	GetDlgItemText(IDC_RPARAM3, tmp);
	double fright = _tstof(tmp);
	tmp.Format(_T("%lf"), fleft * fright);
	SetDlgItemText(IDC_RESULT3, tmp);
}


void Clesson04MFC������Dlg::OnBnClickedResult4()
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
