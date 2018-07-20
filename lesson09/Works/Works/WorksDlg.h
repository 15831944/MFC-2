
// WorksDlg.h : 头文件
//

#pragma once


// CWorksDlg 对话框
class CWorksDlg : public CDialogEx
{
	struct SInfo
	{
		int nNumb;
		TCHAR sName[20];
		float fSala;
		//CTime tData;
		COleDateTime tData;
	};
// 构造
public:
	CWorksDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_WORKS_DIALOG };
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
	afx_msg void OnBnClickedWorkLookup();
	afx_msg void OnBnClickedWorkAdd();
	afx_msg void OnBnClickedWorkDele();
	afx_msg void OnBnClickedWorkModify();
	afx_msg void OnBnClickedWorkSave();
	// 检查号码是否存在
	BOOL CheckNumber(LPCTSTR str);
	// 文件错误集
	void FileError(int error);

public:
	afx_msg void OnBnClickedCancel();
private:
	int m_Row;
	BOOL m_bModify;
};
