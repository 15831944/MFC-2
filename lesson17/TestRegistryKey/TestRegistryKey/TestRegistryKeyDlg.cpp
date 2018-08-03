#include "stdafx.h"
#include "TestRegistryKey.h"
#include "TestRegistryKeyDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

CTestRegistryKeyDlg::CTestRegistryKeyDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_TESTREGISTRYKEY_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTestRegistryKeyDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CTestRegistryKeyDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CTestRegistryKeyDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CTestRegistryKeyDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CTestRegistryKeyDlg::OnBnClickedButton3)
END_MESSAGE_MAP()

BOOL CTestRegistryKeyDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CTestRegistryKeyDlg::OnPaint()
{
	if (IsIconic()){
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
	else{
		CDialogEx::OnPaint();
	}
}

HCURSOR CTestRegistryKeyDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


/*************************************************
part 1 静止应用3秒,呈现出应用程序在忙
	1) 	theApp.DoWaitCursor(1);
		Sleep(3000);
		theApp.DoWaitCursor(0);

	2) 	CWaitCursor a;
		Sleep(3000);
*************************************************/
void CTestRegistryKeyDlg::OnBnClickedButton1()
{

	//theApp.DoWaitCursor(1);
	//Sleep(3000);
	//theApp.DoWaitCursor(0);

	CWaitCursor a;
	Sleep(3000);
}

/***************************************************
part 2 焦点循环(顺时针)
	1) CWnd *p = GetFocus();
	2) 	int nID = p->GetDlgCtrlID();
		if (nID < IDC_EDIT1 || nID > IDC_EDIT4)
			GetDlgItem(IDC_EDIT1)->SetFocus();
		else
			this->DlgCtrl();
***************************************************/
/***************************************************
part 3 焦点循环(逆时针)
	1)  if (nID < IDC_EDIT1 || nID > IDC_EDIT4)
		GetDlgItem(IDC_EDIT1)->SetFocus();
		else
		this->DlgCtrl();
***************************************************/
/***************************************************
part 4 焦点跳转函数
	1) GetDlgItem(IDC_EDIT1)->SetFocus();
	2) GotoDlgCtrl(GetDlgItem(IDC_EDIT1));
***************************************************/
/***************************************************
part 5 CDialog常用的类函数
	a) DoModal: 创建模式对话框
	b) Create:	创建非模式对话框
	c) NextDlgCtrl: 
	b) PrevDlgCtrl:
	e) GotoDlgCtrl:
	f) GetDefID:
	g) SetDefID:
***************************************************/
void CTestRegistryKeyDlg::OnOK()
{
	CWnd *p = GetFocus();
	if (!p)
	{
		return;
	}
	int nID = p->GetDlgCtrlID();
	if (nID < IDC_EDIT1 || nID > IDC_EDIT4)
	{
		//GetDlgItem(IDC_EDIT1)->SetFocus();
		GotoDlgCtrl(GetDlgItem(IDC_EDIT1));
	}
	else
	{
		this->NextDlgCtrl();
		//this->PrevDlgCtrl();
	}
}
/***************************************************
part 6 CDialog的派生类
	a) CColorDialog: Lets user select colors.
	b) CFileDialog:	 Lets user select a filename or replace to open to save.
	c) CFindReplaceDialog; Lets user initiate a find or replace operation in a text file
	d) CFontDialog: Lets user specity a font.
	e) CPrintDialog: Lets user sprcify information for a print job.
	f) CPrintDialogEx: Windows 2000 print property sheet.
***************************************************/
/**************************************************
part 7 截取第几位数据
	1)  #define LOBYTE(w)           ((BYTE)(((DWORD_PTR)(w)) & 0xff))
		#define GetRValue(rgb)      (LOBYTE(rgb))
		#define GetGValue(rgb)      (LOBYTE(((WORD)(rgb)) >> 8))
		#define GetBValue(rgb)      (LOBYTE((rgb)>>16))
**************************************************/
/**************************************************
part 8 TRACE(后台输出)
	1) 头文件: afx.h
**************************************************/
/**************************************************
part 9 设置背景颜色
	1) SetBackgroundColor(color);
**************************************************/
/**************************************************
part 11 设置调色器为独立窗口
	1) CColorDialog cdlg(0, 0, GetDesktopWindow());
**************************************************/
/**************************************************
part 12 设置调色器保留上次选项
	1) CColorDialog cdlg(m_color);
	2) m_color = cdlg.GetColor();
**************************************************/
void CTestRegistryKeyDlg::OnBnClickedButton2()
{
	
	//CColorDialog cdlg;
	//CColorDialog cdlg(0, 0, GetDesktopWindow());
	CColorDialog cdlg(m_color);
	if (cdlg.DoModal() == IDCANCEL)
	{
		return;
	}
	else
	{
		m_color = cdlg.GetColor();
		TRACE(_T("RGB value of the selected color - red = %u, ")
			_T("green = %u, blue = %u\n"),
			GetRValue(m_color), GetGValue(m_color), GetBValue(m_color));
		SetBackgroundColor(m_color);
	}	
}

/**************************************************
part 10 设置背景图片
	1) SetBackgroundImage(IDB_BITMAP);
	2)  BACKGR_TILE、
		BACKGR_TOPLEFT、
		BACKGR_TOPRIGHT、
		BACKGR_BOTTOMLEFT和BACKGR_BOTTOMRIGHT。 默认值为BACKGR_TILE。
**************************************************/
void CTestRegistryKeyDlg::OnBnClickedButton3()
{
	//SetBackgroundImage(IDB_BITMAP);
	SetBackgroundImage(IDB_BITMAP, BACKGR_BOTTOMLEFT);
}
