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
	ON_WM_DESTROY()
	ON_COMMAND(ID_FORMAT_FONT, &CNotepadDlg::OnFormatFont)
	ON_COMMAND(ID_FILE_OPEN, &CNotepadDlg::OnFileOpen)
	ON_COMMAND(ID_FILE_NEW, &CNotepadDlg::OnFileNew)
	ON_COMMAND(ID_FILE_SAVE, &CNotepadDlg::OnFileSave)
	ON_COMMAND(ID_FILE_SAVE_AS, &CNotepadDlg::OnFileSaveAs)
END_MESSAGE_MAP()


/************************************************
part 4 读取.INI 或 注册表 文件数据
	初始化先前窗口的位置和大小
	1) 	CRect rect;
		rect.left = theApp.GetProfileInt(_T("RECT"), _T("LEFT"), 0);
		rect.right = theApp.GetProfileInt(_T("RECT"), _T("RIGHT"), 0);
		rect.top = theApp.GetProfileInt(_T("RECT"), _T("TOP"), 0);
		rect.bottom = theApp.GetProfileInt(_T("RECT"), _T("BOTTOM"), 0);
		MoveWindow(rect, FALSE);
	初始化先前窗口的标题
	2) 	CString str;
		str = theApp.GetProfileString(_T("SETING"), _T("CAPTION"), 0);
		SetWindowText(str);
	
	3) 	LPBYTE pData = NULL;
		UINT len = sizeof(LOGFONT);
		theApp.GetProfileBinary(_T("Setting"), _T("Font"), &pData, &len);
		m_font.CreateFontIndirect((LOGFONT*)pData);
************************************************/
/************************************************
part 8 初始化先前窗口的字体
	1) 	LPBYTE pData = NULL;
		UINT len = sizeof(LOGFONT);
		theApp.GetProfileBinary(_T("Setting"), _T("Font"), &pData, &len);
		m_font.CreateFontIndirect((LOGFONT*)pData);
		GetDlgItem(IDC_TEXT)->SetFont(&m_font, FALSE);
************************************************/

/************************************************
part 9 内存申请监督
	NEW 监督宏
	1)  #ifdef _DEBUG
		#define new DEBUG_NEW
		#endif

	2)	NEW 一个对象没释放,输出就会提示:
		Detected memory leaks!
		Dumping objects ->
	    {210} normal block at 0x0042D800, 92 bytes long.
		Data: <                > EC FF FF FF 00 00 00 00 00 00 00 00 00 00 00 00 
		Object dump complete.
		有92个字节没释放

	3)	if(len > 0)
			delete []pData;

	4)	上面这样的内存泄露还不可怕,可怕的是那种,
		一点就申请内存,可不断申请没释放的
************************************************/
BOOL CNotepadDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	CRect rect;
	rect.left = theApp.GetProfileInt(_T("RECT"), _T("LEFT"), 0);
	rect.right = theApp.GetProfileInt(_T("RECT"), _T("RIGHT"), 0);
	rect.top = theApp.GetProfileInt(_T("RECT"), _T("TOP"), 0);
	rect.bottom = theApp.GetProfileInt(_T("RECT"), _T("BOTTOM"), 0);
	MoveWindow(rect, FALSE);

	CString str;
	str = theApp.GetProfileString(_T("SETING"), _T("CAPTION"), 0);
	SetWindowText(str);


	LPBYTE pData = NULL;
	UINT len = sizeof(LOGFONT);
	theApp.GetProfileBinary(_T("Setting"), _T("Font"), &pData, &len);
	m_font.CreateFontIndirect((LOGFONT*)pData);
	GetDlgItem(IDC_TEXT)->SetFont(&m_font, FALSE);
	if(len > 0)
		delete []pData;
	
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


void CNotepadDlg::OnCancel()
{
	//CDialogEx::OnCancel();
}

void CNotepadDlg::OnClose()
{
	EndDialog(IDCANCEL);
	//CDialogEx::OnClose();
}



void CNotepadDlg::OnOnappexit()
{
	EndDialog(IDCANCEL);
}


