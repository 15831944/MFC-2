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
part 1 ���ڻ�����ʾ
	1)	AnimateWindow(500, AW_VER_NEGATIVE);
**********************************************************/
BOOL CTestWDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	//AnimateWindow(500, AW_VER_NEGATIVE);
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}


void CTestWDlg::OnPaint()
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

HCURSOR CTestWDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CTestWDlg::OnBnClickedAnimate()
{
	AnimateWindow(200, IDC_ANIMATE);
}

/**********************************************************
part 2 ���ڻ�����ʾ(�ڳ�ʼ����ʾ���ڲ�����,��showWindow)
	1)	AnimateWindow(500, AW_VER_NEGATIVE);
**********************************************************/
void CTestWDlg::OnShowWindow(BOOL bShow, UINT nStatus)
{
	CDialogEx::OnShowWindow(bShow, nStatus);

	AnimateWindow(500, AW_VER_NEGATIVE);
}


void CTestWDlg::OnClose()
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	AnimateWindow(500, AW_VER_NEGATIVE);
	CDialogEx::OnClose();
	
}

/**********************************************************
part 3 �ݻٴ��ھ��
	1)	DestroyWindow();
	//EndDialog(-1);�ݻ�Ҳ�Ǵ���,��û��ָ���ÿ�
	//�ݻٴ��ھ��
	//this->DestroyWindow();
	//�ݻ�OK��Ϣ���
	//GetDlgItem(IDOK)->DestroyWindow();
**********************************************************/

void CTestWDlg::OnBnClickedDestroy()
{
	//CWnd* pWnd = FindWindow(_T("Notepad"), NULL);
	//pWnd->DestroyWindow();
	GetDlgItem(IDOK)->DestroyWindow();
}

/**********************************************************
part 3 �������ھ��
	1)	Create(_T("ButtON"), _T("ȷ��"), WS_CHILD | WS_VISIBLE, CRect(0, 0, 60, 30), this, IDOK);
	2)	��һ������: ������
	3) 	CWnd *edit = new CWnd;
		edit->Create(_T("Edit"), _T("ȷ��"), WS_CHILD | WS_VISIBLE,
		CRect(400, 280, 500, 305), this, IDOK);
**********************************************************/
/**********************************************************
part 4 ��ȡ��ǰ����
	1)	CFont* pFont = GetFont();
	2)	��������ok->SetFont(pFont);
**********************************************************/
/**********************************************************
part 5 �û��ഴ������ķ���: CWnd
	1) 	CWnd *ok = new CWnd;
		ok->Create(_T("ButtON"), _T("ȷ��"), WS_CHILD | WS_VISIBLE,
			CRect(400, 280, 500, 305), this, IDOK);
		CFont* pFont = GetFont();
		ok->SetFont(pFont);
**********************************************************/
/**********************************************************
part 6 ���ഴ�����ڵķ���: CEdit
	1)	CEdit *edit = new CEdit;
		edit->Create(WS_CHILD | WS_VISIBLE | WS_BORDER | ES_MULTILINE | ES_WANTRETURN, CRect(400, 111, 500, 280), this, 8888);
		CFont* pFont = GetFont();
		edit->SetFont(pFont);
**********************************************************/
/**********************************************************
part 7 �����б���: CListCtrl

void CTestWDlg::OnBnClickedCreate()
{
	CListCtrl *pList = new CListCtrl;
	pList->Create(WS_CHILD | WS_VISIBLE | LVS_REPORT, CRect(10, 111, 500, 280), this, 8888);
	CFont* pFont = GetFont();
	pList->SetFont(pFont);

	pList->InsertColumn(0, _T("����"), 0, 100);
	pList->InsertColumn(1, _T("����"), 0, 100);
	pList->InsertColumn(2, _T("����"), 0, 100);
	pList->InsertColumn(3, _T("��ְ����"), 0, 100);

}
**********************************************************/

/**********************************************************
part 8	���ഴ���б�ؼ�(û�����ݷ��)

void CTestWDlg::OnBnClickedCreate()
{
	CWnd *pCList = new CWnd;
	pCList->Create(_T("syslistview32"), NULL, WS_CHILD | WS_VISIBLE | LVS_REPORT, CRect(10, 111, 500, 280), this, 8888);
	CListCtrl* pList = (CListCtrl*)GetDlgItem(8888);
	pList->InsertColumn(0, _T("����"), 0, 100);
	pList->InsertColumn(1, _T("����"), 0, 100);
	pList->InsertColumn(2, _T("����"), 0, 100);
	pList->InsertColumn(3, _T("��ְ����"), 0, 100);

	CFont* pFont = GetFont();
	pList->SetFont(pFont);
}
**********************************************************/
/**********************************************************
part 9	��չ���ഴ���б�ؼ�(��չ���б���): CreateEX

void CTestWDlg::OnBnClickedCreate()
{
	CWnd *pCList = new CWnd;
	pCList->CreateEx(WS_EX_CLIENTEDGE, _T("syslistview32"), NULL, WS_CHILD | WS_VISIBLE | LVS_REPORT, CRect(10, 111, 500, 280), this, 8888);
	CListCtrl* pList = (CListCtrl*)GetDlgItem(8888);
	pList->InsertColumn(0, _T("����"), 0, 100);
	pList->InsertColumn(1, _T("����"), 0, 100);
	pList->InsertColumn(2, _T("����"), 0, 100);
	pList->InsertColumn(3, _T("��ְ����"), 0, 100);

	CFont* pFont = GetFont();
	pList->SetFont(pFont);
}
**********************************************************/
/**********************************************************
part 10 ���ഴ����ť
**********************************************************/
CWnd m_ok;
void CTestWDlg::OnBnClickedCreate()
{
	//����:��ť��ʼ�����ٳ�ʼ
	if (!m_ok.m_hWnd)
	{
		m_ok.Create(_T("Button"), _T("ȷ��"), WS_CHILD | WS_VISIBLE | BS_AUTORADIOBUTTON | WS_TABSTOP
			, CRect(10, 50, 155, 69), this, 10088);
		CFont* pFont = GetFont();
		m_ok.SetFont(pFont);
	}
}

/**********************************************************
part 11 �Ӷ����ȡ���
	��ȫ��Hwnd: GetSafeHwnd()
	1)	GetDlgItem(IDOK)->DestroyWindow();	
		HWND hWnd = pWnd->m_hWnd;	//���m_hWnd���ͷ���
		����ͻᱼ��

	2)	HWND hWnd = pWnd->GetSafeHwnd();
**********************************************************/
void CTestWDlg::OnBnClickedGetsafe()
{
	CWnd* pWnd = GetDlgItem(IDOK);
	HWND hWnd = pWnd->GetSafeHwnd();
}

/**********************************************************
part 12	�Ӿ����ö���
**********************************************************/
void CTestWDlg::OnBnClickedFromhandle()
{
	HWND hWnd = ::GetDlgItem(m_hWnd, IDOK);
	CWnd* pOk = CWnd::FromHandle(hWnd);
	pOk->SetWindowText(_T("OK"));
}