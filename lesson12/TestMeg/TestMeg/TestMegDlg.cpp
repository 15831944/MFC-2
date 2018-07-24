#include "stdafx.h"
#include "TestMeg.h"
#include "TestMegDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

CTestMegDlg::CTestMegDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_TESTMEG_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTestMegDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}
/*********************************************************************
	part 2 �궨�����Ϣ����
		BEGIN_MESSAGE_MAP(CTestMegDlg, CDialogEx)
			ON_WM_PAINT()
			ON_WM_QUERYDRAGICON()
		END_MESSAGE_MAP()
*********************************************************************/
/*********************************************************************
	part 2.1 ��Ϣ�����ú�����ʾ
	PTM_WARNING_DISABLE
	const AFX_MSGMAP* CTestMegDlg::GetMessageMap() const
	{
		return GetThisMessageMap();
	}
		const AFX_MSGMAP* PASCAL CTestMegDlg::GetThisMessageMap()
	{
	typedef CTestMegDlg ThisClass;
	typedef CDialogEx TheBaseClass;
	static const AFX_MSGMAP_ENTRY _messageEntries[] = {
		{WM_PAINT, 0, 0, 0, AfxSig_vv, (AFX_PMSG)(AFX_PMSGW) (static_cast< void (AFX_MSG_CALL CWnd::*)(void) > (&ThisClass::OnPaint))},
		{WM_QUERYDRAGICON, 0, 0, 0, AfxSig_hv, (AFX_PMSG)(AFX_PMSGW) (static_cast< HCURSOR(AFX_MSG_CALL CWnd::*)(void) > (&ThisClass::OnQueryDragIcon)) },
		{
		0, 0, 0, 0, AfxSig_end, (AFX_PMSG)0
		}
	};
	static const AFX_MSGMAP messageMap = {&TheBaseClass::GetThisMessageMap, &_messageEntries[0]
	};
		return &messageMap;
	}
	PTM_WARNING_RESTORE
*********************************************************************/
PTM_WARNING_DISABLE 
const AFX_MSGMAP* CTestMegDlg::GetMessageMap() const 
{
	return GetThisMessageMap(); 
} 
const AFX_MSGMAP* PASCAL CTestMegDlg::GetThisMessageMap() 
{ 
	typedef CTestMegDlg ThisClass;						   
	typedef CDialogEx TheBaseClass;					   
	static const AFX_MSGMAP_ENTRY _messageEntries[] = {	
		{WM_PAINT, 0, 0, 0, AfxSig_vv, (AFX_PMSG)(AFX_PMSGW) (static_cast< void (AFX_MSG_CALL CWnd::*)(void) > (&ThisClass::OnPaint))},	
		{WM_QUERYDRAGICON, 0, 0, 0, AfxSig_hv, (AFX_PMSG)(AFX_PMSGW) (static_cast< HCURSOR(AFX_MSG_CALL CWnd::*)(void) > (&ThisClass::OnQueryDragIcon)) },
		{
			0, 0, 0, 0, AfxSig_end, (AFX_PMSG)0
		} 
	}; 
	static const AFX_MSGMAP messageMap = { &TheBaseClass::GetThisMessageMap, &_messageEntries[0] 
	}; 
	return &messageMap; 
}								  
PTM_WARNING_RESTORE

BOOL CTestMegDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CTestMegDlg::OnPaint()
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
HCURSOR CTestMegDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

