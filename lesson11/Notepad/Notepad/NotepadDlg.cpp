#include "stdafx.h"
#include "Notepad.h"
#include "NotepadDlg.h"
#include "afxdialogex.h"
#include "AboutDlg.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif

CNotepadDlg::CNotepadDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_NOTEPAD_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	
}

void CNotepadDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CNotepadDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_COMMAND(ID_OnAppExit, &CNotepadDlg::OnOnappexit)
	ON_WM_DROPFILES()
	ON_COMMAND(ID_APP_ABOUT, &CNotepadDlg::OnAppAbout)
	ON_WM_SIZE()
	ON_WM_CLOSE()
	ON_COMMAND(ID_EDIT_CLEAR, &CNotepadDlg::OnEditClear)
	ON_COMMAND(ID_EDIT_COPY, &CNotepadDlg::OnEditCopy)
	ON_COMMAND(ID_EDIT_CUT, &CNotepadDlg::OnEditCut)
	ON_COMMAND(ID_EDIT_DATE, &CNotepadDlg::OnEditDate)
	ON_COMMAND(ID_EDIT_FIND, &CNotepadDlg::OnEditFind)
	ON_COMMAND(ID_EDIT_FINDNET, &CNotepadDlg::OnEditFindnet)
	ON_COMMAND(ID_EDIT_GO, &CNotepadDlg::OnEditGo)
	ON_COMMAND(ID_EDIT_PASTE, &CNotepadDlg::OnEditPaste)
	ON_COMMAND(ID_EDIT_REPLACE, &CNotepadDlg::OnEditReplace)
	ON_COMMAND(ID_EDIT_UNDO, &CNotepadDlg::OnEditUndo)
	ON_COMMAND(ID_EDIT_SELECT_ALL, &CNotepadDlg::OnEditSelectAll)
END_MESSAGE_MAP()

BOOL CNotepadDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	m_hAccel = ::LoadAccelerators(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDR_MAIN));
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CNotepadDlg::OnPaint()
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

HCURSOR CNotepadDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CNotepadDlg::OnOK()
{
	//CDialogEx::OnOK();
}

/***************************************************************
	part 3 不要用Cancel消息,,按Esc都能出发
***************************************************************/
void CNotepadDlg::OnCancel()
{
	//CDialogEx::OnCancel();
}
/***************************************************************
	part 4 用这个系统关闭
***************************************************************/
void CNotepadDlg::OnClose()
{
	EndDialog(IDCANCEL);
	//CDialogEx::OnClose();
}



void CNotepadDlg::OnOnappexit()
{
	EndDialog(IDCANCEL);
}

/***************************************************************
	part 1 抓多文件丢进程序内(多文档读取)
	TCHAR sFile[256];
	int nCount = DragQueryFile(hDropInfo, -1, NULL, 0);
	int i = 0;
	while (i < nCount)
	{
		DragQueryFile(hDropInfo, i, sFile, _countof(sFile));

		//doing ni your operation

		++i;
	}
***************************************************************/
/***************************************************************
	part 2 抓多文件丢进程序内(只读第一个)
	TCHAR sFile[256];
	int nCount = DragQueryFile(hDropInfo, 0, sFile, _countof(sFile));
***************************************************************/
/***************************************************************
	part 10 Windows记事本文件的字符串类别:
		1) ANSI: 
		2) Unicode: 0x5C 0x75 0x46 0x45 0x46 0x46: 文件开头. 
					宽字符,包括文字,数字,符号都占两个字节,无重复
		3) UTF-8: 0xEF 0xBB 0xBF: 文件开头. 
					单字节字符文本, 并且各国文字统一无重复
		4) UTF-16: 0xFF 0xFE: 文件开头
***************************************************************/
/***************************************************************
	part 11 file.Read(Conten, _countof(Conten))越界了
		当read读满_countof(Conten)时,不-1就越界了
			file.Read(Conten, _countof(Conten) - 1)
***************************************************************/
void CNotepadDlg::OnDropFiles(HDROP hDropInfo)
{
	TCHAR sFile[256];
	TCHAR Conten[4096] = { 0 };
	int nCount = DragQueryFile(hDropInfo, 0, sFile, _countof(sFile));
	CFile file;
	if (!file.Open(sFile, CFile::modeRead))
	{
		AfxMessageBox(_T("文件不存在!\n"));
		return;
	}
	ULONGLONG FileLength = file.GetLength();
	int nub = 0;

	nub = file.Read(Conten,8);
	Conten[nub] = '\0';

	if (Conten[0] == 0x755c && Conten[1] == 0x4546 && Conten[2] == 0x4646)
	{

		while (nub = file.Read(Conten, _countof(Conten) - 1))
		{
			Conten[nub] = _T('\0');

		}
		
	}
	else if (Conten[0] == 0xbbef)
	{

		while (nub = file.Read(Conten, _countof(Conten) - 1))
		{
			Conten[nub] = _T('\0');

		}
	}
	else if (Conten[0] == 0xfeff)
	{

		while (nub = file.Read(Conten, _countof(Conten) - 1))
		{
			Conten[nub] = _T('\0');			
		}
		//获取转换为多字节后需要的缓冲区大小，创建多字节缓冲区
		UINT nLen = MultiByteToWideChar(CP_UTF8, NULL, strUTF8, -1, NULL, NULL);
		WCHAR *wszBuffer = new WCHAR[nLen + 1];
		nLen = MultiByteToWideChar(CP_UTF8, NULL, strUTF8, -1, wszBuffer, nLen);
		wszBuffer[nLen] = 0;

		nLen = WideCharToMultiByte(936, NULL, wszBuffer, -1, NULL, NULL, NULL, NULL);
		CHAR *szBuffer = new CHAR[nLen + 1];
		nLen = WideCharToMultiByte(936, NULL, wszBuffer, -1, szBuffer, nLen, NULL, NULL);
		szBuffer[nLen] = 0;
		strUTF8 = szBuffer;
		//清理内存
		delete[]szBuffer;
		delete[]wszBuffer;
	}
	else
	{

		while (nub = file.Read(Conten, _countof(Conten) - 1))
		{
			Conten[nub] = _T('\0');

		}
	}
	//SetDlgItemText(IDC_TEXT, str);
	SetDlgItemText(IDC_TEXT, Conten);
	file.Close();
	CDialogEx::OnDropFiles(hDropInfo);
}


