
// TestMegDlg.h : ͷ�ļ�
//

#pragma once


// CTestMegDlg �Ի���
class CTestMegDlg : public CDialogEx
{
// ����
public:
	CTestMegDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TESTMEG_DIALOG };
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
/*********************************************************
	part 1 DECLARE_MESSAGE_MAP()
		�궨��, �ȼ���:
		protected:
			static const AFX_MSGMAP* PASCAL GetThisMessageMap();
			virtual const AFX_MSGMAP* GetMessageMap() const;
*********************************************************/
	//DECLARE_MESSAGE_MAP()
protected: 
	static const AFX_MSGMAP* PASCAL GetThisMessageMap(); 
	virtual const AFX_MSGMAP* GetMessageMap() const; 
};
