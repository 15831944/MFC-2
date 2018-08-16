#pragma once


// CAccount 对话框

class CAccount : public CDialogEx
{
	DECLARE_DYNAMIC(CAccount)

public:
	CAccount(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CAccount();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ACCOUNT };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
};
