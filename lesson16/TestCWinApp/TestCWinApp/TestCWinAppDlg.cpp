#include "stdafx.h"
#include "TestCWinApp.h"
#include "TestCWinAppDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

/**************************************************************
part 4 导入图标
	1) m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	2) m_hIcon = ::LoadIcon(theApp.m_hInstance, (LPCTSTR)IDR_MAINFRAME);
**************************************************************/
/**************************************************************
part 5 导入系统图标()
	1) m_hIcon = AfxGetApp()->LoadStandardIcon(IDI_ERROR);
	2) m_hIcon = theApp.LoadStandardIcon(IDI_ERROR);
	3) m_hIcon = ::LoadIcon(NULL, IDI_ERROR);
**************************************************************/

/*************************************************
part 6 导入鼠标图案
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
part 2 构造函数给基类初始化
	1) CTestCWinAppApp::CTestCWinAppApp():CWinApp(_T("温馨提示: "))
	MessageBox(_T("O"));的标题都为(_T("温馨提示: "))
*************************************************/

BOOL CTestCWinAppDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标


	//MessageBox(_T("O"));
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CTestCWinAppDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文
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
part 7 设置鼠标图案
	1) SetCursor(m_hCur);
*************************************************/
void CTestCWinAppDlg::OnMouseMove(UINT nFlags, CPoint point)
{
	SetCursor(m_hCur);

	CDialogEx::OnMouseMove(nFlags, point);
}
