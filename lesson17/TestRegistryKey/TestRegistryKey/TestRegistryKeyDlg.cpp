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
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CTestRegistryKeyDlg::OnPaint()
{
	if (IsIconic()){
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
	else{
		CDialogEx::OnPaint();
	}
}

HCURSOR CTestRegistryKeyDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


/*************************************************
part 1 ��ֹӦ��3��,���ֳ�Ӧ�ó�����æ
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
part 2 ����ѭ��(˳ʱ��)
	1) CWnd *p = GetFocus();
	2) 	int nID = p->GetDlgCtrlID();
		if (nID < IDC_EDIT1 || nID > IDC_EDIT4)
			GetDlgItem(IDC_EDIT1)->SetFocus();
		else
			this->DlgCtrl();
***************************************************/
/***************************************************
part 3 ����ѭ��(��ʱ��)
	1)  if (nID < IDC_EDIT1 || nID > IDC_EDIT4)
		GetDlgItem(IDC_EDIT1)->SetFocus();
		else
		this->DlgCtrl();
***************************************************/
/***************************************************
part 4 ������ת����
	1) GetDlgItem(IDC_EDIT1)->SetFocus();
	2) GotoDlgCtrl(GetDlgItem(IDC_EDIT1));
***************************************************/
/***************************************************
part 5 CDialog���õ��ຯ��
	a) DoModal: ����ģʽ�Ի���
	b) Create:	������ģʽ�Ի���
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
part 6 CDialog��������
	a) CColorDialog: Lets user select colors.
	b) CFileDialog:	 Lets user select a filename or replace to open to save.
	c) CFindReplaceDialog; Lets user initiate a find or replace operation in a text file
	d) CFontDialog: Lets user specity a font.
	e) CPrintDialog: Lets user sprcify information for a print job.
	f) CPrintDialogEx: Windows 2000 print property sheet.
***************************************************/
/**************************************************
part 7 ��ȡ�ڼ�λ����
	1)  #define LOBYTE(w)           ((BYTE)(((DWORD_PTR)(w)) & 0xff))
		#define GetRValue(rgb)      (LOBYTE(rgb))
		#define GetGValue(rgb)      (LOBYTE(((WORD)(rgb)) >> 8))
		#define GetBValue(rgb)      (LOBYTE((rgb)>>16))
**************************************************/
/**************************************************
part 8 TRACE(��̨���)
	1) ͷ�ļ�: afx.h
**************************************************/
/**************************************************
part 9 ���ñ�����ɫ
	1) SetBackgroundColor(color);
**************************************************/
/**************************************************
part 11 ���õ�ɫ��Ϊ��������
	1) CColorDialog cdlg(0, 0, GetDesktopWindow());
**************************************************/
/**************************************************
part 12 ���õ�ɫ�������ϴ�ѡ��
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
part 10 ���ñ���ͼƬ
	1) SetBackgroundImage(IDB_BITMAP);
	2)  BACKGR_TILE��
		BACKGR_TOPLEFT��
		BACKGR_TOPRIGHT��
		BACKGR_BOTTOMLEFT��BACKGR_BOTTOMRIGHT�� Ĭ��ֵΪBACKGR_TILE��
**************************************************/
void CTestRegistryKeyDlg::OnBnClickedButton3()
{
	//SetBackgroundImage(IDB_BITMAP);
	SetBackgroundImage(IDB_BITMAP, BACKGR_BOTTOMLEFT);
}
