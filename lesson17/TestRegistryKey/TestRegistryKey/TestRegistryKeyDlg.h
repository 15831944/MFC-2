
// TestRegistryKeyDlg.h : ͷ�ļ�
//

#pragma once


// CTestRegistryKeyDlg �Ի���
class CTestRegistryKeyDlg : public CDialogEx
{
// ����
public:
	CTestRegistryKeyDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TESTREGISTRYKEY_DIALOG };
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
	afx_msg void OnBnClickedButton1();
	void OnOK();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
public:
	COLORREF m_color;

};
