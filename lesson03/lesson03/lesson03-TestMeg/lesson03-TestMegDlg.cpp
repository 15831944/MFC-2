
// lesson03-TestMegDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "lesson03-TestMeg.h"
#include "lesson03-TestMegDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Clesson03TestMegDlg �Ի���



Clesson03TestMegDlg::Clesson03TestMegDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_LESSON03TESTMEG_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void Clesson03TestMegDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(Clesson03TestMegDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_ADD, &Clesson03TestMegDlg::OnBnClickedAdd)
	ON_BN_CLICKED(IDC_SUB, &Clesson03TestMegDlg::OnBnClickedSub)
	ON_BN_CLICKED(IDC_MUL, &Clesson03TestMegDlg::OnBnClickedMul)
	ON_BN_CLICKED(IDC_DIVI, &Clesson03TestMegDlg::OnBnClickedDivi)
END_MESSAGE_MAP()


// Clesson03TestMegDlg ��Ϣ�������

BOOL Clesson03TestMegDlg::OnInitDialog()
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

void Clesson03TestMegDlg::OnPaint()
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
HCURSOR Clesson03TestMegDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void Clesson03TestMegDlg::OnBnClickedAdd()
{
	int nLeft = GetDlgItemInt(IDC_LPARAM1, NULL, TRUE);
	int nRight = GetDlgItemInt(IDC_RPARAM1);
	SetDlgItemInt(IDC_RESULT1, nLeft + nRight);
}


void Clesson03TestMegDlg::OnBnClickedSub()
{
	int nLeft = GetDlgItemInt(IDC_LPARAM2, NULL, TRUE);
	int nRight = GetDlgItemInt(IDC_RPARAM2);
	SetDlgItemInt(IDC_RESULT2, nLeft - nRight);
}


void Clesson03TestMegDlg::OnBnClickedMul()
{
	int nLeft = GetDlgItemInt(IDC_LPARAM3, NULL, TRUE);
	int nRight = GetDlgItemInt(IDC_RPARAM3);
	SetDlgItemInt(IDC_RESULT3, nLeft * nRight);
}


void Clesson03TestMegDlg::OnBnClickedDivi()
{
	int nRight = GetDlgItemInt(IDC_RPARAM4);
	if (0 == nRight)
	{
		SetDlgItemText(IDC_RESULT4, _T("����������Ϊ0���"));
		return;
	}
	int nLeft = GetDlgItemInt(IDC_LPARAM4, NULL, TRUE);

	SetDlgItemInt(IDC_RESULT4, nLeft / nRight);
}
