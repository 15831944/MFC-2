#pragma once


// ABOUT �Ի���

class ABOUT : public CDialogEx
{
	DECLARE_DYNAMIC(ABOUT)

public:
	ABOUT(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~ABOUT();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUT };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
