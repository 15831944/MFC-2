
// TestWDlg.h : ͷ�ļ�
//

#pragma once


// CTestWDlg �Ի���
class CTestWDlg : public CDialogEx
{
// ����
public:
	CTestWDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TESTW_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedAnimate();
	afx_msg void OnShowWindow(BOOL bShow, UINT nStatus);
	afx_msg void OnClose();
	afx_msg void OnBnClickedDestroy();
	afx_msg void OnBnClickedCreate();
	afx_msg void OnBnClickedGetsafe();
	afx_msg void OnBnClickedFromhandle();
};