void CNotepadDlg::OnAppAbout()
{
	CAboutDlg dlg;
	dlg.DoModal();
}

/***************************************************************
	part 7 窗口可以伸缩放大缩小
		重定义OnSize函数:
		void CNotepadDlg::OnSize(UINT nType, int cx, int cy)
		{
			CDialogEx::OnSize(nType, cx, cy);
			CWnd *p = GetDlgItem(IDC_TEXT);
			if (p)
			{
			CRect rect;
			GetClientRect(rect);
			p->MoveWindow(rect);
			}
		}

***************************************************************/
void CNotepadDlg::OnSize(UINT nType, int cx, int cy)
{
	CDialogEx::OnSize(nType, cx, cy);
	CWnd *p = GetDlgItem(IDC_TEXT);
	if (p)
	{
		CRect rect;
		GetClientRect(rect);
		p->MoveWindow(rect);
	}
}



/***********************************************************
	part 5 获取基类指针,有基类函数可调用
		CWnd* pEdit = GetDlgItem(IDC_TEXT);
***********************************************************/
/***********************************************************
	part 6 获取子类指针,有子类函数可调用
		CEdit* pEdit = (CEdit*)GetDlgItem(IDC_TEXT);
***********************************************************/
void CNotepadDlg::OnEditClear()
{
	//CWnd* pEdit = GetDlgItem(IDC_TEXT);
	CEdit* pEdit = (CEdit*)GetDlgItem(IDC_TEXT);
	pEdit->Clear();
}


void CNotepadDlg::OnEditCopy()
{
	CEdit* pEdit = (CEdit*)GetDlgItem(IDC_TEXT);
	pEdit->Copy();
}


void CNotepadDlg::OnEditCut()
{
	CEdit* pEdit = (CEdit*)GetDlgItem(IDC_TEXT);
	pEdit->Cut();
}

/***********************************************************
	part 8 Edit Control光标位置插入字符串
		CEdit* pEdit = (CEdit*)GetDlgItem(IDC_TEXT);
		pEdit->ReplaceSel(str)
***********************************************************/
void CNotepadDlg::OnEditDate()
{
	COleDateTime time = COleDateTime::GetCurrentTime();
	CString str = time.Format(_T("%H:%M %Y/%m/%d %A"));
	//SetDlgItemText(IDC_TEXT, str);
	CEdit* pEdit = (CEdit*)GetDlgItem(IDC_TEXT);
	pEdit->ReplaceSel(str);
}


void CNotepadDlg::OnEditFind()
{

}


void CNotepadDlg::OnEditFindnet()
{
	// TODO: 在此添加命令处理程序代码
}


void CNotepadDlg::OnEditGo()
{
	// TODO: 在此添加命令处理程序代码
}


void CNotepadDlg::OnEditPaste()
{
	CEdit* pEdit = (CEdit*)GetDlgItem(IDC_TEXT);
	pEdit->Paste();
}


void CNotepadDlg::OnEditReplace()
{
	CEdit* pEdit = (CEdit*)GetDlgItem(IDC_TEXT);
	//pEdit->ReplaceSel();
}


void CNotepadDlg::OnEditUndo()
{
	CEdit* pEdit = (CEdit*)GetDlgItem(IDC_TEXT);
	pEdit->Undo();
}


void CNotepadDlg::OnEditSelectAll()
{
	CEdit* pEdit = (CEdit*)GetDlgItem(IDC_TEXT);
	pEdit->SetSel(0, -1);
}

/***********************************************************
	part 9 快捷键设置
		1) 在资源视图中添加资源，选择"Accelerator"
		2) 编辑其中包括ID、修饰符、键
		3) 头文件中添加快捷键变量: HACCEL m_hAccel
		4) OnInitDialog函数初始化:
			m_hAccel = ::LoadAccelerators(AfxGetInstanceHandle(), MAKEINTRESOURCE(Accelerator的ID));
		5)	编写以下代码: 
***********************************************************/
BOOL CNotepadDlg::PreTranslateMessage(MSG* pMsg)
{
	int iResult;
	switch (pMsg->message)
	{
	case WM_KEYDOWN:
	case WM_SYSKEYDOWN:
		iResult = TranslateAccelerator(m_hWnd, m_hAccel, pMsg);//翻译加速键表。该函数处理菜单命令中的加速键。
		if (iResult == ID_EDIT_DATE)
		{
			OnEditDate();
			return true;
		}
		if (iResult == ID_EDIT_DATE)
		{
			OnEditSelectAll();
			return true;
		}
		break;
	}
	return CDialogEx::PreTranslateMessage(pMsg);
}
