#include "stdafx.h"
#include "TestW.h"
#include "TestWDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

CTestWDlg::CTestWDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_TESTW_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTestWDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CTestWDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_ANIMATE, &CTestWDlg::OnBnClickedAnimate)
	ON_WM_SHOWWINDOW()
	ON_WM_CLOSE()
	ON_BN_CLICKED(IDC_DESTROY, &CTestWDlg::OnBnClickedDestroy)
	ON_BN_CLICKED(IDC_CREATE, &CTestWDlg::OnBnClickedCreate)
	ON_BN_CLICKED(IDC_GetSafe, &CTestWDlg::OnBnClickedGetsafe)
	ON_BN_CLICKED(IDC_FromHandle, &CTestWDlg::OnBnClickedFromhandle)
END_MESSAGE_MAP()


/**********************************************************
part 1 窗口花样显示
	1)	AnimateWindow(500, AW_VER_NEGATIVE);
**********************************************************/
BOOL CTestWDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	//AnimateWindow(500, AW_VER_NEGATIVE);
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}


void CTestWDlg::OnPaint()
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

HCURSOR CTestWDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CTestWDlg::OnBnClickedAnimate()
{
	AnimateWindow(200, IDC_ANIMATE);
}

/**********************************************************
part 2 窗口花样显示(在初始化显示窗口不居中,在showWindow)
	1)	AnimateWindow(500, AW_VER_NEGATIVE);
**********************************************************/
void CTestWDlg::OnShowWindow(BOOL bShow, UINT nStatus)
{
	CDialogEx::OnShowWindow(bShow, nStatus);

	AnimateWindow(500, AW_VER_NEGATIVE);
}


void CTestWDlg::OnClose()
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	AnimateWindow(500, AW_VER_NEGATIVE);
	CDialogEx::OnClose();
	
}

/**********************************************************
part 3 摧毁窗口句柄
	1)	DestroyWindow();
	//EndDialog(-1);摧毁也是窗口,还没把指针置空
	//摧毁窗口句柄
	//this->DestroyWindow();
	//摧毁OK消息句柄
	//GetDlgItem(IDOK)->DestroyWindow();
**********************************************************/

void CTestWDlg::OnBnClickedDestroy()
{
	//CWnd* pWnd = FindWindow(_T("Notepad"), NULL);
	//pWnd->DestroyWindow();
	GetDlgItem(IDOK)->DestroyWindow();
}

/**********************************************************
part 3 创建窗口句柄
	1)	Create(_T("ButtON"), _T("确定"), WS_CHILD | WS_VISIBLE, CRect(0, 0, 60, 30), this, IDOK);
	2)	第一个参数: 分类名
	3) 	CWnd *edit = new CWnd;
		edit->Create(_T("Edit"), _T("确定"), WS_CHILD | WS_VISIBLE,
		CRect(400, 280, 500, 305), this, IDOK);
**********************************************************/
/**********************************************************
part 4 获取当前字体
	1)	CFont* pFont = GetFont();
	2)	设置字体ok->SetFont(pFont);
**********************************************************/
/**********************************************************
part 5 用基类创建子类的方法: CWnd
	1) 	CWnd *ok = new CWnd;
		ok->Create(_T("ButtON"), _T("确定"), WS_CHILD | WS_VISIBLE,
			CRect(400, 280, 500, 305), this, IDOK);
		CFont* pFont = GetFont();
		ok->SetFont(pFont);
**********************************************************/
/**********************************************************
part 6 子类创建窗口的方法: CEdit
	1)	CEdit *edit = new CEdit;
		edit->Create(WS_CHILD | WS_VISIBLE | WS_BORDER | ES_MULTILINE | ES_WANTRETURN, CRect(400, 111, 500, 280), this, 8888);
		CFont* pFont = GetFont();
		edit->SetFont(pFont);
**********************************************************/
/**********************************************************
part 7 子类列表创建: CListCtrl

void CTestWDlg::OnBnClickedCreate()
{
	CListCtrl *pList = new CListCtrl;
	pList->Create(WS_CHILD | WS_VISIBLE | LVS_REPORT, CRect(10, 111, 500, 280), this, 8888);
	CFont* pFont = GetFont();
	pList->SetFont(pFont);

	pList->InsertColumn(0, _T("工号"), 0, 100);
	pList->InsertColumn(1, _T("姓名"), 0, 100);
	pList->InsertColumn(2, _T("工资"), 0, 100);
	pList->InsertColumn(3, _T("入职日期"), 0, 100);

}
**********************************************************/

/**********************************************************
part 8	基类创建列表控件(没有下陷风格)

void CTestWDlg::OnBnClickedCreate()
{
	CWnd *pCList = new CWnd;
	pCList->Create(_T("syslistview32"), NULL, WS_CHILD | WS_VISIBLE | LVS_REPORT, CRect(10, 111, 500, 280), this, 8888);
	CListCtrl* pList = (CListCtrl*)GetDlgItem(8888);
	pList->InsertColumn(0, _T("工号"), 0, 100);
	pList->InsertColumn(1, _T("姓名"), 0, 100);
	pList->InsertColumn(2, _T("工资"), 0, 100);
	pList->InsertColumn(3, _T("入职日期"), 0, 100);

	CFont* pFont = GetFont();
	pList->SetFont(pFont);
}
**********************************************************/
/**********************************************************
part 9	扩展基类创建列表控件(扩展了列表风格): CreateEX

void CTestWDlg::OnBnClickedCreate()
{
	CWnd *pCList = new CWnd;
	pCList->CreateEx(WS_EX_CLIENTEDGE, _T("syslistview32"), NULL, WS_CHILD | WS_VISIBLE | LVS_REPORT, CRect(10, 111, 500, 280), this, 8888);
	CListCtrl* pList = (CListCtrl*)GetDlgItem(8888);
	pList->InsertColumn(0, _T("工号"), 0, 100);
	pList->InsertColumn(1, _T("姓名"), 0, 100);
	pList->InsertColumn(2, _T("工资"), 0, 100);
	pList->InsertColumn(3, _T("入职日期"), 0, 100);

	CFont* pFont = GetFont();
	pList->SetFont(pFont);
}
**********************************************************/
/**********************************************************
part 10 基类创建按钮
**********************************************************/
CWnd m_ok;
void CTestWDlg::OnBnClickedCreate()
{
	//单例:按钮初始过后不再初始
	if (!m_ok.m_hWnd)
	{
		m_ok.Create(_T("Button"), _T("确定"), WS_CHILD | WS_VISIBLE | BS_AUTORADIOBUTTON | WS_TABSTOP
			, CRect(10, 50, 155, 69), this, 10088);
		CFont* pFont = GetFont();
		m_ok.SetFont(pFont);
	}
}

/**********************************************************
part 11 从对象获取句柄
	安全的Hwnd: GetSafeHwnd()
	1)	GetDlgItem(IDOK)->DestroyWindow();	
		HWND hWnd = pWnd->m_hWnd;	//如果m_hWnd被释放了
		程序就会奔溃

	2)	HWND hWnd = pWnd->GetSafeHwnd();
**********************************************************/
void CTestWDlg::OnBnClickedGetsafe()
{
	CWnd* pWnd = GetDlgItem(IDOK);
	HWND hWnd = pWnd->GetSafeHwnd();
}

/**********************************************************
part 12	从句柄获得对象
**********************************************************/
void CTestWDlg::OnBnClickedFromhandle()
{
	HWND hWnd = ::GetDlgItem(m_hWnd, IDOK);
	CWnd* pOk = CWnd::FromHandle(hWnd);
	pOk->SetWindowText(_T("OK"));
}