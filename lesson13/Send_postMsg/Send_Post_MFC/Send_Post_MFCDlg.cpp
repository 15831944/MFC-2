#include "stdafx.h"
#include "Send_Post_MFC.h"
#include "Send_Post_MFCDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

/*************************************************
	part 3 �Զ�����Ϣ
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
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CSend_Post_MFCDlg::OnPaint()
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

HCURSOR CSend_Post_MFCDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


/*************************************************
	part 1 һ��ֱ�ӷ�������,���ҵȴ�������
*************************************************/
/*************************************************
	part 5 �����ͬһ���߳���
		����ʹ��SendMessage,�������ܺܿ�õ���Ϣ���
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
	part 2 һ��ֱ�ӷ����ʾ�,�ʾ���֪ͨ
		 �����ż�,�������ҵ���
*************************************************/
/*************************************************
	part 6 ����ڲ�ͬ�߳���
		ʹ��PostMessage,�������Բ��������̶߳��������
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
	if(IDYES == MessageBox(_T("Ҫ������?\n"), _T("��ܰ����"), MB_YESNO))
		CDialogEx::OnClose();
}

/*************************************************
	part 4 �Զ�����Ϣ����
		����ͼ->�Ҽ���Ӧ������->����->��Ϣ->����Զ�����Ϣ
*************************************************/
afx_msg LRESULT CSend_Post_MFCDlg::OnUmAdd(WPARAM wParam, LPARAM lParam)
{
	Sleep(2000);
	CString str;
	str.Format(_T("%d"), wParam + lParam);
	MessageBox(str, _T("��ܰ����"), MB_YESNO);
	return 0;
}
