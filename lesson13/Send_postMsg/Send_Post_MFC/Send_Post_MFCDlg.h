
// Send_Post_MFCDlg.h : ͷ�ļ�
//

#pragma once


// CSend_Post_MFCDlg �Ի���
class CSend_Post_MFCDlg : public CDialogEx
{
// ����
public:
	CSend_Post_MFCDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SEND_POST_MFC_DIALOG };
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
	afx_msg void OnBnClickedSend();
	afx_msg void OnBnClickedPost();
	afx_msg void OnClose();
protected:
	afx_msg LRESULT OnUmAdd(WPARAM wParam, LPARAM lParam);
};
