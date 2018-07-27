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

	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	m_hAccel = ::LoadAccelerators(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDR_MAIN));
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CNotepadDlg::OnPaint()
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

HCURSOR CNotepadDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CNotepadDlg::OnOK()
{
	//CDialogEx::OnOK();
}

/***************************************************************
	part 3 ��Ҫ��Cancel��Ϣ,,��Esc���ܳ���
***************************************************************/
void CNotepadDlg::OnCancel()
{
	//CDialogEx::OnCancel();
}
/***************************************************************
	part 4 �����ϵͳ�ر�
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
	part 1 ץ���ļ�����������(���ĵ���ȡ)
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
	part 2 ץ���ļ�����������(ֻ����һ��)
	TCHAR sFile[256];
	int nCount = DragQueryFile(hDropInfo, 0, sFile, _countof(sFile));
***************************************************************/
/***************************************************************
	part 10 Windows���±��ļ����ַ������:
		1) ANSI: 
		2) Unicode: 0x5C 0x75 0x46 0x45 0x46 0x46: �ļ���ͷ. 
					���ַ�,��������,����,���Ŷ�ռ�����ֽ�,���ظ�
		3) UTF-8: 0xEF 0xBB 0xBF: �ļ���ͷ. 
					���ֽ��ַ��ı�, ���Ҹ�������ͳһ���ظ�
		4) UTF-16: 0xFF 0xFE: �ļ���ͷ
***************************************************************/
/***************************************************************
	part 11 file.Read(Conten, _countof(Conten))Խ����
		��read����_countof(Conten)ʱ,��-1��Խ����
			file.Read(Conten, _countof(Conten) - 1)

void CNotepadDlg::OnDropFiles(HDROP hDropInfo)
{
	TCHAR sFile[256];
	TCHAR Conten[4096] = { 0 };
	int nCount = DragQueryFile(hDropInfo, 0, sFile, _countof(sFile));
	CFile file;
	if (!file.Open(sFile, CFile::modeRead))
	{
		AfxMessageBox(_T("�ļ�������!\n"));
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
		//��ȡת��Ϊ���ֽں���Ҫ�Ļ�������С���������ֽڻ�����
		UINT nLen = MultiByteToWideChar(CP_UTF8, NULL, strUTF8, -1, NULL, NULL);
		WCHAR *wszBuffer = new WCHAR[nLen + 1];
		nLen = MultiByteToWideChar(CP_UTF8, NULL, strUTF8, -1, wszBuffer, nLen);
		wszBuffer[nLen] = 0;

		nLen = WideCharToMultiByte(936, NULL, wszBuffer, -1, NULL, NULL, NULL, NULL);
		CHAR *szBuffer = new CHAR[nLen + 1];
		nLen = WideCharToMultiByte(936, NULL, wszBuffer, -1, szBuffer, nLen, NULL, NULL);
		szBuffer[nLen] = 0;
		strUTF8 = szBuffer;
		//�����ڴ�
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
***************************************************************/
void UTF8toANSI(LPSTR buf)
{
	//��ȡת��Ϊ���ֽں���Ҫ�Ļ�������С���������ֽڻ�����
	UINT nLen = MultiByteToWideChar(CP_UTF8, NULL, buf, -1, NULL, NULL);
	WCHAR *wszBuffer = new WCHAR[nLen + 1];
	nLen = MultiByteToWideChar(CP_UTF8, NULL, buf, -1, wszBuffer, nLen);
	wszBuffer[nLen] = 0;

	nLen = WideCharToMultiByte(936, NULL, wszBuffer, -1, NULL, NULL, NULL, NULL);
	CHAR *szBuffer = new CHAR[nLen + 1];
	nLen = WideCharToMultiByte(936, NULL, wszBuffer, -1, szBuffer, nLen, NULL, NULL);
	szBuffer[nLen] = 0;
	buf = szBuffer;
	//�����ڴ�
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
/***************************************************************
	part 12 �ļ���ȡλ���趨
		file.Seek(3, CFile::begin);//�ӵ������ֽڶ�ȡ
***************************************************************/
/***************************************************************
	part 13 ACSIIתUTF8
		MultiByteToWideChar(CP_UTF8, NULL, buf, -1, sText, _countof(sText))

void CNotepadDlg::ReadUTF8(CFile& file)
{
	file.Seek(3, CFile::begin);
	char buf[1024];
	TCHAR sText[513];
	UINT nRet = 0;
	CString str;
	while (nRet = file.Read(buf, sizeof(buf) - 1))
	{
		buf[nRet] = '\0';
		UINT nLen = MultiByteToWideChar(CP_UTF8, NULL, buf, -1, sText, _countof(sText));
		str += sText;
	}
	SetDlgItemText(IDC_TEXT, str);
}
***************************************************************/
/***************************************************************
	part 14 �ϱ�һ��һ�εĶ�ȡ�ı�,
		�м��жϿ�,���п�����һ���ֽ�(�ı�����˫�ֽ�)�Ĵ���ȥ,
		ʹ�����ı�����λ�ô�
***************************************************************/
/***************************************************************
	part 15 ���ı����ݵĳ���
		LONGLONG nRet = file.GetLength();
		NEW һ�����ݳ��ȵĿռ�,����һ���Դ��,�ų��ֽڴ��ĵķ���
***************************************************************/
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
/***************************************************************
	part 16 UTF16����Ҫת��,��Ϊ��ǰ����UTF16(���Unicode)
		
***************************************************************/
/***************************************************************
	part 17 ע��file.GetLength();����
		GetLength()���ص����ֽڳ���
		Unicode��˫�ֽڵ�, new TCHAR[nRet / 2];
		β��˫�ֽڵĿռ�pText[nRet / 2] = '\0';

***************************************************************/
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
	CFile file;
	if (!file.Open(sFile, CFile::modeRead))
	{
		AfxMessageBox(_T("���ļ�ʧ��!"));
		return;
	}
	if (file.Read(sFile, 2) == 2)
	{
		switch (sFile[0])
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

void CNotepadDlg::OnAppAbout()
{
	CAboutDlg dlg;
	dlg.DoModal();
}

/***************************************************************
	part 7 ���ڿ��������Ŵ���С
		�ض���OnSize����:
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
	part 5 ��ȡ����ָ��,�л��ຯ���ɵ���
		CWnd* pEdit = GetDlgItem(IDC_TEXT);
***********************************************************/
/***********************************************************
	part 6 ��ȡ����ָ��,�����ຯ���ɵ���
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
	part 8 Edit Control���λ�ò����ַ���
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
	// TODO: �ڴ���������������
}


void CNotepadDlg::OnEditGo()
{
	// TODO: �ڴ���������������
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
	part 9 ��ݼ�����
		1) ����Դ��ͼ�������Դ��ѡ��"Accelerator"
		2) �༭���а���ID�����η�����
		3) ͷ�ļ�����ӿ�ݼ�����: HACCEL m_hAccel
		4) OnInitDialog������ʼ��:
			m_hAccel = ::LoadAccelerators(AfxGetInstanceHandle(), MAKEINTRESOURCE(Accelerator��ID));
		5)	��д���´���: 
***********************************************************/
BOOL CNotepadDlg::PreTranslateMessage(MSG* pMsg)
{
	int iResult;
	switch (pMsg->message)
	{
	case WM_KEYDOWN:
	case WM_SYSKEYDOWN:
		iResult = TranslateAccelerator(m_hWnd, m_hAccel, pMsg);//������ټ����ú�������˵������еļ��ټ���
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


