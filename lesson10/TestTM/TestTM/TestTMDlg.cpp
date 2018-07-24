#include "stdafx.h"
#include "TestTM.h"
#include "TestTMDlg.h"
#include "afxdialogex.h"

#include "MyTime.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

CTestTMDlg::CTestTMDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_TESTTM_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTestTMDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CTestTMDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_GET_TIME, &CTestTMDlg::OnBnClickedGetTime)
	ON_BN_CLICKED(IDC_BUTTON2, &CTestTMDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CTestTMDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CTestTMDlg::OnBnClickedButton4)
END_MESSAGE_MAP()

BOOL CTestTMDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CTestTMDlg::OnPaint()
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

HCURSOR CTestTMDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CTestTMDlg::OnBnClickedGetTime()
{
	time_t tt = time(NULL);
	//struct tm * pTime = localtime(&tt);

	tm tm1;
	//localtime_s ��ֹ tt ����
	//��localtime ��ȫ
	errno_t nErr = localtime_s(&tm1, &tt);

	CString str;
	str.Format(_T("%d��%d��%d�� %d:%d:%d"), 
		tm1.tm_year + 1900, tm1.tm_mon + 1, tm1.tm_mday, tm1.tm_hour, tm1.tm_min, tm1.tm_sec);
	AfxMessageBox(str);
}


void CTestTMDlg::OnBnClickedButton2()
{
	CMyTime time = CMyTime::GetCurrentTime();

	CString str;
	str.Format(_T("%d��%d��%d�� %d:%d:%d"), 
		time.GetYear(), time.GetMonth(), time.GetDay(), time.GetHour(), time.GetMinute(), time.GetSecond());
	AfxMessageBox(str);
}

/****************************************************
	part 1 Edit control����ֻ��
		GetDlgItemText(IDC_TIME_YEAR, str);
		SetDlgItemText(IDC_TIME_YEAR, str);
		GetDlgItem(IDC_TIME_YEAR)->EnableWindow(FALSE);
****************************************************/
/****************************************************
	part 2 Button��ť��������
		//CWnd *pWnd = GetDlgItem(IDC_BUTTON1);
		//pWnd->ModifyStyle(0, BS_AUTOCHECKBOX | BS_PUSHLIKE );
****************************************************/
void CTestTMDlg::OnBnClickedButton3()
{
	tm tms = { 15, 55, 12, 1, 12 - 1, 2015 - 1900 };
	time_t tt = mktime(&tms);

	CString str;
	str.Format(_T("%d��%d��%d�� %d:%d:%d"),
		tms.tm_year + 1900, tms.tm_mon + 1, tms.tm_mday, tms.tm_hour, tms.tm_min, tms.tm_sec);
	AfxMessageBox(str);
	
	GetDlgItemText(IDC_TIME_YEAR, str);
	SetDlgItemText(IDC_TIME_YEAR, str);
	GetDlgItem(IDC_TIME_YEAR)->EnableWindow(FALSE);
	
	//CWnd *pWnd = GetDlgItem(IDC_BUTTON1);
	//pWnd->ModifyStyle(0, BS_AUTOCHECKBOX | BS_PUSHLIKE );
	
	//GetDlgItem(IDC_TIME_YEAR)->SetFocus();
}




void CTestTMDlg::OnBnClickedButton4()
{
	CMyTime time(2018, 12, 31, 19, 58, 55);
	//time.GetAsSystemTime
	CString str;
	str.Format(_T("%d��%d��%d�� %d:%d:%d"),
		time.GetYear(), time.GetMonth(), time.GetDay(), time.GetHour(), time.GetMinute(), time.GetSecond());
	AfxMessageBox(str);
}
