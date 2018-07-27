#include "stdafx.h"
#include "Send_Post_MFC.h"
#include "Send_Post_MFCDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

/*************************************************
	part 3 自定义消息
*************************************************/
enum
{
	UM_ADD = WM_USER + 100
};
CSend_Post_MFCDlg::CSend_Post_MFCDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_SEND_POST_MFC_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CSend_Post_MFCDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CSend_Post_MFCDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_SEND, &CSend_Post_MFCDlg::OnBnClickedSend)
	ON_BN_CLICKED(IDC_POST, &CSend_Post_MFCDlg::OnBnClickedPost)
	ON_WM_CLOSE()
	ON_MESSAGE(UM_ADD, &CSend_Post_MFCDlg::OnUmAdd)
END_MESSAGE_MAP()

BOOL CSend_Post_MFCDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CSend_Post_MFCDlg::OnPaint()
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

HCURSOR CSend_Post_MFCDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


/*************************************************
	part 1 一个直接发给对象,而且等待对象反馈
*************************************************/
/*************************************************
	part 5 如果在同一个线程内
		可以使用SendMessage,这样可能很快得到消息结果
*************************************************/
void CSend_Post_MFCDlg::OnBnClickedSend()
{
	LRESULT nRet = SendMessage(UM_ADD, 1000, -12);
	if (nRet == 988)
	{
		AfxMessageBox(_T("YES\n"));
	}
}

/*************************************************
	part 2 一个直接发给邮局,邮局再通知
		 发完信件,继续做我的事
*************************************************/
/*************************************************
	part 6 如果在不同线程内
		使用PostMessage,这样可以不跟人抢线程而造成柱塞
*************************************************/
void CSend_Post_MFCDlg::OnBnClickedPost()
{
	BOOL bo = PostMessage(WM_CLOSE);
	if (bo)
	{
		AfxMessageBox(_T("YES\n"));
	}

}


void CSend_Post_MFCDlg::OnClose()
{
	Sleep(2000);
	if(IDYES == MessageBox(_T("要走了吗?\n"), _T("温馨提醒"), MB_YESNO))
		CDialogEx::OnClose();
}

/*************************************************
	part 4 自定义消息函数
		类视图->右键对应窗口类->类向导->消息->添加自定义消息
*************************************************/
afx_msg LRESULT CSend_Post_MFCDlg::OnUmAdd(WPARAM wParam, LPARAM lParam)
{
	Sleep(2000);
	CString str;
	str.Format(_T("%d"), wParam + lParam);
	MessageBox(str, _T("温馨提醒"), MB_YESNO);
	return 0;
}
