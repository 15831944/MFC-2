
// TestWDlg.h : 头文件
//

#pragma once


// CTestWDlg 对话框
class CTestWDlg : public CDialogEx
{
// 构造
public:
	CTestWDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TESTW_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
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
