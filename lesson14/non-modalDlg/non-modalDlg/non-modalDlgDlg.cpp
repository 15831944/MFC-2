#include "stdafx.h"
#include "non-modalDlg.h"
#include "non-modalDlgDlg.h"
#include "afxdialogex.h"

#include "ABOUT.h"
#include "MessageDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

/*********************************************************
	part 5 AfxGetApp()
	1) AfxGetApp()ָ�� ȫ�ֱ��� theApp;

CnonmodalDlgDlg::CnonmodalDlgDlg(CWnd* pParent)
	: CDialogEx(IDD_NONMODALDLG_DIALOG, pParent)
{
	CWinApp *p = AfxGetApp();
	m_hIcon = p->LoadIcon(IDR_MAINFRAME);
}
*********************************************************/

/*********************************************************
	part 6 ��ȡ��Դ�ܹ�(ָ�����Ŵ�����������Ϣ)
	1) HINSTANCE hInst = AfxGetIntanceHandle();
	2) HINSTANCE hInst = AfxGetApp()->m_hInstance;
	2) HINSTANCE hInst = theApp.m_hInstance;
*********************************************************/
CnonmodalDlgDlg::CnonmodalDlgDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_NONMODALDLG_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);

}
void CnonmodalDlgDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CnonmodalDlgDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CnonmodalDlgDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CnonmodalDlgDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CnonmodalDlgDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CnonmodalDlgDlg::OnBnClickedButton4)
END_MESSAGE_MAP()

BOOL CnonmodalDlgDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CnonmodalDlgDlg::OnPaint()
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

HCURSOR CnonmodalDlgDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


/*********************************************************
	part 1 ģʽ�Ի���
	1) �ö���.DoModal()����
	2) ���ó����Ĵ����Ǳ�����ɵ�,��Ȼ������
*********************************************************/
void CnonmodalDlgDlg::OnBnClickedButton1()
{
	ABOUT about;
	about.DoModal();
}

/*********************************************************
	part 2 ��ģʽ�Ի���
	1) �ö���.DoModal()����
	2) ���ó����Ĵ����Ǳ�����ɵ�,��Ȼ������
*********************************************************/
/*********************************************************
	part 3 ��ģʽ�Ի���
	1) �����ڶ���NEW����,��Ȼ��ջ�гɾֲ�����,һ�������ͱ�������

void CnonmodalDlgDlg::OnBnClickedButton2()
{
	MessageDlg *pDlg = new MessageDlg();
	pDlg->Create(IDD_MSGDLG);
	pDlg->ShowWindow(SW_SHOWNA);
}
*********************************************************/


/*********************************************************
	part 4 ��ģʽ�Ի��� & �����Ի���
	1) ��������һ��,�������������Լ���ͼ��
		pDlg->Create(IDD_MSGDLG, GetDesktopWindow());
*********************************************************/
void CnonmodalDlgDlg::OnBnClickedButton2()
{
	MessageDlg *pDlg = new MessageDlg();
	pDlg->Create(IDD_MSGDLG, GetDesktopWindow());
	pDlg->ShowWindow(SW_SHOWNA);
}

/*********************************************************
	part 7 ��ȡ������
	1) CString str = AfxGetAppName();
	2) CString str = theApp.m_pszAppName;
*********************************************************/
void CnonmodalDlgDlg::OnBnClickedButton3()
{
	CWinApp *p = AfxGetApp();
	CString str = theApp.m_pszAppName;
	AfxMessageBox(str);
}

/*********************************************************
	part 8 ��ȡ�������ַ
	1) 
*********************************************************/
void CnonmodalDlgDlg::OnBnClickedButton4()
{
	CString str;
	str.Format(_T("this: %x"), this);
	AfxMessageBox(str);

	CWnd *p1 = theApp.m_pMainWnd;
	str.Format(_T("theApp.m_pMainWnd: %x"), p1); 
	AfxMessageBox(str);

	CWnd *p2 = AfxGetMainWnd();
	str.Format(_T("theApp.m_pMainWnd: %x"), p2);
	AfxMessageBox(str);
}
