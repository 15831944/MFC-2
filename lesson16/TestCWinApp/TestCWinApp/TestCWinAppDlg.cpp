#include "stdafx.h"
#include "TestCWinApp.h"
#include "TestCWinAppDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

/**************************************************************
part 4 ����ͼ��
	1) m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	2) m_hIcon = ::LoadIcon(theApp.m_hInstance, (LPCTSTR)IDR_MAINFRAME);
**************************************************************/
/**************************************************************
part 5 ����ϵͳͼ��()
	1) m_hIcon = AfxGetApp()->LoadStandardIcon(IDI_ERROR);
	2) m_hIcon = theApp.LoadStandardIcon(IDI_ERROR);
	3) m_hIcon = ::LoadIcon(NULL, IDI_ERROR);
**************************************************************/

/*************************************************
part 6 �������ͼ��
	1) m_hCur = ::LoadCursor(theApp.m_hInstance, (LPCTSTR)IDC_CURPEN);
*************************************************/
CTestCWinAppDlg::CTestCWinAppDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_TESTCWINAPP_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	//m_hIcon = ::LoadIcon(theApp.m_hInstance, (LPCTSTR)IDR_MAINFRAME);
	//m_hIcon = AfxGetApp()->LoadStandardIcon(IDI_ERROR);
	//m_hIcon = theApp.LoadStandardIcon(IDI_ERROR);
	//m_hIcon = ::LoadIcon(NULL, IDI_ERROR);

	m_hCur = ::LoadCursor(theApp.m_hInstance, (LPCTSTR)IDC_CURPEN);
}

void CTestCWinAppDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CTestCWinAppDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

/*************************************************
part 2 ���캯���������ʼ��
	1) CTestCWinAppApp::CTestCWinAppApp():CWinApp(_T("��ܰ��ʾ: "))
	MessageBox(_T("O"));�ı��ⶼΪ(_T("��ܰ��ʾ: "))
*************************************************/

BOOL CTestCWinAppDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��


	//MessageBox(_T("O"));
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CTestCWinAppDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������
		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}
HCURSOR CTestCWinAppDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


/*************************************************
part 7 �������ͼ��
	1) SetCursor(m_hCur);
*************************************************/
void CTestCWinAppDlg::OnMouseMove(UINT nFlags, CPoint point)
{
	SetCursor(m_hCur);

	CDialogEx::OnMouseMove(nFlags, point);
}
