
// lesson04-MFC������Dlg.h : ͷ�ļ�
//

#pragma once


// Clesson04MFC������Dlg �Ի���
class Clesson04MFC������Dlg : public CDialogEx
{
// ����
public:
	Clesson04MFC������Dlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_LESSON04MFC_DIALOG };
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
	afx_msg void OnBnClickedResult1();
	afx_msg void OnBnClickedResult2();
	afx_msg void OnBnClickedResult3();
	afx_msg void OnBnClickedResult4();
};
