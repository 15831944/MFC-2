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
	part 2 OnInitDialog��ʼ�����ӿؼ�

*********************************************************/
BOOL CTestMsgDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	CListCtrl* pList = (CListCtrl*)GetDlgItem(IDC_LIST);

	pList->InsertColumn(0, _T("����"), LVCFMT_LEFT, 100);
	pList->InsertColumn(1, _T("����"), LVCFMT_LEFT, 150);
	pList->InsertColumn(2, _T("����"), LVCFMT_LEFT, 150);
	pList->InsertColumn(3, _T("��ְ����"), LVCFMT_LEFT, 246);

	pList->SetBkColor(RGB(205, 226, 252));
	pList->SetTextBkColor(RGB(205, 226, 252));
	pList->SetTextColor(RGB(0, 0, 255));




	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CTestMsgDlg::OnPaint()
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

HCURSOR CTestMsgDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

/*********************************************************
	part 0 WM_CREATE, WM_INITDLALOG�Ա�

*********************************************************/
/*********************************************************
	part 1 WM_CREATE��WM_INITDLALOG����ִ��
		����������ռ仹û��������
		ʧ��:
			pList->InsertColumn(0, _T("����"), 0, 100);
*********************************************************/
/*********************************************************
	part 3 �Ը����ڽ��в�����û�����
		���ڸ����Ѿ�������
		�ɹ�:
			SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
			SetIcon(m_hIcon, FALSE);		// ����Сͼ��
*********************************************************/
int CTestMsgDlg::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CDialogEx::OnCreate(lpCreateStruct) == -1)
		return -1;

	//CListCtrl* pList = (CListCtrl*)GetDlgItem(IDC_LIST);
	//pList->InsertColumn(0, _T("����"), 0, 100);

	//SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	//SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	return 0;
}

/*********************************************************
	part 4 PreSubclassWindow�� WM_CREATE�� WM_INITDLALOG����ִ��
		�������Ѿ���������
		�ɹ�:
			SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
			SetIcon(m_hIcon, FALSE);		// ����Сͼ��
*********************************************************/
void CTestMsgDlg::PreSubclassWindow()
{
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	CDialogEx::PreSubclassWindow();
}

/*********************************************************
	part 5 ϵͳ�رչ���: WM_SYSCOMMAND->WM_CLOSE->OnCancel->WM_DESTROY
		���������е�WM_DESTORYʱ��,���������Ĺر���
		1) WM_SYSCOMMAND:�Ƕ�����ϵͳ�˵��е��������(����: ���/С��, �ƶ�, �ر�...(F1��ȥ��))
*********************************************************/
void CTestMsgDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	//if (nID == SC_CLOSE)
	//{
	//	ShowWindow(SW_MINIMIZE);
	//	return;
	//}
	CDialogEx::OnSysCommand(nID, lParam);//ִ��ȱʡ����,�൱��,��ʲôҲû��,�����Ҵ���

}


void CTestMsgDlg::OnClose()
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ

	CDialogEx::OnClose();
}


/*********************************************************
	part 6 ���йرչ���: OnCancel->WM_DESTROY

*********************************************************/
void CTestMsgDlg::OnCancel()
{
	CDialogEx::OnCancel();
}

/*********************************************************
	part 7 ���ںͿؼ��Ļ�����
		CDialogEx::OnDestroy();
*********************************************************/
void CTestMsgDlg::OnDestroy()
{


	CDialogEx::OnDestroy();

	// TODO: �ڴ˴������Ϣ����������
}