void UTF8toANSI(LPSTR buf)
{
	//获取转换为多字节后需要的缓冲区大小，创建多字节缓冲区
	UINT nLen = MultiByteToWideChar(CP_UTF8, NULL, buf, -1, NULL, NULL);
	WCHAR *wszBuffer = new WCHAR[nLen + 1];
	nLen = MultiByteToWideChar(CP_UTF8, NULL, buf, -1, wszBuffer, nLen);
	wszBuffer[nLen] = 0;

	nLen = WideCharToMultiByte(936, NULL, wszBuffer, -1, NULL, NULL, NULL, NULL);
	CHAR *szBuffer = new CHAR[nLen + 1];
	nLen = WideCharToMultiByte(936, NULL, wszBuffer, -1, szBuffer, nLen, NULL, NULL);
	szBuffer[nLen] = 0;
	buf = szBuffer;
	//清理内存
	delete[]szBuffer;
	delete[]wszBuffer;
}

void CNotepadDlg::ReadASCII(CFile& file)
{
	file.Seek(0, CFile::begin);
	char buf[1024];
	UINT nRet = 0;
	CString str;
	while (nRet = file.Read(buf, sizeof(buf) - 1))
	{
		buf[nRet] = '\0';
		str += buf;
	}
	SetDlgItemText(IDC_TEXT, str);
}

void CNotepadDlg::ReadUTF8(CFile& file)
{
	file.Seek(3, CFile::begin);
	LONGLONG nRet = file.GetLength();

	char *p = new char[nRet + 2];
	memset(p, 0, nRet + 2);

	nRet = file.Read(p, nRet);
	p[nRet] = '\0';
	TCHAR *pText = new TCHAR[nRet + 2];
	memset(pText, 0, nRet + 2);

	UINT nLen = MultiByteToWideChar(CP_UTF8, NULL, p, -1, pText, nRet + 2);

	SetDlgItemText(IDC_TEXT, pText);
	delete[]p;
	delete[]pText;
}

void CNotepadDlg::ReadUTF16(CFile& file)
{
	file.Seek(2, CFile::begin);
	ULONGLONG nRet = file.GetLength(); 
	TCHAR *pText = new TCHAR[nRet / 2 + 2];

	nRet = file.Read(pText, nRet);

	pText[nRet / 2] = '\0';
	SetDlgItemText(IDC_TEXT, pText);

	delete[]pText;
}

void CNotepadDlg::OnDropFiles(HDROP hDropInfo)
{
	TCHAR sFile[256];
	int nCount = DragQueryFile(hDropInfo, 0, sFile, _countof(sFile));
	LoadFile(sFile);
}

void CNotepadDlg::OnAppAbout()
{
	CAboutDlg dlg;
	dlg.DoModal();
}
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



/************************************************
part 1 关闭的最后一步
	1) 做保存数据,可以在最后一步执行
	2) CRect rect;
		GetWindowRect(rect);
		theApp.WriteProfileInt(_T("RECT"), _T("LEFT"), rect.left);

	3) theApp.WriteProfileString(_T("SETING"), _T("CAPTION"), _T("我的笔记本"));
************************************************/
/************************************************
part 7 保持修改后的字体格式
	1) 	if (m_font.GetSafeHandle())
		{
			LOGFONT lf;
			m_font.GetLogFont(&lf);
			BOOL RET = theApp.WriteProfileBinary(_T("Setting"), _T("Font"), (LPBYTE)&lf, sizeof(LOGFONT));
		}
************************************************/
void CNotepadDlg::OnDestroy()
{
	CRect rect;
	GetWindowRect(rect);
	theApp.WriteProfileInt(_T("RECT"), _T("LEFT"), rect.left);
	theApp.WriteProfileInt(_T("RECT"), _T("RIGHT"), rect.right);
	theApp.WriteProfileInt(_T("RECT"), _T("TOP"), rect.top);
	theApp.WriteProfileInt(_T("RECT"), _T("BOTTOM"), rect.bottom);
	//theApp.WriteProfileString(_T("SETING"), _T("CAPTION"), _T("我的笔记本"));

	if (m_font.GetSafeHandle())
	{
		LOGFONT lf;
		m_font.GetLogFont(&lf);
		BOOL RET = theApp.WriteProfileBinary(_T("Setting"), _T("Font"), (LPBYTE)&lf, sizeof(LOGFONT));
	}

	CDialogEx::OnDestroy();
}

