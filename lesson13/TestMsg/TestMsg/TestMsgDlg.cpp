#include "stdafx.h"
#include "TestMsg.h"
#include "TestMsgDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

CTestMsgDlg::CTestMsgDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_TESTMSG_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTestMsgDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CTestMsgDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_CREATE()
	ON_WM_SYSCOMMAND()
	ON_WM_CLOSE()
	ON_WM_DESTROY()
END_MESSAGE_MAP()


/*********************************************************
	part 2 OnInitDialog初始化了子控件

*********************************************************/
BOOL CTestMsgDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	CListCtrl* pList = (CListCtrl*)GetDlgItem(IDC_LIST);

	pList->InsertColumn(0, _T("工号"), LVCFMT_LEFT, 100);
	pList->InsertColumn(1, _T("姓名"), LVCFMT_LEFT, 150);
	pList->InsertColumn(2, _T("工资"), LVCFMT_LEFT, 150);
	pList->InsertColumn(3, _T("入职日期"), LVCFMT_LEFT, 246);

	pList->SetBkColor(RGB(205, 226, 252));
	pList->SetTextBkColor(RGB(205, 226, 252));
	pList->SetTextColor(RGB(0, 0, 255));




	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CTestMsgDlg::OnPaint()
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

HCURSOR CTestMsgDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

/*********************************************************
	part 0 WM_CREATE, WM_INITDLALOG对比

*********************************************************/
/*********************************************************
	part 1 WM_CREATE比WM_INITDLALOG还先执行
		窗口中子类空间还没被创建好
		失败:
			pList->InsertColumn(0, _T("工号"), 0, 100);
*********************************************************/
/*********************************************************
	part 3 对父窗口进行操作是没问题的
		窗口父类已经创建好
		成功:
			SetIcon(m_hIcon, TRUE);			// 设置大图标
			SetIcon(m_hIcon, FALSE);		// 设置小图标
*********************************************************/
int CTestMsgDlg::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CDialogEx::OnCreate(lpCreateStruct) == -1)
		return -1;

	//CListCtrl* pList = (CListCtrl*)GetDlgItem(IDC_LIST);
	//pList->InsertColumn(0, _T("工号"), 0, 100);

	//SetIcon(m_hIcon, TRUE);			// 设置大图标
	//SetIcon(m_hIcon, FALSE);		// 设置小图标

	return 0;
}

/*********************************************************
	part 4 PreSubclassWindow比 WM_CREATE和 WM_INITDLALOG还先执行
		父窗体已经创建好了
		成功:
			SetIcon(m_hIcon, TRUE);			// 设置大图标
			SetIcon(m_hIcon, FALSE);		// 设置小图标
*********************************************************/
void CTestMsgDlg::PreSubclassWindow()
{
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	CDialogEx::PreSubclassWindow();
}

/*********************************************************
	part 5 系统关闭过程: WM_SYSCOMMAND->WM_CLOSE->OnCancel->WM_DESTROY
		当程序运行到WM_DESTORY时候,程序真正的关闭了
		1) WM_SYSCOMMAND:是对所有系统菜单中的命令管理(包括: 最大/小化, 移动, 关闭...(F1进去看))
*********************************************************/
void CTestMsgDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	//if (nID == SC_CLOSE)
	//{
	//	ShowWindow(SW_MINIMIZE);
	//	return;
	//}
	CDialogEx::OnSysCommand(nID, lParam);//执行缺省任务,相当于,我什么也没做,它帮我处理

}


void CTestMsgDlg::OnClose()
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	CDialogEx::OnClose();
}


/*********************************************************
	part 6 自行关闭过程: OnCancel->WM_DESTROY

*********************************************************/
void CTestMsgDlg::OnCancel()
{
	CDialogEx::OnCancel();
}

/*********************************************************
	part 7 窗口和控件的毁灭函数
		CDialogEx::OnDestroy();
*********************************************************/
void CTestMsgDlg::OnDestroy()
{


	CDialogEx::OnDestroy();

	// TODO: 在此处添加消息处理程序代码
}


