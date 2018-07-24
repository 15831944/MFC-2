
// TestMegDlg.h : 头文件
//

#pragma once


// CTestMegDlg 对话框
class CTestMegDlg : public CDialogEx
{
// 构造
public:
	CTestMegDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TESTMEG_DIALOG };
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
/*********************************************************
	part 1 DECLARE_MESSAGE_MAP()
		宏定义, 等价于:
		protected:
			static const AFX_MSGMAP* PASCAL GetThisMessageMap();
			virtual const AFX_MSGMAP* GetMessageMap() const;
*********************************************************/
	//DECLARE_MESSAGE_MAP()
protected: 
	static const AFX_MSGMAP* PASCAL GetThisMessageMap(); 
	virtual const AFX_MSGMAP* GetMessageMap() const; 
};