/************************************************
part 5 设置字体格式
	1) _font.DeleteObject();	//	先释放,才能重新创建字体
	2) m_font.CreateFontIndirect(&lf);	//	对象初始化
	
void CNotepadDlg::OnFormatFont()
{
	CFontDialog dlg;
	if (dlg.DoModal() == IDCANCEL)
		return;
	LOGFONT lf;
	m_font.DeleteObject();
	dlg.GetCurrentFont(&lf);
	m_font.CreateFontIndirect(&lf);
	GetDlgItem(IDC_TEXT)->SetFont(&m_font);
}
************************************************ /
/************************************************
part 6 保留先前字体设置
	1) GetSafeHandle()	//判断对象是否初始化
	2) GetFont();	//获取一个窗口设置好的字体指针
	3) GetLogFont()	//解析出字体指针的结构体
************************************************/
void CNotepadDlg::OnFormatFont()
{
	LOGFONT lf;
	CFont* pFont = NULL;
	if (m_font.GetSafeHandle())
		pFont = &m_font;
	else
		pFont = GetFont();
	pFont->GetLogFont(&lf);

	CFontDialog dlg(&lf);

	if (dlg.DoModal() == IDCANCEL)
		return;	
	m_font.DeleteObject();
	dlg.GetCurrentFont(&lf);
	m_font.CreateFontIndirect(&lf);
	GetDlgItem(IDC_TEXT)->SetFont(&m_font);
}

/************************************************
part 7 自动补充文件类型 | 默认搜索*.txt | 默认指定目录 | 打开文件风格(文件存在/文件多选)
	1) CFileDialog dlg(TRUE, _T("txt"), _T("*.txt"));
	2) CFileDialog dlg(TRUE, _T("txt"), _T("C:\\"));
	3) CFileDialog dlg(TRUE, _T("txt"), NULL, OFN_FILEMUSTEXIST | OFN_ALLOWMULTISELECT);
	4) 多选要配合:
		OFN_ALLOWMULTISELECT
		GetStartPosition();
		GetNextPathName();
************************************************/
/************************************************
part 8 获取文件路径
	1) GetPathName();
************************************************/
/************************************************
part 9 文件打开过滤器
	1) LPCTSTR szFilter = _T("文本文件(*.txt)|*.txt|Chart Files (*.xlc)|*.xlc|Worksheet Files (*.xls)|*.xls|Data Files (*.xlc;*.xls)|*.xlc; *.xls|所有文件 (*.*)|*.*||");
	2) CFileDialog dlg(TRUE, _T("txt"), NULL, 0, szFilter);
************************************************/

void CNotepadDlg::OnFileOpen()
{
	LPCTSTR szFilter = _T("文本文件(*.txt)|*.txt|Chart Files (*.xlc)|*.xlc|Worksheet Files (*.xls)|*.xls|Data Files (*.xlc;*.xls)|*.xlc; *.xls|所有文件 (*.*)|*.*||");

	//CFileDialog dlg(TRUE);
	CFileDialog dlg(TRUE, _T("txt"), NULL, 0, szFilter);
	if (dlg.DoModal() == IDCANCEL)
		return;
	CString szFile = dlg.GetPathName();
	CFile file;
	LoadFile(szFile);
}
void CNotepadDlg::LoadFile(LPCTSTR sFile)
{

	TCHAR sData[4];
	CFile file;
	if (!file.Open(sFile, CFile::modeRead))
	{
		AfxMessageBox(_T("打开文件失败!"));
		return;
	}
	if (file.Read(sData, 2) == 2)
	{
		switch (sData[0])
		{
		case 0xbbef:
			ReadUTF8(file);
			return;
		case 0xfeff:
			ReadUTF16(file);
			return;
		}
	}
	ReadASCII(file);
}

void CNotepadDlg::OnFileNew()
{
	// TODO: 在此添加命令处理程序代码
}


void CNotepadDlg::OnFileSave()
{
	// TODO: 在此添加命令处理程序代码
}


void CNotepadDlg::OnFileSaveAs()
{
	// TODO: 在此添加命令处理程序代码
}



