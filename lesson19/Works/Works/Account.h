#pragma once


// CAccount �Ի���

class CAccount : public CDialogEx
{
	DECLARE_DYNAMIC(CAccount)

public:
	CAccount(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CAccount();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ACCOUNT };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
};
