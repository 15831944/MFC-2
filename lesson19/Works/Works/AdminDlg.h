#pragma once





class CAdminDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CAdminDlg)

public:
	CAdminDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CAdminDlg();

#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PRIRO_DLG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedWorkAdd();
	afx_msg void OnBnClickedWorkDele();
	afx_msg void OnBnClickedWorkModify();
	virtual BOOL OnInitDialog();
	BOOL Check(CString str);
//	afx_msg void OnDestroy();
	virtual void OnCancel();
	void SaveFile();
	void LoadFile();

public:
	BOOL m_bModify;
};
